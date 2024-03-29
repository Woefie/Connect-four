# Building with CMake

## Dependencies

For a list of dependencies, please refer to [vcpkg.json](vcpkg.json).

## Build

Make sure to read the generated [HACKING.md](HACKING.md) document to see what needs to be done to fetch dependencies.

This project doesn't require any special command-line flags to build to keep things simple.
But as explained in [HACKING.md](HACKING.md) this project does depend on vcpkg. So to use that set CMAKE_TOOLCHAIN_FILE to vcpkg root.

Unix Makefiles one:

```sh
mkdir build; cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE="${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
cmake --build .
```

Visual Studio:

```sh
mkdir build; cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE="{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
cmake --build . --config Release

```

### Building with MSVC

Note that MSVC by default is not standards compliant and you need to pass some
flags to make it behave properly. See the `flags-windows` preset in the
[CMakePresets.json](CMakePresets.json) file for the flags and with what
variable to provide them to CMake during configuration.

## Install

This project doesn't require any special command-line flags to install to keep
things simple. As a prerequisite, the project has to be built with the above
commands already.

The below commands require at least CMake 3.15 to run, because that is the
version in which [Install a Project][2] was added.

Here is the command for installing the release mode artifacts with a
single-configuration generator, like the Unix Makefiles one:

```sh
cmake --install build
```

Here is the command for installing the release mode artifacts with a
multi-configuration generator, like the Visual Studio ones:

```sh
cmake --install build --config Release
```

[1]: https://cmake.org/download/
[2]: https://cmake.org/cmake/help/latest/manual/cmake.1.html#install-a-project
