# *************************
# *** GOOGLE TEST SETUP ***
# *************************

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.gt googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)


# *****************************
# *** RAPIDCHECK TEST SETUP ***
# *****************************

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.rc rapidcheck-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/rapidcheck-download )
if(result)
    message(FATAL_ERROR "CMake step for rapidcheck failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/rapidcheck-download )
if(result)
    message(FATAL_ERROR "Build step for rapidcheck failed: ${result}")
endif()

# Add rapidcheck directly to our build.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/rapidcheck-src
        ${CMAKE_CURRENT_BINARY_DIR}/rapidcheck-build
        EXCLUDE_FROM_ALL)

# *************************
# *** BUILDING BINARIES ***
# *************************

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(example example.cpp)
target_link_libraries(example gtest_main)

# Adds a test to the project to be run by the ctest command.
# This will only be done if enable_testing has been invoked.
add_test(NAME example_test COMMAND example)

add_executable(example_rc example_rc.cpp)
target_link_libraries(example_rc rapidcheck)