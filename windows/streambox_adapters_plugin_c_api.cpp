#include "include/streambox_adapters/streambox_adapters_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "streambox_adapters_plugin.h"

void StreamboxAdaptersPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  streambox_adapters::StreamboxAdaptersPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
