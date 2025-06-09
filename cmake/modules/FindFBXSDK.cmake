# 设置 FBX SDK 的根目录
find_path(FBXSDK_INCLUDE_DIR
  NAMES fbxsdk.h
  HINTS "${CMAKE_SOURCE_DIR}/ThirdParty/fbxsdk/include"
)

# 设置库文件路径
find_library(FBXSDK_LIBRARY
  NAMES libfbxsdk fbxsdk
  HINTS "${CMAKE_SOURCE_DIR}/ThirdParty/fbxsdk/lib"
)

# 检查是否找到所需的文件
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(FBXSDK
  REQUIRED_VARS FBXSDK_INCLUDE_DIR FBXSDK_LIBRARY
)

# 如果找到，创建 IMPORTED 目标
if(FBXSDK_FOUND)
  add_library(FBXSDK::FBXSDK STATIC IMPORTED GLOBAL)
  set_target_properties(FBXSDK::FBXSDK PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${FBXSDK_INCLUDE_DIR}"
    IMPORTED_LOCATION "${FBXSDK_LIBRARY}"
  )
endif()
