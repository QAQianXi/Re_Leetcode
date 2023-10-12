#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int indexLeft = 0, indexRight = x, indexMid, result;
        while (indexLeft <= indexRight){
            indexMid = indexLeft + (indexRight - indexLeft) / 2;
            if ((long long)indexMid * indexMid > x){
                indexRight = indexMid - 1;
            }else {
                result = indexMid;
                indexLeft = indexMid + 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    int target = 8;
    cout<<solution.mySqrt(target);
    return 0;
}
