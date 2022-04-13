# An Example of C Shared Library

features:

- CMake Build
- It could be wrappped easily by Python C Extension Package(Tested on macOS, for Windows, Linux in future)

## Layout

Build Layout
`RPATH` in `build/tests/testhello` is an absolute dir.

.build
├── /src/libhello.dylib
└── /tests/testhello

Install Layout
`RPATH` in `bin/testhello` is set as `@executable_path`, where `testhello` is being executed.

.bin
├── /libhello.dylib
└── /testhello

## Usage

```sh
▶ mkdir build
▶ cd build

# Build, in `build` folder
▶ cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_SHARED_LIBS=ON \
    .. && cmake --build .

# Install
▶ cmake install

# Test
▶ ./tests/testhello
Hello Frank
```

## Debug

For Build, dylib's install_name and executable's RPATH setting

```sh
❯ otool -L build/src/libhello.dylib
build/src/libhello.dylib:
        @rpath/libhello.dylib (compatibility version 0.0.0, current version 0.0.0)
        /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1311.0.0)

❯ otool -L build/tests/testhello
build/tests/testhello:
        @rpath/libhello.dylib (compatibility version 0.0.0, current version 0.0.0)
        /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1311.0.0)

❯ otool -l build/tests/testhello | grep -C3 LC_RPATH
      current version 1311.0.0
compatibility version 1.0.0
Load command 15
          cmd LC_RPATH
      cmdsize 72
         path /Users/siyao/Documents/example-hello-c-lib/build/src (offset 12)
Load command 16
```

For Install,

```sh
❯ otool -L bin/libhello.dylib
bin/libhello.dylib:
        @rpath/libhello.dylib (compatibility version 0.0.0, current version 0.0.0)
        /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1311.0.0)

❯ otool -L bin/testhello
bin/testhello:
        @rpath/libhello.dylib (compatibility version 0.0.0, current version 0.0.0)
        /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1311.0.0)

❯ otool -l bin/testhello | grep -C3 LC_RPATH
  dataoff 49256
 datasize 0
Load command 17
          cmd LC_RPATH
      cmdsize 32
         path @executable_path (offset 12)
```
