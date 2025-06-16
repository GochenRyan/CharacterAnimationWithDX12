#include <Skelly/BoneNode.h>

using namespace Skelly;

void BoneNode::GetAllNodes(std::vector<std::shared_ptr<BoneNode>> &allNodes)
{
    allNodes.push_back(shared_from_this());
    for (auto child : mChildren)
    {
        allNodes.push_back(child);
    }
}