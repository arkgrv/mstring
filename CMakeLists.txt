cmake_minimum_required(VERSION 3.10)
project(mstring LANGUAGES C CXX)

# Add the src subdirectory (library sources)
add_subdirectory("src")

# Add the test subdirectory (unit tests)
add_subdirectory("test")
