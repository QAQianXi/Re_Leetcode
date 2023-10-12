#include <iostream>
#include <vector>
using namespace std;
/* Python AC代码
 * class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        recordQueue = deque(nums)
        countNums = 0
        while len(recordQueue) >= 2:
            countNums += int(str(recordQueue.popleft())+str(recordQueue.pop()))
        if len(recordQueue) != 0:
            countNums += recordQueue.pop()
        return countNums
 */
class Solution {    // TODO 2023/10/12 Python已过 缺少C++写法
public:
    long long findTheArrayConcVal(vector<int>& nums) {

    }
};

int main() {
    Solution solution;
    vector<int> nums = {7,52,2,4};  // 输出：596
    cout << solution.findTheArrayConcVal(nums);
    return 0;
}
