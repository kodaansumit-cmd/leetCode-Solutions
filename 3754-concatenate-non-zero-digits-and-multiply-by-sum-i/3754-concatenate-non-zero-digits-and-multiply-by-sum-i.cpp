class Solution {
public:
    long long sumAndMultiply(int n) {

        string s = to_string(n);

        long long x = 0;
        int sum = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != '0')
            {
                x = x * 10 + (s[i] - '0');
                sum = sum + (s[i] - '0');
            }
        }

        return x * sum;
    }
};