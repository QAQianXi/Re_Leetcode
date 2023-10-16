#include <iostream>
#include <vector>
#include<unordered_map>
#include<deque>
#include <set>

using namespace std;


//class Solution {
//public:
//    vector<int> avoidFlood(vector<int> &rains) {
//        unordered_map<int, int> recordPool;
//        deque<int> recordWater;
//        vector<int> result = {};
//        for (auto i: rains) {
//            if (i != 0) { //加水情况 判断是否有这个池子对应值+1，没有就创建
//                recordWater.push_back(i);
//                auto it = recordPool.find(i);
//                if (it != recordPool.end()) {
//                    recordPool[i] += 1;
//                    if ((recordPool[i]) >= 2) {//如果添加后大于2直接返回空
//                        return {};
//                    }
//                } else {
//                    recordPool[i] = 1;
//                }
//                result.emplace_back(-1);
//            } else {
//                if (!recordPool.empty() && !recordWater.empty()) {//有水的情况下才开始防水 否则默认为1
//
//                    for (auto it: recordPool) {//todo 先弹最近装水出现最多次数的池子
//
//                    }
//                    recordPool[recordWater.back()] = max(0, recordPool[recordWater.back()] -= 1);
//                    result.emplace_back(recordWater.back());
//                    recordWater.pop_back();
//                } else {
//                    result.emplace_back(1);
//                }
//            }
//        }
//
//        return result;
//    }
//};
class Solution {
public:
    vector<int> avoidFlood(vector<int> &rains) {
        vector<int> ans(rains.size(), 1);
        unordered_map<int, int> water;
        set<int> zero;

        for (int i = 0; i < rains.size(); i++) {
            int r = rains[i];
            if (r == 0) {
                zero.insert(i);
                continue;
            }
            if (water.count(r) != 0) {
                auto it = zero.lower_bound(water[r]);
                if (it == zero.end()) return {};
                ans[*it] = r;
                zero.erase(it);
            }
            water[r] = i;
            ans[i] = -1;
        }
        return ans;
    }
};
    int main() {
        Solution solution;
        vector<int> rains = {0, 1, 1};

        auto result = solution.avoidFlood(rains);
        for (auto it: result) {
            cout << it << ",";
        }
        return 0;
    }
