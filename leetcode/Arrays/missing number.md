```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * (n+1))/ 2;
        int sum2 = 0;
        for(int i = 0 ; i < nums.size(); i++){
            sum2+= nums[i];
        }
        int missing = sum - sum2;
        return missing ;
    }
};
```
