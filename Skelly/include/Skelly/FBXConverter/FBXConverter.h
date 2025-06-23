#pragma once
#include <Skelly/BoneNode.h>
#include <Skelly/Core/Skelly.h>
#include <Skelly/FBXConverter/ExportEnums.h>
#include <Skelly/Gfx/GeometryNode.h>
#include <Skelly/Gfx/MeshNode.h>

#include <fbxsdk.h>
#include <string_view>

namespace Skelly
{
    class SKELLY_API FBXConverter
    {
    public:
        bool ExportFile(std::string_view src, std::string_view dst);
    private:
        bool InitFBX();
        bool GetMeshNode(FbxNode* pNode);
        void GetAnim(FbxNode* pNode);
        void GetSkeleton(FbxNode* pNode, std::shared_ptr<BoneNode> pParentBoneNode = nullptr);
        void MaxMatToDX12Mat(const FbxAMatrix &MaxMat, DirectX::XMFLOAT4X4& VSMat);
        void ReadVertex(FbxGeometryBase* pMesh, int ctrlPointIndex, DirectX::XMFLOAT3& Vertex);
        void ReadColor(FbxGeometryBase* pMesh, int ctrlPointIndex, int vertexCounter, DirectX::XMFLOAT3& Color);
        void ReadUV(FbxGeometryBase* pMesh, int ctrlPointIndex, int textureUVIndex, int uvLayer, DirectX::XMFLOAT2& UV);
        void ReadNormal(FbxGeometryBase* pMesh, int ctrlPointIndex, int vertexCounter, DirectX::XMFLOAT3& Normal);
        void ReadTangent(FbxGeometryBase* pMesh, int ctrlPointIndex, int vertexCounter, DirectX::XMFLOAT3& Tangent);
        void ReadBinormal(FbxGeometryBase* pMesh, int ctrlPointIndex, int vertexCounter, DirectX::XMFLOAT3& Tangent);
        void GetTriangleMaterialIndex(FbxGeometryBase* pMesh, int triangleCount, std::vector<int>& TriangleMaterialIndex);
        void GetTriangleSmGroupIndex(FbxGeometryBase* pMesh, int triangleCount, std::vector<int>& TriangleSmGroupIndex);
        void CreateTangentAndBinormal(const DirectX::XMFLOAT3& Point0, const DirectX::XMFLOAT3& Point1, const DirectX::XMFLOAT3& Point2,
                                      const DirectX::XMFLOAT2& TexCoord0, const DirectX::XMFLOAT2& TexCoord1, const DirectX::XMFLOAT2& TexCoord2,
                                      const DirectX::XMFLOAT3& Normal, DirectX::XMFLOAT3& Tangent, DirectX::XMFLOAT3& Binormal);
    
    public:
        ExportType mExportType;
        ExportParam mExportParam;
    private:
        FbxManager* mFbxManager{nullptr};
        FbxImporter* mFbxImporter{nullptr};
        FbxScene* mFbxScene{nullptr};

        std::shared_ptr<MeshNode<GeometryNode>> mNode;
        std::shared_ptr<GeometryNode> mGeometryNode;
    };
}
