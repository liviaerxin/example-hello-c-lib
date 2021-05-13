# An Example C Hello Shared Library Imported By Python C Extension Package(Tested on macOS, for Windows, Linux in future)

## Usage

```sh
▶ mkdir build
▶ cd build

# Build, in `build` folder
▶ cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_SHARED_LIBS=ON \
    .. && cmake --build .

# Test
▶ ./tests/testhello
Hello Frank

# Check dylib's install_name and executable's RPATH setting
▶ otool -L src/libhello.dylib
src/libhello.dylib:
	@rpath/libhello.dylib (compatibility version 0.0.0, current version 0.0.0)
	/usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1281.0.0)

▶ otool -L tests/testhello 
tests/testhello:
	@rpath/libhello.dylib (compatibility version 0.0.0, current version 0.0.0)
	/usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1281.0.0)

▶ otool -l tests/testhello | grep -C3 LC_RPATH
      current version 1281.0.0
compatibility version 1.0.0
Load command 15
          cmd LC_RPATH
      cmdsize 40
         path @executable_path/../src (offset 12)
Load command 16
```
