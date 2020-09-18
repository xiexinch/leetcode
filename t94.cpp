#include <vector>
#include <stack>
#include "treenode.hpp"


class Solution {

public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        std::stack<TreeNode*> st;
        while (root != nullptr || !st.empty()) {
            while (root != nullptr) {
                st.push(root -> left);
                root = root -> left;
            }
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            root = root -> right;
        }
        return ans;
    }

};