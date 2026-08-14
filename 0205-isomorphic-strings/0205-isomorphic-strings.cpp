class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        vector<int> mapST(256, -1);

        vector<int> mapTS(256, -1);

        for (int i = 0; i < s.length(); i++) {

            char ch1 = s[i];
            char ch2 = t[i];

            if (mapST[ch1] != -1) {
                if (mapST[ch1] != ch2)
                    return false;
            }

            else {
                mapST[ch1] = ch2;
            }
            if (mapTS[ch2] != -1) {

                if (mapTS[ch2] != ch1)
                    return false;
            }
            else {
                mapTS[ch2] = ch1;
            }
        }
        return true;
    }
};