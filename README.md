# streambox_adapters

A set of ready-to-use storage adapters for the
[`streambox_core`](https://pub.dev/packages/streambox_core) framework.  
Provides pluggable implementations of `KeyValueStoreInterface` for common
Flutter & Dart storage backends.

[![pub package](https://img.shields.io/pub/v/streambox_adapters.svg)](https://pub.dev/packages/streambox_adapters)
[![style: very good analysis](https://img.shields.io/badge/style-very_good_analysis-B22C89.svg)](https://pub.dev/packages/very_good_analysis)
[![Verified Publisher](https://img.shields.io/pub/publisher/streambox_adapters)](https://pub.dev/packages/streambox_adapters)

---

## ✨ Features

- Drop-in storage adapters for `streambox_core`
- Built-in support for:
  - Memory-only store
  - SharedPreferences (async)
  - SharedPreferences with in-memory caching
  - FlutterSecureStorage for encrypted values
- Unified `KeyValueStoreInterface` contract
- Easy integration with custom cache strategies

---

## 📦 Installation

```yaml
dependencies:
  streambox_core: ^1.0.0
  streambox_adapters: ^1.0.0
```

---

## 💄 Why a Separate Package?

The `streambox_adapters` package was split from `streambox_core` to:

- Keep the **core library lightweight** and focused on abstractions
- Avoid **extra dependencies** for users who don’t need adapters
- Allow **faster independent updates** to adapters without releasing a new
  version of `streambox_core`
- Provide a **clean modular design**, so you only import what you need

---

## 🗄️ Available Adapters

### MemoryStoreAdapter

- Stores values in memory only  
- Perfect for testing, prototyping, ephemeral caches  
- Persistence: ❌ (cleared when app restarts)

### AsyncSharedPrefsStorageAdapter

- Uses the asynchronous `SharedPreferencesAsync` API  
- Great for general persistent storage with async access  
- Persistence: ✅ (shared preferences)

### CachedSharedPrefsStorageAdapter

- Backed by `SharedPreferencesWithCache`  
- Reduces disk I/O via in-memory caching  
- Persistence: ✅ (cached + disk-backed)

### FlutterSecureStorageAdapter

- Backed by `flutter_secure_storage`  
- Encrypted and secure key-value storage  
- Ideal for sensitive data (tokens, credentials)  
- Persistence: ✅ (secure & encrypted)

---

## 📘 Example Usage

```dart
import 'package:streambox_core/streambox_core.dart';
import 'package:streambox_adapters/streambox_adapters.dart';

final repo = ExampleRepoImpl(
  dataSource: ExampleDataSource(
    api: ExampleApiInterface(dio),
    cacheStrategy: CacheThenRefreshStrategy(
      cache: BaseKeyValueCache(
        store: FlutterSecureStorageAdapter(),
      ),
    ),
  ),
);
```

If you don’t need persistence:

```dart
cacheStrategy: NoOpCacheStrategy(),
```

---

## 🛠 Extensibility

You can implement:

- Custom adapters via `KeyValueStoreInterface`
- Your own persistent backends (e.g., Hive, Isar, SQLite)
- Specialized storage layers for advanced use cases
