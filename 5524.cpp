#include <vector>

class Solution {
public:
    int minOperationsMaxProfit(std::vector<int>& customers, int boardingCost, int runningCost) {
        int maxStep = 0;
        int currentStep = 0;
        int waitings = 0;
        long totalIncome = 0;
        int maxIncome = 0;
        int i = 0;
        while (i < customers.size() || waitings > 0) {
            if (i < customers.size()) {
                waitings += customers[i];
            }
           
            currentStep++;
            int numberBordings = waitings >= 4 ? 4 : waitings;
            waitings -= numberBordings;
            int currentIncome = numberBordings * boardingCost - runningCost;
            totalIncome += currentIncome;
            if (totalIncome > maxIncome) {
                maxStep = currentStep;
                maxIncome = totalIncome;
            }
            
            i++;
        }
        return maxIncome > 0? maxStep: -1;
    }
};