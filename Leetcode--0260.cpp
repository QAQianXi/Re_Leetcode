#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,3,5,6};
    int target = 2;
    cout << solution.searchInsert(nums,target);
    return 0;
}
