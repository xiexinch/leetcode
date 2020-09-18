#include <vector>
#include <algorithm>

class Solution {
private:
    std::vector<int> vis;
public:

    void backtrack(std::vector<int> & nums, std::vector<std::vector<int>>& ans, int idx, std::vector<int>& perm) {
        int sz = nums.size();
        if (idx == sz) {
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < sz; i++) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, idx + 1, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }

    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> perm;
        std::sort(nums.begin(), nums.end());
        vis.resize(nums.size());
        backtrack(nums, ans, 0, perm);
        return ans;
    }
};