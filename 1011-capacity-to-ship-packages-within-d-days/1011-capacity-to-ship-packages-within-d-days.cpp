class Solution {
public:
    bool canCarry(vector<int>& weights, int days, int k) {
       int currentweight=0;
       int useddays=1;
        for (int weight : weights) {
    
           if(currentweight+weight>k){
            useddays++;
            currentweight=0;
           }

           currentweight+=weight;
        }
        return useddays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canCarry(weights, days, mid)) {

                high = mid;
            }
            else {

                low = mid + 1;
            }
        }

        return low;
    }
};
    