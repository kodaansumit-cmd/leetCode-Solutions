class Solution {
public:
    bool canSplit(vector<int>& nums, int k,  long long maxsum ) {
       long long currentsum=0;
       int subarrays=1;
        for (int num : nums) {
    
           if(currentsum+num>maxsum){
            subarrays++;
            currentsum=0;
           }

           currentsum+=num;
        }
        return subarrays<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(),nums.end());
        long long high = accumulate(nums.begin(), nums.end(),0);

        while (low < high) {
        long long mid = low + (high - low) / 2;

            if (canSplit(nums,k, mid)) {

                high = mid;
            }
            else {

                low = mid + 1;
            }
        }

        return low;
    }
};
       
   