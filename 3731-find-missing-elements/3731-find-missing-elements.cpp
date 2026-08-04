class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       unordered_set<int>st;

       int mini=INT_MAX;
         int maxi=INT_MIN;

         for(int num:nums){
            st.insert(num);

            mini=min(num,mini);
            maxi=max(num,maxi);
         }
         vector<int> ans;

         for(int i=mini+1;i<maxi;i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }
         }
         return ans;
    }
};