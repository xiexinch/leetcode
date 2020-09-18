#include <vector>
#include <queue>
#include "treenode.hpp"


class Solution {
public:
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::queue<TreeNode*> nodeQueue;
        std::vector<double> ans;
        nodeQueue.push(root);
        int currentLevel = 1, nextLevel = 0;
        int counter = 0;
        double sum = 0;
        while (!nodeQueue.empty()) {
            TreeNode* temp = nodeQueue.front();
            nodeQueue.pop();
            if (temp -> left != nullptr) {
                nodeQueue.push(temp -> left);
                nextLevel++;
            }
            if (temp -> right != nullptr) {
                nodeQueue.push(temp -> right);
                nextLevel++;
            }
            currentLevel--;
            counter++;
            sum += temp -> val;
            if (currentLevel == 0) {
                ans.push_back(sum / (double)counter);
                counter = 0;
                sum = 0;
                currentLevel = nextLevel;
                nextLevel = 0;
            }
            
        }
        return ans;
    }
};