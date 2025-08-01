#ifndef FLUTTER_PLUGIN_STREAMBOX_ADAPTERS_PLUGIN_H_
#define FLUTTER_PLUGIN_STREAMBOX_ADAPTERS_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace streambox_adapters {

class StreamboxAdaptersPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  StreamboxAdaptersPlugin();

  virtual ~StreamboxAdaptersPlugin();

  // Disallow copy and assign.
  StreamboxAdaptersPlugin(const StreamboxAdaptersPlugin&) = delete;
  StreamboxAdaptersPlugin& operator=(const StreamboxAdaptersPlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace streambox_adapters

#endif  // FLUTTER_PLUGIN_STREAMBOX_ADAPTERS_PLUGIN_H_
