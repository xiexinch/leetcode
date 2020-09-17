#include <vector>
#include <stack>

class Solution {
public:
    bool find132pattern(std::vector<int>& nums) {
        if(nums.size()<3)
            return false;
        std::stack<int> sta;
        int third = INT_MIN;
        for( int i = nums.size()-1;i>=0;i--){
            if(nums[i]<third)return true;
            while(!sta.empty()&&sta.top()<nums[i]){
                third = sta.top();
                sta.pop();
            }
            sta.push(nums[i]);
        }
        return false;
    }
};