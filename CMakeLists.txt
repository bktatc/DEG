cmake_minimum_required(VERSION 3.16)

project(CoordinateConverter
    VERSION 1.0.0
    DESCRIPTION "Coordinate Converter"
    LANGUAGES CXX
)

# ===========================
# C++ Standard
# ===========================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ===========================
# Compiler Warnings
# ===========================
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ===========================
# Executable
# ===========================
add_executable(CoordinateConverter
    src/main.cpp
    src/GeoUtils.cpp
)

# ===========================
# Header Locations
# ===========================
target_include_directories(CoordinateConverter
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src
)

# ===========================
# Installation (optional)
# ===========================
install(TARGETS CoordinateConverter
    RUNTIME DESTINATION bin
)
