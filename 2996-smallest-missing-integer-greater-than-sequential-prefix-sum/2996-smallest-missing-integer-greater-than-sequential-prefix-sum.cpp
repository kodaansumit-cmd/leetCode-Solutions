class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        int i=1;
        while(i<n&& nums[i]==nums[i-1]+1){
            sum+=nums[i];
            i++;
        }
        int ans=sum;

        unordered_set<int>st(nums.begin(),nums.end());
        while(st.count(ans)){
            ans++;
        }
        return ans;
    }
};