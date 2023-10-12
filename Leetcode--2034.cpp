#include <iostream>
#include <vector>
#include <map>
#include <hash_map>
#include <set>
using namespace std;

class StockPrice0 {
private:
    int currentTime;
    int maxPrice;
    int maxTime;
    int minPrice;
    int minTime;
    map<int, int> recordPrice;
public:
    StockPrice() {
        recordPrice = {};
        currentTime = -1;
        maxPrice = -1;
        maxTime = -1;
        minTime = -1;
        minPrice = INT_MAX;
    }

    void update(int timestamp, int price) {
        auto it = recordPrice.find(timestamp);
        if (it == recordPrice.end()) { // 未找到值的情况下进行添加
            recordPrice.insert(pair(timestamp, price));
            if (price < minPrice) {
                minPrice = price;
                minTime = timestamp;
            }
            if (price > maxPrice) {
                maxPrice = price;
                maxTime = timestamp;
            }
        } else {   // 找到对应值的情况则进行最大最小值的判断
            it->second = price;
            if (maxTime == minTime) {
                maxPrice = price;
                minPrice = price;
            }
            else if (it->first == maxTime) {   // 和最大值的时间戳相同：值更大则替换最大值，值更小则重新搜索一遍
                    if (price >= maxPrice) {
                        maxPrice = price;
                    } else {
                        if (price < minPrice) {
                            minPrice = price;
                            minTime = it->first;
                        }
                        maxPrice = -1;
                        for (auto &i: recordPrice) {
                            if (i.second > maxPrice) {
                                maxPrice = i.second;
                                maxTime = i.first;
                            }
                        }
                    }
                }
            else if (it->first == minTime) {   // 同上进行一次最小值的判断
                    if (price <= minPrice) {
                        minPrice = price;
                    } else {
                        if (price > maxPrice) {
                            maxPrice = price;
                            maxTime = it->first;
                        }
                        minPrice = INT_MAX;
                        for (auto &i: recordPrice) {
                            if (i.second < minPrice) {
                                minPrice = i.second;
                                minTime = i.first;
                            }
                        }
                    }
                }
            else{
            if (price < minPrice) {
                minPrice = price;
                minTime = timestamp;
            }
            if (price > maxPrice) {
                maxPrice = price;
                maxTime = timestamp;
            }}

        }
        if (currentTime < timestamp) {
            currentTime = timestamp;
        }
    }

    int current() {
        return recordPrice[currentTime];
    }

    int maximum() {
        return maxPrice;
    }

    int minimum() {
        return minPrice;
    }



};
class StockPrice {
public:
    StockPrice() {
        this->maxTimestamp = 0;
    }

    void update(int timestamp, int price) {
        maxTimestamp = max(maxTimestamp, timestamp);
        int prevPrice = timePriceMap.count(timestamp) ? timePriceMap[timestamp] : 0;
        timePriceMap[timestamp] = price;
        if (prevPrice > 0) {
            auto it = prices.find(prevPrice);
            if (it != prices.end()) { //找到删除原来的价格
                prices.erase(it);
            }
        }
        prices.emplace(price);
    }

    int current() {
        return timePriceMap[maxTimestamp];
    }

    int maximum() {
        return *prices.rbegin();
    }

    int minimum() {
        return *prices.begin();
    }
private:
    int maxTimestamp;
    unordered_map<int, int> timePriceMap;
    multiset<int> prices;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {
    StockPrice stockPrice = *new StockPrice();
    stockPrice.update(765, 3848);
    cout << stockPrice.current() << "  ";
    cout << stockPrice.current() << "  ";
    stockPrice.update(765, 8511);
    stockPrice.update(853, 6124);
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.minimum() << "  ";
    stockPrice.update(765, 5733);
    cout << stockPrice.current() << "  ";
    cout << stockPrice.maximum() << "  ";
    stockPrice.update(832, 5725);
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.maximum() << "  ";
    stockPrice.update(799, 1311);
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.minimum() << "  ";
    stockPrice.update(793, 4708);
    stockPrice.update(849, 9940);
    cout << stockPrice.maximum() << "  ";
    stockPrice.update(757, 3154);
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.maximum() << "  ";
    stockPrice.update(847, 9940);
    stockPrice.update(834, 6830);
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.current() << "  ";
    stockPrice.update(820, 2754);
    cout << stockPrice.current() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.minimum() << "  ";
    stockPrice.update(826, 3783);
    cout << stockPrice.minimum() << "  ";
    stockPrice.update(794, 7551);
    cout << stockPrice.maximum() << "  ";
    stockPrice.update(837, 3666);
    stockPrice.update(834, 7067);
    stockPrice.update(779, 2754);
    stockPrice.update(832, 7551);
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.minimum() << "  ";
    stockPrice.update(839, 982);
    cout << stockPrice.current() << "  ";
    stockPrice.update(839, 1283);
    stockPrice.update(836, 3960);
    stockPrice.update(846, 7223);
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.current() << "  ";
    stockPrice.update(776, 4337);
    cout << stockPrice.current() << "  ";
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.maximum() << "  ";
    stockPrice.update(827, 6830);
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.maximum() << "  ";
    stockPrice.update(820, 7223);
    cout << stockPrice.current() << "  ";
    stockPrice.update(765, 9265);
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.minimum() << "  ";
    stockPrice.update(826, 1987);
    cout << stockPrice.minimum() << "  ";
    stockPrice.update(771, 2494);
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.maximum() << "  ";
    stockPrice.update(811, 3154);
    cout << stockPrice.current() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.maximum() << "  ";
    stockPrice.update(848, 7223);
    cout << stockPrice.current() << "  ";
    cout << stockPrice.maximum() << "  ";
    stockPrice.update(794, 839);
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.current() << "  ";
    stockPrice.update(758, 1283);
    cout << stockPrice.minimum() << "  ";
    stockPrice.update(794, 2206);
    cout << stockPrice.maximum() << "  ";
    stockPrice.update(758, 1204);
    stockPrice.update(820, 3259);
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.current() << "  ";
    stockPrice.update(854, 1379);
    stockPrice.update(842, 3848);
    cout << stockPrice.maximum() << "  ";
    stockPrice.update(803, 1461);
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.current() << "  ";
    stockPrice.update(846, 1310);
    cout << stockPrice.current() << "  ";
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.maximum() << "  ";
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.current() << "  ";
    cout << stockPrice.minimum() << "  ";
    stockPrice.update(779, 1556);
    cout << stockPrice.minimum() << "  ";
    cout << stockPrice.current() << "  ";
}