class Solution {
public:
    struct Node {
        int prod = 1;
        int pref[5] = {0, 0, 0, 0, 0};
    };

    int k;
    vector<Node> tree;

    Node mergeNode(const Node& a, const Node& b) {
        Node res;

        res.prod = (1LL * a.prod * b.prod) % k;

        for (int r = 0; r < k; r++) {
            res.pref[r] += a.pref[r];

            int nr = (1LL * a.prod * r) % k;
            res.pref[nr] += b.pref[r];
        }

        return res;
    }

    vector<int> resultArray(vector<int>& nums, int K,
                            vector<vector<int>>& queries) {
        k = K;

        int n = nums.size();
        int size = 1;

        while (size < n)
            size <<= 1;

        tree.resize(2 * size);

        for (int i = 0; i < n; i++) {
            int rem = nums[i] % k;

            tree[size + i].prod = rem;
            tree[size + i].pref[rem] = 1;
        }

        for (int i = size - 1; i >= 1; i--) {
            tree[i] = mergeNode(tree[2 * i], tree[2 * i + 1]);
        }

        auto update = [&](int pos, int value) {
            int p = size + pos;

            tree[p] = Node();

            int rem = value % k;
            tree[p].prod = rem;
            tree[p].pref[rem] = 1;

            p /= 2;

            while (p >= 1) {
                tree[p] = mergeNode(tree[2 * p], tree[2 * p + 1]);
                p /= 2;
            }
        };

        auto query = [&](int l) {
            int left = l + size;
            int right = n + size;

            Node leftRes;
            Node rightRes;

            while (left < right) {
                if (left & 1) {
                    leftRes = mergeNode(leftRes, tree[left]);
                    left++;
                }

                if (right & 1) {
                    --right;
                    rightRes = mergeNode(tree[right], rightRes);
                }

                left /= 2;
                right /= 2;
            }

            return mergeNode(leftRes, rightRes);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(index, value);

            Node res = query(start);

            ans.push_back(res.pref[x]);
        }

        return ans;
    }
};