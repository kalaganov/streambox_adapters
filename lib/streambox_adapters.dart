
import 'streambox_adapters_platform_interface.dart';

class StreamboxAdapters {
  Future<String?> getPlatformVersion() {
    return StreamboxAdaptersPlatform.instance.getPlatformVersion();
  }
}
