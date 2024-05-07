project(mstring LANGUAGES C)

set(CMAKE_C_STANDARD 99)

# Set basic compiler flags
if (MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "/Od /TC /Z7 /MTd")
    set(CMAKE_CXX_FLAGS_RELEASE "/Os /TC /MT")
else()
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -fsanitize=address")
    set(CMAKE_CXX_FLAGS_DEBUG "-Os")
endif()


add_library(${CMAKE_PROJECT_NAME} "mstring.c" "include/mstring.h")
