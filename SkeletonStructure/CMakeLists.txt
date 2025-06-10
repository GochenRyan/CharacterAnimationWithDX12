project(SkeletonStructure)

set(PROJECT_ROOT "${PROJECT_SOURCE_DIR}")
set(FBX_RESOURCES_DIR "${PROJECT_ROOT}/Resources/FBX")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")
find_package(FBXSDK REQUIRED)

file(GLOB_RECURSE src CONFIGURE_DEPENDS src/*cpp include/*.h)

add_executable(SkeletonStructure ${src})
setup_output_directories(SkeletonStructure)

target_compile_definitions(SkeletonStructure PRIVATE FBX_RESOURCES_DIR="${FBX_RESOURCES_DIR}")
target_include_directories(SkeletonStructure PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE FBXSDK::FBXSDK)