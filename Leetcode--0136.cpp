#include <iostream>
#include <vector>

using namespace std;
/* Python 计数器？
 * class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        freq = collections.Counter(nums)
        ans = [num for num, occ in freq.items() if occ == 1][0]
        return ans
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int total = 0;
            for (int num: nums) {
                total += ((num >> i) & 1);
            }
            if (total % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {0,1,0,1,0,1,99};
    cout << solution.singleNumber(nums);
    return 0;
}
