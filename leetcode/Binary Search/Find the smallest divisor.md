- there is a pattern in answer so we will apply binary search on answer....


```c++
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1 ; int high = maxElement(nums); 
        int ans = INT_MAX;

        while(low <= high){
            int mid = low + (high - low) / 2; 
            int minDivisor = func(nums, mid);
            if(minDivisor <= threshold){
                ans = mid ; 
                high = mid -1;
            }else{
                low = mid +1 ;
            }

        }
        return ans;
    }
    int func(vector<int>& nums , int mid){
        int total = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            total += ceil((double)nums[i]/mid);
        }
        return total;
    }

    int maxElement(vector<int>&nums){
        int maxi = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            maxi = max(nums[i], maxi);
        }
        return maxi;
    }
};
```