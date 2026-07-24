class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
sort(intervals.begin(), intervals.end());

     vector<vector<int>> ans;

 ans.push_back(intervals[0]);

        
        for (int i = 1; i < intervals.size(); i++) {

          
            int start = intervals[i][0];
            int end = intervals[i][1];

            
            int lastEnd = ans.back()[1];

            
            if (start <= lastEnd) {

                ans.back()[1] = max(lastEnd, end);
            }
            else {
                
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};