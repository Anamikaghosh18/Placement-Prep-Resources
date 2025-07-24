```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerbound(nums,target);
        int ub = upperbound(nums, target);
        int size = nums.size();

        if (lb == size || nums[lb] != target) {
            return {-1, -1};
        }
        return {lb, ub - 1};
    }

    int lowerbound(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    int upperbound(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
```
