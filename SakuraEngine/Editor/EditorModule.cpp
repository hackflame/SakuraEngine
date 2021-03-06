/*
 * @This File is Part of Sakura by SaeruHikari: 
 * @Description: Copyright SaeruHikari
 * @Version: 0.1.0
 * @Autor: SaeruHikari
 * @Date: 2020-02-24 13:05:07
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2020-03-30 16:20:51
 */
#include "EditorModule.h"
#include "SakuraEngine/Core/Core.h"
#include "RenderGraphTestApplication.hpp"

void EditorModule::OnLoad()
{
    EditorModule::debug_info<Sakura::flags::DEBUG_EDITOR>
        ("EditorModule Loaded!");
	return;
}

void EditorModule::OnUnload()
{
    EditorModule::debug_info<Sakura::flags::DEBUG_EDITOR>
        ("EditorModule Unloaded!");
	return;
}

void EditorModule::MainPluginExec()
{
    EditorModule::debug_info<Sakura::flags::DEBUG_EDITOR>
        ("Editor Module: Main Plugin Exec!");
    //auto app = std::make_unique<VkTestApplication>();
    auto app = std::make_unique<RenderGraphTestApplication>();
	app->run();
    return;
}
