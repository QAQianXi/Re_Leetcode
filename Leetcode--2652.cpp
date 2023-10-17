#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOfMultiples(int n) {
        return sumOfSingle(n, 3) + sumOfSingle(n, 5) + sumOfSingle(n, 7) - sumOfSingle(n, 15) - sumOfSingle(n, 21) - sumOfSingle(n, 35) + sumOfSingle(n, 105);
    }
private:
    int sumOfSingle(int n,int m){
        return n / m * (n / m + 1) / 2 * m;
    }
};

int main() {    // 2652. 倍数求和
    Solution solution;
    int nums = 7;
    cout << solution.sumOfMultiples(nums);
    return 0;
}
