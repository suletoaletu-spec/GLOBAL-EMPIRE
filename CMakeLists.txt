cmake_minimum_required(VERSION 3.10)
project(GLOBAL-EMPIRE VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    Main
    Ui/Components/U
)

# Create executable
add_executable(empire ${SOURCES})

# Compiler flags for different configurations
if(MSVC)
    target_compile_options(empire PRIVATE /W4)
else()
    target_compile_options(empire PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Installation
install(TARGETS empire DESTINATION bin)

# Enable testing
enable_testing()

# Add custom targets
add_custom_target(run COMMAND empire DEPENDS empire)
add_custom_target(clean-build COMMAND ${CMAKE_COMMAND} -P cmake_clean.cmake)
