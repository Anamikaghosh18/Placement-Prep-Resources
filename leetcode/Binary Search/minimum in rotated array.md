
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int low = 0 ; 
        int high = n-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            // left sorted 
            if(nums[low] <= nums[mid]){
                mini = min(nums[low], mini);
                low = mid+ 1;

            } // right sorted 
            else{
                mini = min(nums[mid], mini);
                high = mid - 1;
            }
        }
        return mini;    
            
        
    }
};
