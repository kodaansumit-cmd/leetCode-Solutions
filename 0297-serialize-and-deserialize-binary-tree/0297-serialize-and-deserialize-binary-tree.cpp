/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "null,";
        }
        string s= to_string(root->val)+",";
        s+=serialize(root->left);
        s+=serialize(root->right);
        return s;
    }
    TreeNode* solve(vector<string>&v,int &i){
        if(v[i]=="null"){
            i++;
            return NULL;
        }
   
    TreeNode* root=new TreeNode(stoi(v[i]));
    i++;

    root->left=solve(v,i);
    root->right=solve(v,i);
    return root;
}

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>v;
        stringstream ss(data);
        string word;

        while (getline(ss,word,',')){
            v.push_back(word);
        }
        int i=0;
        return solve(v,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));