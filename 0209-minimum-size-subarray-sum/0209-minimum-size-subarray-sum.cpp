class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int start = 0;
        int end = 0;

        int sum = 0;
        int ans = INT_MAX;

        while(end < nums.size())
        {
            sum += nums[end];

            while(sum >= target)
            {
                ans = min(ans, end - start + 1);

                sum -= nums[start];
                start++;
            }

            end++;
        }

        if(ans == INT_MAX)
            return 0;

        return ans;
    }
};