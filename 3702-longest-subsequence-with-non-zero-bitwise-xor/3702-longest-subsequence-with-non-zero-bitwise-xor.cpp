class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xr=0;
        bool zero=false;
        for(int num:nums){
            xr=xr^num;
            if(num!=0){
                zero=true;
            }
        }
        if(xr!=0){
            return n;
        }
        if(zero==false){
            return 0;
        }
        return n-1;
    }
};