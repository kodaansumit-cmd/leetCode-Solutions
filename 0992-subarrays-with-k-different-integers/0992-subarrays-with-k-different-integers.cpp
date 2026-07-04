class Solution {
public:

    int solve(vector<int>& nums, int k)
    {
        unordered_map<int, int> mp;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            mp[nums[right]]++;

            while (mp.size() > k)
            {
                mp[nums[left]]--;

                if (mp[nums[left]] == 0)
                    mp.erase(nums[left]);

                left++;
            }

            ans += (right - left + 1);
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k)
    {
        return solve(nums, k) - solve(nums, k - 1);
    }
};