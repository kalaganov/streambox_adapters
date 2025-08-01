## 1.2.0
- bump streambox_core to ^1.2.0

## 1.1.0

- Initial standalone release of `streambox_adapters`.
- Moved all storage adapters out of `streambox_core` into this package.
- Provided ready-to-use implementations of `KeyValueStoreInterface`:
  - AsyncSharedPrefsStorageAdapter
  - CachedSharedPrefsStorageAdapter
  - FlutterSecureStorageAdapter
  - MemoryStoreAdapter
