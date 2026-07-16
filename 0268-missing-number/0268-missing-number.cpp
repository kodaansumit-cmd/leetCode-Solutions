class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n=nums.size();
       int totalsum=n*(n+1)/2;
       int current=0;
       for(int x:nums) {
        current+=x;
       }
       return totalsum-current;
    }
};