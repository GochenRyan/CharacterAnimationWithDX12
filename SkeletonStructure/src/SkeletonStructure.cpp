#include <fbxsdk.h>
#include <string>
#include <iostream>

static void PrintBoneHierarchy(FbxNode* pNode, int depth)
{
    if (pNode == nullptr)
        return;

    auto attribute = pNode->GetNodeAttribute();

    if (attribute->GetAttributeType() == FbxNodeAttribute::EType::eSkeleton)
    {
        auto pSkeleton = pNode->GetSkeleton();
        for (int i = 0; i < depth; ++i)
            std::cout << "  ";
        std::cout << pNode->GetName();

        auto pParent = pNode->GetParent();
        if (pParent)
        {
            std::cout << " (Parent: " << pParent->GetName() << ")";
        }
        std::cout << std::endl;

        for (int i = 0; i < pNode->GetChildCount(); ++i)
        {
            PrintBoneHierarchy(pNode->GetChild(i), depth + 1);
        }
    }
}

int main()
{
    std::string fbxPath = std::string(FBX_RESOURCES_DIR) + "/hip-hop-dancing/Hip Hop Dancing.fbx";
    std::cout << "FBX Path: " << fbxPath << std::endl;

    // Initialize the SDK manager. This object handles memory management.
    FbxManager* lSdkManager = FbxManager::Create();

    // Create the IO settings object.
    FbxIOSettings* ios = FbxIOSettings::Create(lSdkManager, IOSROOT);
    lSdkManager->SetIOSettings(ios);

    // Create an importer using the SDK manager.
    FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");

    // Check the file format
    int format = -1;
    if (!lSdkManager->GetIOPluginRegistry()->DetectReaderFileFormat(fbxPath.data(), format)) {
        format = lSdkManager->GetIOPluginRegistry()->FindReaderIDByDescription("FBX binary (*.fbx)");
    }

    // Use the first argument as the filename for the importer.
    if (!lImporter->Initialize(fbxPath.data(), format, lSdkManager->GetIOSettings()))
    {
        printf("Call to FbxImporter::Initialize() failed.\n");
        printf("Error returned: %s\n\n", lImporter->GetStatus().GetErrorString());
        exit(-1);
    }

    // Create a new scene so that it can be populated by the imported file.
    FbxScene* lScene = FbxScene::Create(lSdkManager, "myScene");

    // Import the contents of the file into the scene.
    lImporter->Import(lScene);

    // The file is imported, so get rid of the importer.
    lImporter->Destroy();

    // Print the nodes of the scene and their attributes recursively.
    // Note that we are not printing the root node because it should
    // not contain any attributes.
    FbxNode* lRootNode = lScene->GetRootNode();
    if (lRootNode) {
        for (int i = 0; i < lRootNode->GetChildCount(); i++)
            PrintBoneHierarchy(lRootNode->GetChild(i), 0);
    }
    // Destroy the SDK manager and all the other objects it was handling.
    lSdkManager->Destroy();

    return 0;
}