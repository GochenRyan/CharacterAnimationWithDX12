#include <Skelly/FBXConverter/FBXConverter.h>
#include <Skelly/Gfx/StaticMeshNode.h>

using namespace Skelly;

namespace
{
    DirectX::XMFLOAT4X4 MayaToDX12(
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, -1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    );
}


bool Skelly::FBXConverter::ExportFile(std::string_view src, std::string_view dst)
{
    // Check the file format
    int format = -1;
    if (!mFbxManager->GetIOPluginRegistry()->DetectReaderFileFormat(src.data(), format)) {
        format = mFbxManager->GetIOPluginRegistry()->FindReaderIDByDescription("FBX binary (*.fbx)");
    }

    // Use the first argument as the filename for the importer.
    if (!mFbxImporter->Initialize(src.data(), format, mFbxManager->GetIOSettings()))
    {
        printf("Call to FbxImporter::Initialize() failed.\n");
        printf("Error returned: %s\n\n", mFbxImporter->GetStatus().GetErrorString());
        return false;
    }

    if (!mFbxImporter->Import(mFbxScene))
        return false;
    
    switch (mExportType)
    {
        case ExportType::STATIC_MESH:
        {
            // mNode = std::make_shared<StaticMeshNode>();
            // mGeometryNode = std::make_shared<GeometryNode>();
        }
    }

    return true;
}

bool FBXConverter::InitFBX()
{
    // Initialize the SDK manager. This object handles memory management.
    mFbxManager = FbxManager::Create();
    if (!mFbxManager)
        return false;

    // Create the IO settings object.
    FbxIOSettings* ios = FbxIOSettings::Create(mFbxManager, IOSROOT);
    mFbxManager->SetIOSettings(ios);

    // Create an importer using the SDK manager.
    mFbxImporter = FbxImporter::Create(mFbxManager, "");

    // Create a new scene so that it can be populated by the imported file.
    mFbxScene = FbxScene::Create(mFbxManager, "");

    FbxGlobalSettings& globalSettings = mFbxScene->GetGlobalSettings();
    if (globalSettings.GetAxisSystem() != FbxAxisSystem::DirectX)
    {
        FbxAxisSystem::DirectX.ConvertScene(mFbxScene);
    }

    FbxSystemUnit systemUnit = globalSettings.GetSystemUnit();
    if (systemUnit != FbxSystemUnit::m)
    {
        const FbxSystemUnit::ConversionOptions options = {
            false,
            true,
            true,
            true,
            true,
            true
        };

        FbxSystemUnit::m.ConvertScene(mFbxScene, options);
    }

    return true;
}

