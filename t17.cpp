#include <vector>
#include <map>
#include <string>
#include <unordered_map>


class Solution {
public:
    void backtrack(std::vector<std::string>& combinations, const std::unordered_map<char, std::string>& phoneMap, const std::string& digits, int index, std::string& combination) {
        if (index == digits.length()) {
            combinations.push_back(combination);
            return;
        }
        char digit = digits[index];
        const std::string& letters = phoneMap.at(digit);
        for (const char& letter: letters) {
            combination.push_back(letter);
            backtrack(combinations, phoneMap, digits, index + 1, combination);
            combination.pop_back();
        }
    }
    std::vector<std::string> letterCombination(std::string digits) {
        std::vector<std::string> combinations;
        if (digits.empty()) {
            return combination;
        }
        std::unordered_map<char, std::string> phoneMap {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        std::string combination;
        backtrack(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }
};