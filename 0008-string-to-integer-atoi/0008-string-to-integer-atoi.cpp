class Solution {
public:
    int myAtoi(string s) {

        int n = s.length();
        int i = 0;
        while (i < n && s[i] == ' ') {
            i++;
        }
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            sign = 1;
            i++;
        }
        long long num = 0;
        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';
            if (num > INT_MAX / 10 ||
                (num == INT_MAX / 10 && digit > 7)) {
                if (sign == 1)
                    return INT_MAX;
                return INT_MIN;
            }
            num = num * 10 + digit;

            i++;
        }
        num = num * sign;
return (int)num;
    }
};