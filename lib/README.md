## How to build and link v8 into Inexor Core

### 1. Clone Depot Tools

This is part of the build stack. Do not clone the git repository directly.

```
PWD=`pwd`
cd build
git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
export PATH=$PATH:{$PWD}/build/depot_tools
gclient
```

### 2. Fetch v8 sources

```
mkdir {$PWD}/build/v8
cd {$PWD}/build/v8
fetch v8
cd {$PWD}/build/v8/v8
```

### 3. Update sources

```
gclient sync
```

### 4. Install build dependencies (Linux)

```
{$PWD}/build/v8/v8/build/install-build-deps.sh
```

### 5. Build the static library

This is can take a while. The build parameters are all required. Basically our use case is possible but the defaults are the complete opposite. We want a monolitic static library compiled with GCC instead of clang (libcxx).

```
{$PWD}/build/v8/v8/tools/dev/v8gen.py x64.debug -- v8_monolithic=true v8_static_library=true v8_use_external_startup_data=false is_component_build=false is_clang=false use_sysroot=false v8_enable_i18n_support=false v8_enable_backtrace=false use_glib=false use_custom_libcxx=false use_custom_libcxx_for_host = false treat_warnings_as_errors = false && ninja -C out.gn/x64.debug v8_monolith
```

### 6. Copy static library to lib folder (see CMakeLists.txt)

```
cp -a {$PWD}/build/v8/v8/out.gn/x64.debug/obj/libv8_monolith.a {$PWD}/lib
```

Afterwards you should have a file {$PWD}/lib/libv8_monolith.a

### 7. Congrats

> Now you are able to link
