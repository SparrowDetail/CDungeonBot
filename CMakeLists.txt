cmake_minimum_required(VERSION 3.22.1)

# Project name, version and description
project(dungeonBot VERSION 0.1 DESCRIPTION "DnD helper bot")
 
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
 
# Create an executable
add_executable(${PROJECT_NAME}
    src/DungeonBot.cpp
)
 
# Find our pre-installed DPP package (using FindDPP.cmake).
find_package(DPP REQUIRED)
 
# Link the pre-installed DPP package.
target_link_libraries(${PROJECT_NAME} 
    ${DPP_LIBRARIES}
)
 
# Include the DPP directories.
target_include_directories(${PROJECT_NAME} PRIVATE
    ${DPP_INCLUDE_DIR}
)
 
# Set C++ version
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)