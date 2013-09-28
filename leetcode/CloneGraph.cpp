/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:

    typedef map<int, UndirectedGraphNode*> NodeMap;

    UndirectedGraphNode* cloneNode(UndirectedGraphNode* node, NodeMap& allNodes) {
        if (!node)
            return 0;
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        allNodes[node->label] = newNode;
        for (size_t i = 0; i < node->neighbors.size(); ++i)
        {
            UndirectedGraphNode* neighbor = node->neighbors[i];
            NodeMap::iterator nIter = allNodes.find(neighbor->label);

            if (nIter != allNodes.end())
            {
                newNode->neighbors.push_back(nIter->second);
            }
            else
            {
                newNode->neighbors.push_back(cloneNode(neighbor, allNodes));
            }
        }
        return newNode;
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        NodeMap allNodes;
        UndirectedGraphNode* result = cloneNode(node, allNodes);
        return result;
    }
};
