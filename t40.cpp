#include <vector>
#include <algorithm>


class Solution {
private:
    std::vector<std::pair<int, int>> freq;
    std::vector<std::vector<int>> ans;
    std::vector<int> sequence;

public:
    void dfs(int pos, int rest) {
        if (rest == 0) {
            ans.push_back(sequence);
            return;
        }
        if (pos == freq.size() || rest < freq[pos].first) {
            return;
        }

        dfs(pos + 1, rest);

        int most = std::min(rest / freq[pos].first, freq[pos].second);
        for (int i = 1; i <= most; i++) {
            sequence.push_back(freq[pos].first);
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        for (int i = 1; i <= most; i++) {
            sequence.pop_back();
        }
    }

    std::vector<std::vector<int> > combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        for (int num: candidates) {
            if (freq.empty() || num != freq.back().first) {
                freq.emplace_back(num, 1);
            } else {
                freq.back().second++;
            }
        }
        dfs(0, target);
        return ans;
    }

};