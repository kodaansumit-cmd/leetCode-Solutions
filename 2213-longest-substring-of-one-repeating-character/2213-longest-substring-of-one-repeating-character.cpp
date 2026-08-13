class Solution {
public:
    struct Node {
        char leftChar;   
        char rightChar;  

        int prefix;      
        int suffix;      
        int best;       
        int len;       
    };

    vector<Node> seg;

    Node merge(Node L, Node R) {

        Node P;

        P.len = L.len + R.len;

        P.leftChar = L.leftChar;
        P.rightChar = R.rightChar;

        P.best = max(L.best, R.best);
        P.prefix = L.prefix;
        P.suffix = R.suffix;
        if (L.rightChar == R.leftChar) {
            P.best = max(P.best, L.suffix + R.prefix);
            if (L.prefix == L.len) {
                P.prefix = L.len + R.prefix;
            }
            if (R.suffix == R.len) {
                P.suffix = R.len + L.suffix;
            }
        }

        return P;
    }
    void build(string &s, int index, int low, int high) {
        if (low == high) {

    seg[index].leftChar = s[low];
            seg[index].rightChar = s[low];

            seg[index].prefix = 1;
            seg[index].suffix = 1;
            seg[index].best = 1;

            seg[index].len = 1;

            return;
        }

 int mid = low + (high - low) / 2;
        build(s, 2 * index, low, mid);
        build(s, 2 * index + 1, mid + 1, high);

        seg[index] = merge(
            seg[2 * index],
            seg[2 * index + 1]
        );
    }

    void update(int index, int low, int high,
                int pos, char ch) {

        if (low == high) {

            seg[index].leftChar = ch;
            seg[index].rightChar = ch;

            seg[index].prefix = 1;
            seg[index].suffix = 1;
            seg[index].best = 1;

            return;
        }
int mid = low + (high - low) / 2;
        if (pos <= mid) {
update(2 * index,low,mid,pos,ch );
        }
        else {

            update( 2 * index + 1, mid + 1, high, pos, ch);
        }
        seg[index] = merge(
            seg[2 * index],
            seg[2 * index + 1]
        );
    }
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();
        seg.resize(4 * n);
        build(s, 1, 0, n - 1);
        vector<int> ans;
        for (int i = 0; i < queryIndices.size(); i++) {

            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            update(1,0,n - 1,pos,ch);
            ans.push_back(seg[1].best);
        }
        return ans;
    }
};