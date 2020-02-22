//A header file genereate by Sakura J2H tool
//Contains the infomation of a module of Sakura Engine
//With the MIT License Copyright!
#pragma once
#include <tuple>
#include <cstddef>

inline static const char sp_meta[] = {
0x7b, 0xa, 0x20, 0x20, 0x20, 0x20, 0x22, 0x61, 0x70, 0x69, 0x22, 0x20, 
0x3a, 0x20, 0x22, 0x30, 0x2e, 0x31, 0x2e, 0x30, 0x22, 0x2c, 0xa, 0x20, 
0x20, 0x20, 0x20, 0x22, 0x6e, 0x61, 0x6d, 0x65, 0x22, 0x20, 0x3a, 0x20, 
0x22, 0x70, 0x6c, 0x75, 0x67, 0x69, 0x6e, 0x5f, 0x30, 0x22, 0x2c, 0xa, 
0x20, 0x20, 0x20, 0x20, 0x22, 0x70, 0x72, 0x65, 0x74, 0x74, 0x79, 0x4e, 
0x61, 0x6d, 0x65, 0x22, 0x20, 0x3a, 0x20, 0x22, 0x50, 0x6c, 0x75, 0x67, 
0x69, 0x6e, 0x20, 0x30, 0x22, 0x2c, 0xa, 0x20, 0x20, 0x20, 0x20, 0x22, 
0x76, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x22, 0x20, 0x3a, 0x20, 0x22, 
0x31, 0x2e, 0x30, 0x2e, 0x30, 0x22, 0x2c, 0xa, 0x20, 0x20, 0x20, 0x20, 
0x22, 0x61, 0x75, 0x74, 0x68, 0x6f, 0x72, 0x22, 0x20, 0x3a, 0x20, 0x22, 
0x22, 0x2c, 0xa, 0x20, 0x20, 0x20, 0x20, 0x22, 0x75, 0x72, 0x6c, 0x22, 
0x20, 0x3a, 0x20, 0x22, 0x22, 0x2c, 0xa, 0x20, 0x20, 0x20, 0x20, 0x22, 
0x6c, 0x69, 0x63, 0x65, 0x6e, 0x73, 0x65, 0x22, 0x20, 0x3a, 0x20, 0x22, 
0x22, 0x2c, 0xa, 0x20, 0x20, 0x20, 0x20, 0x22, 0x63, 0x6f, 0x70, 0x79, 
0x72, 0x69, 0x67, 0x68, 0x74, 0x22, 0x20, 0x3a, 0x20, 0x22, 0x22, 0xa, 
0x7d, 0xa
};

inline static const std::size_t sp_meta_size = 182;

inline static std::size_t __GetMetaSize(void)
{
    return sp_meta_size;
}
inline static const char* __GetMetaData(void)
{
    return sp_meta;
}
public:
virtual const char* GetMetaData(void) override
{return __GetMetaData();}
public:
virtual std::size_t GetMetaSize(void) override
{return __GetMetaSize();}
