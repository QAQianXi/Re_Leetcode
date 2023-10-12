#include <iostream>
#include <vector>
using namespace std;
/* Python 投机取巧o.O
 * def removeDuplicates(self, nums: List[int]) -> int:
        new_tup=sorted(list(set(nums)))
        k=len(new_tup)
        nums.clear()
        for i in new_tup:
            nums.append(i)
        return k
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[slowIndex] == nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;



        }
};


int main() {
    Solution solution;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << solution.removeDuplicates(nums);
    for (auto i : nums) {
        cout << i;

    }
    return 0;
}
