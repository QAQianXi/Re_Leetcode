#include <iostream>
#include <vector>
using namespace std;

class Solution {    // TODO 2023/10/05 未完成--必须要需要动态规划方法
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 1){
            return 0;
        }
        vector<int> differencePrice(prices.size() - 1);
        vector<int> finalPrice(prices.size() - 1);
        int result = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            differencePrice[i] = (prices[i + 1] - prices[i]);
        }
        int q = 0;
        int temp = 0;
        while (q != differencePrice .size()){
            if (differencePrice[q] > 0){
                temp += differencePrice[q];
                if ((q == differencePrice.size() - 1 or differencePrice[q + 1] <= 0)){ // 说明不可继续赚
                    finalPrice.emplace_back(temp);
                    temp = 0;
                }
            }
            q++;
        }
        sort(finalPrice.rbegin(),finalPrice.rend());
        for (int i = 0; i < k; ++i) {
            result += finalPrice[i];
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {1,6,3,4,5,6};
    int k = 2;
    cout<<solution.maxProfit(k, prices);
    return 0;
}
