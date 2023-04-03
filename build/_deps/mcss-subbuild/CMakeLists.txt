# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.22.1)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(mcss-populate NONE)



include(ExternalProject)
ExternalProject_Add(mcss-populate
                     "UPDATE_DISCONNECTED" "False" "URL" "https://github.com/friendlyanon/m.css/releases/download/release-1/mcss.zip" "URL_MD5" "00cd2757ebafb9bcba7f5d399b3bec7f" "UPDATE_DISCONNECTED" "YES"
                    SOURCE_DIR          "/mnt/c/Projects/connect-four/build/mcss"
                    BINARY_DIR          "/mnt/c/Projects/connect-four/build/_deps/mcss-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)


