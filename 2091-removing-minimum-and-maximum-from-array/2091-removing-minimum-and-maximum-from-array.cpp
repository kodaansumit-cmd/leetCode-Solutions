class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
       int n =nums.size() ;
       int maxindex=0;
       int minindex=0;
       for(int i=0;i<n;i++){
        if(nums[i]<nums[minindex])
        minindex=i;

        if(nums[i]>nums[maxindex])
        maxindex=i;
 }

 int left=max(minindex,maxindex)+1;

 int right=n-min(minindex,maxindex);

 int both=min(minindex,maxindex)+1 +n-max(maxindex,minindex);

 return min({left,right,both});
    }
};