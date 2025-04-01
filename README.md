# Connect-four

This is the connect-four project for the recruitment process of **S[&]T**.

## Building and installing

Tested on Build on WSL (ubuntu 22.04)
dependcy install instructions:

First follow install instruction from [vcpkg](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started?pivots=shell-powershell)

```sh
sudo apt install build-essential
sudo apt install pkg-config
```


See the [BUILDING](BUILDING.md) document.

## TODO's

* Fix `CMAKE_TOOLCHAIN_FILE` in CMakePrests.json for linux so its not a hardcoded path
  * Visual Studio cross compiling cmake does not understand `$env{VCPKG_ROOT}` to get the environment variable from wsl
* Clear more warnings that clang-tidy suggests
* Maybe a sizeable board for more then 2 players as a extra feature
* Cleanup doxygen generation

## Licensing

MIT
