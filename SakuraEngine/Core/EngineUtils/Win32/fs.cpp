#ifdef _WIN32
#pragma once
#include "../fs.h"
#define WIN32_LEAN_AND_MEAN
#pragma warning (disable:4800)
#include <Windows.h>
using namespace Sakura;
namespace Sakura::fs
{
	bool exists(const char* path)
	{
		return GetFileAttributesA(path) != INVALID_FILE_ATTRIBUTES;
	}

	bool isdir(const char* path)
	{
		DWORD x = GetFileAttributesA(path);
		return x != INVALID_FILE_ATTRIBUTES && (x & FILE_ATTRIBUTE_DIRECTORY);
	}

	int64 mtime(const char* path)
	{
		WIN32_FILE_ATTRIBUTE_DATA info;
		BOOL r = GetFileAttributesExA(path, GetFileExInfoStandard, &info);
		if (!r)
			return -1;
		FILETIME& wt = info.ftLastWriteTime;
		return ((int64)wt.dwHighDateTime << 32) | wt.dwLowDateTime;
	}

    int64 fsize(const char* path) {
        WIN32_FILE_ATTRIBUTE_DATA info;
        BOOL r = GetFileAttributesExA(path, GetFileExInfoStandard, &info);
        if (!r) return -1;
        return ((int64)info.nFileSizeHigh << 32) | info.nFileSizeLow;
    }

    // p = false  ->  mkdir
    // p = true   ->  mkdir -p
    bool mkdir(const char* path, bool p) {
        if (!p) return CreateDirectoryA(path, 0);

        const char* s = strrchr(path, '/');
        if (s == 0) s = strrchr(path, '\\');
        if (s == 0) return CreateDirectoryA(path, 0);

        pmr::string parent(path, s - path);

        if (fs::exists(parent.c_str())) {
            return CreateDirectoryA(path, 0);
        }
        else {
            return fs::mkdir(parent.c_str(), true) && CreateDirectoryA(path, 0);
        }
    }

    // rf = false  ->  rm or rmdir
    // rf = true   ->  rm -rf
    bool remove(const char* path, bool rf) {
        if (!fs::exists(path)) return true;

        if (!rf) {
            if (fs::isdir(path)) return RemoveDirectoryA(path);
            return DeleteFileA(path);
        }
        else {
            pmr::string cmd;
            cmd.append("rd /s /q \"").append(pmr::string(path));
            cmd += '"';
            return system(cmd.c_str()) != -1;
        }
    }

    bool rename(const char* from, const char* to) {
        return MoveFileA(from, to);
    }

    bool symlink(const char* dst, const char* lnk) {
        fs::remove(lnk);
        return CreateSymbolicLinkA(lnk, dst, fs::isdir(dst));
    }

#define nullfd INVALID_HANDLE_VALUE

    namespace xx {
        HANDLE open(const char* path, char mode) {
            if (mode == 'r') {
                return CreateFileA(path, GENERIC_READ, 7, 0, OPEN_EXISTING, 0, 0);
            }
            else if (mode == 'a') {
                return CreateFileA(path, FILE_APPEND_DATA, 7, 0, OPEN_ALWAYS, 0, 0);
            }
            else if (mode == 'w') {
                return CreateFileA(path, GENERIC_WRITE, 7, 0, CREATE_ALWAYS, 0, 0);
            }
            else if (mode == 'm') {
                return CreateFileA(path, GENERIC_WRITE, 7, 0, OPEN_ALWAYS, 0, 0);
            }
            else {
                return nullfd;
            }
        }
    } // xx

    struct fctx {
        HANDLE fd;
        pmr::string path;
    };

    file::~file() {
        if (!_p) return;
        this->close();
        delete (fctx*)_p;
        _p = 0;
    }

    file::operator bool() const {
        fctx* p = (fctx*)_p;
        return p && p->fd != nullfd;
    }

    const pmr::string& file::path() const {
        fctx* p = (fctx*)_p;
        return p->path;
    }

    bool file::open(const char* path, char mode) {
        this->close();
        fctx* p = (fctx*)_p;
        if (!p) _p = p = new fctx;
        p->path = path;
        return (p->fd = xx::open(path, mode)) != nullfd;
    }

    void file::close() {
        fctx* p = (fctx*)_p;
        if (!p || p->fd == nullfd) return;
        CloseHandle(p->fd);
        p->fd = nullfd;
    }

    void file::seek(int64 off, int whence) {
        static int seekfrom[3] = { FILE_BEGIN, FILE_CURRENT, FILE_END };
        whence = seekfrom[whence];

        if (off < (1LL << 31)) {
            SetFilePointer(((fctx*)_p)->fd, (LONG)off, 0, whence);
        }
        else {
            LARGE_INTEGER li;
            li.QuadPart = off;
            SetFilePointer(((fctx*)_p)->fd, li.LowPart, &li.HighPart, whence);
        }
    }

    size_t file::read(void* s, size_t n)
    {
        DWORD r = 0;
        ReadFile(((fctx*)_p)->fd, s, (DWORD)n, &r, 0);
        return r;
    }

    pmr::string file::read(size_t n)
    {
        pmr::string s;
        s.resize(n);
        this->read((void*)s.data(), n);
        return s;
    }

    size_t file::write(const void* s, size_t n) {
        DWORD r = 0;
        WriteFile(((fctx*)_p)->fd, s, (DWORD)n, &r, 0);
        return r;
    }

#undef nullfd
}
#endif