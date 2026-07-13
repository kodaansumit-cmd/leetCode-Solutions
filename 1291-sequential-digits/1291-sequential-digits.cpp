class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        string s = "123456789";

        vector<int> ans;

        int lowLength = to_string(low).size();
        int highLength = to_string(high).size();

        for (int len = lowLength; len <= highLength; len++) {

            for (int i = 0; i + len <= 9; i++) {

                string temp = s.substr(i, len);

                int num = stoi(temp);

                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};