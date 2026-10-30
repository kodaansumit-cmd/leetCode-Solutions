class Solution {
public:
vector<int>prefix;
    vector<int> runningSum(vector<int>& nums) {
        prefix.resize(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        return prefix;
    }
};