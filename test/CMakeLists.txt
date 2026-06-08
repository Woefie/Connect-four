# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(connect-fourTests LANGUAGES CXX)

# ---- Dependencies ----

find_package(Catch2 REQUIRED)
enable_testing()


# ---- Tests ----

add_executable(connect-four_test src/connect-four_test.cpp)
target_link_libraries(
    connect-four_test PRIVATE 
    connect-four_lib
    Catch2::Catch2WithMain
)
target_compile_features(connect-four_test PRIVATE cxx_std_20)

list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

catch_discover_tests(connect-four_test)

# ---- End-of-file commands ----

add_folders(Test)
