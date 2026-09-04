class Solution {
public:
bool canMake(vector<int>& flowers, int m, int k,int days) {
        int count=0;
        int bouqets=0;
        for (int flower : flowers) {
           if(flower<=days){
            count++;

            if(count==k){
                bouqets++;
                count=0;
            }
           }
           else{
            count=0;
           }
        }
        return bouqets>=m;
}

int minDays(vector<int>& bloomDay, int m, int k) {

    if((long long)m*k>bloomDay.size())
    return -1;

        int low = 1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, m,k, mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};


