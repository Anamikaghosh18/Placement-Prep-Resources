```c++
class Solution {
public:
    bool check(vector<int>& nums) {
        for(int i = 0 ; i < nums.size()-1 ; i++){
            
            if(nums[i] < nums[i+1]){

            }
            else{
                return  false;
            }
        }
        return true;
    }
    
};
```


