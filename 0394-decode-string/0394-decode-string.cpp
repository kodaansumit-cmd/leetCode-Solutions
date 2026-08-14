class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> st;

        int num = 0;
        string curr = "";
        for (char ch : s) {
            if (isdigit(ch)) {

                num = num * 10 + (ch - '0');
            }
            else if (ch == '[') {
                st.push({num, curr});
                num = 0;
                curr = "";
            }
            else if (ch == ']') {
                int repeat = st.top().first;
                string previous = st.top().second;

                st.pop();
                string temp = "";

                for (int i = 0; i < repeat; i++) {
                    temp += curr;
                }
                curr = previous + temp;
            }
            else {
                curr += ch;
            }
        }
        return curr;
    }
};