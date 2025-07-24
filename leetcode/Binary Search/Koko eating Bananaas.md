- when changing the ceil value keep in either take value in double or long long otherwise in case of 
integer it will return only the integer value only....

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxElement(piles); 
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totaltime = timeTaken(piles, mid);

            if (totaltime <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    long long timeTaken(vector<int>& piles, int mid) {
        long long total = 0; 
        for (int i = 0; i < piles.size(); i++) {
            total += (piles[i] + mid - 1) / mid; 
        }
        return total;
    }

    int maxElement(vector<int>& piles) {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(piles[i], maxi);
        }
        return maxi;
    }
};