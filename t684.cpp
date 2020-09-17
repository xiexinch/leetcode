#include <vector>

class Solution {
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        std::vector<int> rp(1001);
        int sz = edges.size();
        for (int i = 0; i < sz; i++) {
            rp[i] = i;
        }
        for (int j = 0; j < sz; j++) {
            int set1 = find(edges[j][0], rp);
            int set2 = find(edges[j][1], rp);
            if (set1 == set2) {
                return edges[j];
            } else {
                rp[set1] = set2;
            }
        }
        return {0, 0};
    }

    int find(int n, std::vector<int> &rp) {
        int num = n;
        while (rp[num] != num) {
            num = rp[num];
        }
        return num;
    }
};