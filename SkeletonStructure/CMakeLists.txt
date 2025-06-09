project(SkeletonStructure)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")
find_package(FBXSDK REQUIRED)

file(GLOB_RECURSE src CONFIGURE_DEPENDS src/*cpp include/*.h)

add_executable(SkeletonStructure ${src})
setup_output_directories(SkeletonStructure)

target_include_directories(SkeletonStructure PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE FBXSDK::FBXSDK)