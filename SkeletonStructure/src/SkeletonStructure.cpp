#include <fbxsdk.h>
#include <string>
#include <iostream>

int main()
{
    std::string fbx_path = std::string(FBX_RESOURCES_DIR) + "/vietnam-helmet-free/source/Helmet1.fbx";
    std::cout << "FBX Path: " << fbx_path << std::endl;
    return 0;
}