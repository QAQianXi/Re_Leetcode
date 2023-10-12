#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int countEarn = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (prices[i + 1] > prices[i]){
                countEarn += prices[i + 1] - prices[i];
            }
        }
        return countEarn;
    }
};

int main() {
    Solution solution;
    int target = 9;
    vector<int> prices = {1, 2, 3, 4, 5};
    cout << solution.maxProfit(prices);
    return 0;
}
