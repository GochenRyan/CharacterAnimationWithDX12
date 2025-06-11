# 设置 FBX SDK 的根目录
find_path(FBXSDK_INCLUDE_DIR
  NAMES fbxsdk.h
  HINTS "${CMAKE_SOURCE_DIR}/ThirdParty/fbxsdk/include"
  NO_DEFAULT_PATH  # 强制只在指定路径查找，避免冲突
)

# 查找不同构建配置下的库文件（.lib 和 .dll）
# 注意：需要为每个配置（Debug/Release 等）显式设置路径
set(FBX_LIB_DEBUG "${CMAKE_SOURCE_DIR}/ThirdParty/fbxsdk/lib/libfbxsdk.lib")
set(FBX_LIB_RELEASE "${CMAKE_SOURCE_DIR}/ThirdParty/fbxsdk/lib/libfbxsdk.lib")

set(FBX_DLL_DEBUG "${CMAKE_SOURCE_DIR}/ThirdParty/fbxsdk/bin/libfbxsdk.dll")
set(FBX_DLL_RELEASE "${CMAKE_SOURCE_DIR}/ThirdParty/fbxsdk/bin/libfbxsdk.dll")

# 设置 MinSizeRel 的 .lib 和 .dll 路径
set(FBX_LIB_MINSIZEREL "${CMAKE_SOURCE_DIR}/ThirdParty/fbxsdk/lib/libfbxsdk.lib")
set(FBX_DLL_MINSIZEREL "${CMAKE_SOURCE_DIR}/ThirdParty/fbxsdk/bin/libfbxsdk.dll")

# RelWithDebInfo
set(FBX_LIB_RELWITHDEBINFO "${CMAKE_SOURCE_DIR}/ThirdParty/fbxsdk/lib/libfbxsdk.lib")
set(FBX_DLL_RELWITHDEBINFO "${CMAKE_SOURCE_DIR}/ThirdParty/fbxsdk/bin/libfbxsdk.dll")


# 检查是否找到所需的文件
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(FBXSDK
  REQUIRED_VARS FBXSDK_INCLUDE_DIR FBX_LIB_DEBUG FBX_LIB_RELEASE FBX_DLL_DEBUG FBX_DLL_RELEASE
)

# 如果找到，创建 IMPORTED 目标并设置不同配置的路径
if(FBXSDK_FOUND)
  add_library(FBXSDK::FBXSDK SHARED IMPORTED GLOBAL)  # 创建共享库目标

  # 设置包含目录（所有配置通用）
  set_target_properties(FBXSDK::FBXSDK PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${FBXSDK_INCLUDE_DIR}"
  )

  # 设置 Debug 配置的 .lib 和 .dll 路径
  set_target_properties(FBXSDK::FBXSDK PROPERTIES
    IMPORTED_IMPLIB_DEBUG "${FBX_LIB_DEBUG}"
    IMPORTED_LOCATION_DEBUG "${FBX_DLL_DEBUG}"
  )

  # 设置 Release 配置的 .lib 和 .dll 路径
  set_target_properties(FBXSDK::FBXSDK PROPERTIES
    IMPORTED_IMPLIB_RELEASE "${FBX_LIB_RELEASE}"
    IMPORTED_LOCATION_RELEASE "${FBX_DLL_RELEASE}"
  )

  # 设置目标属性
  set_target_properties(FBXSDK::FBXSDK PROPERTIES
    IMPORTED_IMPLIB_MINSIZEREL "${FBX_LIB_MINSIZEREL}"
    IMPORTED_LOCATION_MINSIZEREL "${FBX_DLL_MINSIZEREL}"
  )

  set_target_properties(FBXSDK::FBXSDK PROPERTIES
    IMPORTED_IMPLIB_RELWITHDEBINFO "${FBX_LIB_RELWITHDEBINFO}"
    IMPORTED_LOCATION_RELWITHDEBINFO "${FBX_DLL_RELWITHDEBINFO}"
  )
endif()