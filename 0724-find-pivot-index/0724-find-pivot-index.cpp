class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix;
    
        prefix.resize(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
        prefix[i]=prefix[i-1]+nums[i];
    }
    int total = prefix[nums.size() - 1];
int leftSum = 0;

for(int i = 0; i < nums.size(); i++) {

    int rightSum = total - leftSum - nums[i];

    if(leftSum == rightSum) {
        return i;
    }

    leftSum += nums[i];
}

return -1;

    }
};