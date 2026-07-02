class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> mp(128, 0);

        
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }

        int start = 0, end = 0;
        int total = t.size();     
        int ans = INT_MAX;
        int index = -1;

        while (end < s.size()) {

           
            mp[s[end]]--;

            
            if (mp[s[end]] >= 0)
                total--;

            
            while (total == 0) {

                
                if (ans > end - start + 1) {
                    ans = end - start + 1;
                    index = start;
                }

                
                mp[s[start]]++;

                
                if (mp[s[start]] > 0)
                    total++;

                start++;
            }

            end++;
        }

        if (index == -1)
            return "";

        return s.substr(index, ans);
    }
};