class Solution {
public:

    long long gcdSum(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefixGcd;

        int mx = 0;

       
        for (int i = 0; i < n; i++) {

            mx = max(mx, nums[i]);

            prefixGcd.push_back(gcd(nums[i], mx));
        }

       
        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;

        int left = 0;
        int right = n - 1;

        
        while (left < right) {

            ans += gcd(prefixGcd[left], prefixGcd[right]);

            left++;
            right--;
        }

        return ans;
    }
};