#include <vector>
#include <string>

class Solution {
private:
    void backtrack(std::vector<std::string>& ans, std::string& cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.emplace_back(cur);
            return;
        }
        if (open < n) {
            cur += '(';
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur += ')';
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ans;
        std::string cur;
        backtrack(ans, cur, 0, 0, n);
        return ans;
    }
};