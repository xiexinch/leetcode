#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

class ThroneInheritance {
private:
    std::unordered_map<std::string, std::vector<std::string>> children;
    std::unordered_set<std::string> dead;
    std::string king;
    std::vector<std::string> order;

    void dfs(std::string u) {
        if (!dead.count(u)) {
            order.emplace_back(u);
        }
        for (std::string v: children[u]) {
            dfs(v);
        }
    }

public:
    ThroneInheritance(std::string kingName) {
        this->king = kingName;
        this->children[kingName] = {};
    }
    
    void birth(std::string parentName, std::string childName) {
        this->children[parentName].emplace_back(childName);
    }
    
    void death(std::string name) {
        this->dead.insert(name);
    }
    
    std::vector<std::string> getInheritanceOrder() {
        this->order.clear();
        this->dfs(this->king);
        return order;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */