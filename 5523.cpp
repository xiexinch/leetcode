#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int minOperations(std::vector<std::string>& logs) {
        int step = 0;
        for (auto i : logs) {
            if (i == "./" || (i == "../" && step == 0)) {
                continue;
            } else if (i == "../" && step > 0) {
                step--;
            } else {
                step++;
            }
        }
        return step;      
    }
};