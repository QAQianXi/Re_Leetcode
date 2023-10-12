#include <iostream>
#include <vector>
using namespace std;

class StockSpanner {
public:
    vector<int> recordPrices;
    StockSpanner() = default;

    int next(int price) {
        int countLessDay = 0;
        recordPrices.emplace_back(price);
        for (auto it = recordPrices.rbegin(); it != recordPrices.rend(); ++it) {
            if (*it <= price){
                ++countLessDay;
            } else {
                break;
            }
        }
        return countLessDay;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {
    StockSpanner stockSpanner = *new StockSpanner();
    cout<<stockSpanner.next(32); // 返回 1
    cout<<stockSpanner.next(82);  // 返回 1
    cout<<stockSpanner.next(73);  // 返回 1
    cout<<stockSpanner.next(99);  // 返回 2
    cout<<stockSpanner.next(91);  // 返回 1
}
