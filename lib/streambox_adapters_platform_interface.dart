import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'streambox_adapters_method_channel.dart';

abstract class StreamboxAdaptersPlatform extends PlatformInterface {
  /// Constructs a StreamboxAdaptersPlatform.
  StreamboxAdaptersPlatform() : super(token: _token);

  static final Object _token = Object();

  static StreamboxAdaptersPlatform _instance = MethodChannelStreamboxAdapters();

  /// The default instance of [StreamboxAdaptersPlatform] to use.
  ///
  /// Defaults to [MethodChannelStreamboxAdapters].
  static StreamboxAdaptersPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [StreamboxAdaptersPlatform] when
  /// they register themselves.
  static set instance(StreamboxAdaptersPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }
}
