class Solution {
public:
    set<string> st;
    string s;
    int i;
    set<string> parseExpression() {
        set<string> result;
        
        while (i < s.size() && s[i] != '}') {
            if (s[i] == ',') {
                i++;
                continue;
            }

            set<string> cur = parseTerm();

            result.insert(cur.begin(), cur.end());
        }

        return result;
    }
    set<string> parseTerm() {
        set<string> result = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur;

            if (s[i] == '{') {
                i++;  

                cur = parseExpression();

                i++; 
            }
            else {
                cur.insert(string(1, s[i]));
                i++;
            }
            set<string> temp;

            for (auto &a : result) {
                for (auto &b : cur) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> ans = parseExpression();

        return vector<string>(ans.begin(), ans.end());
    }
};