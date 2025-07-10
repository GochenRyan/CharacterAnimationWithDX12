project(SkeletonStructure)

set(FBX_RESOURCES_DIR "${CMAKE_SOURCE_DIR}/Resources/FBX")

file(GLOB_RECURSE src CONFIGURE_DEPENDS src/*cpp include/*.h)

add_executable(SkeletonStructure ${src})
setup_output_directories(SkeletonStructure)


target_compile_definitions(SkeletonStructure PRIVATE FBX_RESOURCES_DIR="${FBX_RESOURCES_DIR}")
target_include_directories(SkeletonStructure PRIVATE include)
target_link_libraries(SkeletonStructure PRIVATE FBXSDK::FBXSDK)
target_compile_definitions(SkeletonStructure PRIVATE FBXSDK_SHARED)