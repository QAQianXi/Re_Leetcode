#include <iostream>
#include <vector>

using namespace std;


class Solution2 {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int right = searchRight(nums, target);
        int left = searchLeft(nums, target);
        if (right == -2 || left == -2) return {-1, -1};
        if (right - left > 1) return {left + 1, right - 1};
        return {-1, -1};
    }

private:
    int searchRight(vector<int> &nums, int target) {
        int left = 0, right = int(nums.size() - 1), mid, rightBorder = -2;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
                rightBorder = left;
            } else {
                right = mid - 1;
            }
        }
        return rightBorder;
    }

    int searchLeft(vector<int> &nums, int target) {
        int left = 0, right = int(nums.size() - 1), mid, leftBorder = -2;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
                leftBorder = right;
            } else {
                left = mid + 1;
            }
        }
        return leftBorder;
    }
};


class Solution3 {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int right = searchRight(nums, target);
        int left = searchLeft(nums, target);
        if (right == -2 || left == -2) return {-1, -1};
        if (right - left > 1) return {left + 1, right - 1};
        return {-1, -1};
    }

private:
    int searchRight(vector<int> &nums, int target) {
        int left = 0, right = int(nums.size() - 1), mid, rightBorder = -2;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
                rightBorder = left;
            } else {
                right = mid - 1;
            }
        }
        return rightBorder;
    }

    int searchLeft(vector<int> &nums, int target) {
        int left = 0, right = int(nums.size() - 1), mid, leftBorder = -2;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
                leftBorder = right;
            } else {
                left = mid + 1;
            }
        }
        return leftBorder;
    }
};


int main() {
    Solution3 solution;
    vector<int> nums = {5, 7, 7, 8, 10};
    int target = 7;
    auto result = solution.searchRange(nums, target);
    for (auto i: result) {
        cout << i << " ";
    }
    return 0;
}