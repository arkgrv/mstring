message(STATUS "Fetching googletest...")
include(FetchContent)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY	https://github.com/google/googletest.git
	GIT_TAG		release-1.12.0
	GIT_SHALLOW	TRUE
	GIT_PROGRESS	TRUE)
FetchContent_MakeAvailable(googletest)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(mstring_tests
	       "basic_test.cpp")
		   
target_link_libraries(mstring_tests gtest_main mstring)
target_include_directories(mstring_tests PUBLIC "../src/include")