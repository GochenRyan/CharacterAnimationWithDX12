project(Common)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB_RECURSE public_src CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE private_src CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(Common SHARED ${public_src} ${private_src})
setup_output_directories(Common)

target_include_directories(Common PUBLIC include)

target_link_libraries(Common PUBLIC d3dcompiler d3d12 dxgi)