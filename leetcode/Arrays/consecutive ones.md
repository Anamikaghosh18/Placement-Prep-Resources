```c++
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int cout = 0;
        for(int i = 0 ; i < nums.size() ;i++ ){
            if(nums[i] == 1){
                cout += 1;
                maxi = max(cout, maxi); 
            }else{
                cout = 0;
            }
        }
        return maxi;
        
    }
};
```