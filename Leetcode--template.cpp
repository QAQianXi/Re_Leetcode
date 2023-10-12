#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int indexLeft = 0,indexRight=nums.size();
        while (indexLeft < indexRight){
            int indexMid = indexLeft + (indexRight - indexLeft) / 2;
            if (nums[indexMid] == target){
                return indexMid;
            }else if (nums[indexMid] < target){
                indexLeft = indexMid + 1;
            }else if (nums[indexMid] > target){
                indexRight = indexMid ;
            }
        }
        for (int i = 0; i <nums.size() ; ++i) {
            if (nums[i] > target){
                return i;
            }
        }
        return int(nums.size());
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,3,5,6};
    int target = 2;
    cout << solution.searchInsert(nums,target);
    return 0;
}
