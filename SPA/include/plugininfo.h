/*
 * @This File is Part of Sakura by SaeruHikari: 
 * @Description: Copyright SaeruHikari
 * @Version: 0.1.0
 * @Autor: SaeruHikari
 * @Date: 2020-02-14 00:31:40
 * @LastEditors  : SaeruHikari
 * @LastEditTime : 2020-02-14 00:42:08
 */
#pragma once
#include <memory_resource>
#include <string>
#include <vector>
#include <cstdlib>

namespace Sakura::SPA
{
    /**
     * @description: Represents a dependency as specified in the 
     * plugin.json file. A list of dependencies is stored in each
     * PluginInfo Object. 
     * @author: SaeruHikari
     */
    struct Dependency
    {
        std::pmr::string name; //!< The name of the dependency
        std::pmr::string version; //!< The version of the dependency
    };

    /**
     * @description: Struct that contains all plugin metadata
     * @author: SaeruHikari
     */
    struct PluginInfo
    {
        std::pmr::string name; //!< name of the plugin
        std::pmr::string prettyname;//!< formatted name of the plugin
        std::pmr::string version;// !< version of the plugin
        std::pmr::string license;//!< license of the plugin
        std::pmr::string copyright;//!< copyright of the plugin

        // Dependencies array
        std::pmr::vector<std::unique_ptr<Dependency>> dependencies;
    };
}