#include <iostream>
#include <vector>
using namespace std;
/* Python 字符串排序
 * class Solution:
    def groupAnagrams(self, strs: List[str])    :
        sortedStrs = collections.defaultdict(list)
        for str in strs:
            # for char in strSingleChar:
            #     sortedStr += char
            sortedStr = "".join(sorted(list(str)))
            # 判断是否相同，如果相同则加入，不相同则新开一个字典
            sortedStrs[sortedStr].append(str)
        return list(sortedStrs.values())
 */
class Solution { // TODO 2023/10/17 Python已过 缺少C++写法
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,3,5,6};
    int target = 2;
    cout << solution.searchInsert(nums,target);
    return 0;
}
