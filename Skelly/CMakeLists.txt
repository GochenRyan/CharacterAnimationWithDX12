project(Skelly)

find_package(FBXSDK REQUIRED)

file(GLOB_RECURSE public_src CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE private_src CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(Skelly SHARED ${public_src} ${private_src})
setup_output_directories(Skelly)

target_include_directories(Skelly PUBLIC include)

target_link_libraries(Skelly PUBLIC d3dcompiler d3d12 dxgi)
target_link_libraries(Skelly PUBLIC FBXSDK::FBXSDK)
target_compile_definitions(Skelly PUBLIC FBXSDK_SHARED)