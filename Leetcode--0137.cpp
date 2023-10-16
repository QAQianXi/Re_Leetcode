#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution { // 暴力解法 hashmap
public:
    vector<int> singleNumber(vector<int> &nums) {
        unordered_map<int, int> recordNums;
        vector<int> result{};
        for (int num: nums) {
            auto it = recordNums.find(num);
            if (it == recordNums.end()) {
                recordNums[num] = 1;
            } else {
                recordNums[num] += 1;
            }
        }
        for (auto i: recordNums) {
            if (i.second == 1) {
                result.emplace_back(i.first);
            }
        }
        return result;

    }
};

class Solution2 { // 暴力解法改进
public:
    vector<int> singleNumber(vector<int> &nums) {
        unordered_map<int, int> recordNums;
        vector<int> result{};
        for (int num: nums) {
            auto it = recordNums.find(num);
            if (it == recordNums.end()) {
                recordNums[num] = 1;
            } else {
                recordNums.erase(num);
            }
        }
        for (auto i: recordNums) {
            result.emplace_back(i.first);
        }
        return result;
    }
};

int main() {    // 137. 只出现一次的数字 II https://leetcode.cn/problems/single-number-ii/
    Solution solution2;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    for (auto i: solution2.singleNumber(nums)) {
        cout << i << " ";
    }
    return 0;
}
