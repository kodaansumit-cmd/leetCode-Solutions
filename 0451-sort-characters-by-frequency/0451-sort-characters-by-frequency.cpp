class Solution {
public:
    string frequencySort(string s) {
 map<char, int> mp;
        for(char ch : s) {
            mp[ch]++;
        }
        vector<pair<char, int>> v;

        for(auto x : mp) {
            v.push_back(x);
        }
        for(int i = 0; i < v.size(); i++) {
            for(int j = i + 1; j < v.size(); j++) {

                if(v[i].second < v[j].second) {
                    swap(v[i], v[j]);
                }
            }
        }

        string ans = "";
        for(auto x : v) {

            for(int i = 0; i < x.second; i++) {
                ans += x.first;
            }
        }

        return ans;
    }
};