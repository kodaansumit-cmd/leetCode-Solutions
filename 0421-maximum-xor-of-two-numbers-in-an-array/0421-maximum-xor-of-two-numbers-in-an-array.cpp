class Solution {
public:
    struct Node {
        Node* child[2];

        Node() {
            child[0] = nullptr;
            child[1] = nullptr;
        }
    };

    void insert(Node* root, int num) {
        Node* curr = root;

        for (int b = 30; b >= 0; b--) {
            int bit = (num >> b) & 1;

            if (curr->child[bit] == nullptr)
                curr->child[bit] = new Node();

            curr = curr->child[bit];
        }
    }

    int findMaxXor(Node* root, int num) {
        Node* curr = root;
        int ans = 0;

        for (int b = 30; b >= 0; b--) {
            int bit = (num >> b) & 1;
            int opposite = 1 - bit;

            if (curr->child[opposite] != nullptr) {
                ans |= (1 << b);
                curr = curr->child[opposite];
            } else {
                curr = curr->child[bit];
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();

        for (int num : nums)
            insert(root, num);

        int answer = 0;

        for (int num : nums)
            answer = max(answer, findMaxXor(root, num));

        return answer;
    }
};