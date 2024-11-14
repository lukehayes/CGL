cmake_minimum_required(VERSION 3.2)
project(XXGL)

# Variables.
# 
set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(INCLUDE_DIRS "include")
set(XX_DIR "${PROJECT_SOURCE_DIR}/src/xx")
set(BIN_NAME "cgl")

# -----------------------------------------------------------------------------
# Find SDL library.
# 
find_package(SDL2 REQUIRED)

# -----------------------------------------------------------------------------
# Set the project include directories.
# 
include_directories(${INCLUDE_DIRS})

add_executable(${BIN_NAME} main.c src/glad.c)

#add_subdirectory("src")

 set(XX_LIB "xx")

 add_library(${XX_LIB} STATIC
	 "${XX_DIR}/gl/debug_program.c"
 )

# -----------------------------------------------------------------------------
# Build the System Library
# 
# set(SYSTEM_LIB "XXSystem")
#
# add_library(${SYSTEM_LIB} SHARED
# 	"${XX_DIR}/System/Engine.cpp"
# 	"${XX_DIR}/System/Window.cpp"
# )

# -----------------------------------------------------------------------------
# Build the GFX Library
# 
# set(GFX_LIB "XXGfx")
#
# add_library(${GFX_LIB} SHARED
# 	"${XX_DIR}/Gfx/Buffer.cpp"
# 	"${XX_DIR}/Gfx/Shader.cpp"
# 	"${XX_DIR}/Gfx/Camera3D.cpp"
# )


# -----------------------------------------------------------------------------
# Link in the libraies the binary needs.
# 
target_link_libraries(${BIN_NAME} SDL2)
target_link_libraries(${BIN_NAME} ${XX_LIB})

