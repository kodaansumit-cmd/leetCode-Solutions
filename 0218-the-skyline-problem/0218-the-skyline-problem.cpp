class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;

        for (auto& b : buildings) {
            events.push_back({b[0], -b[2]});
            events.push_back({b[1], b[2]});
        }
        sort(events.begin(), events.end());

        multiset<int> active;
        active.insert(0);

        vector<vector<int>> ans;
        int prevHeight = 0;

        int i = 0;
        int n = events.size();

        while (i < n) {
            int x = events[i].first;

            while (i < n && events[i].first == x) {
                int h = events[i].second;

                if (h < 0) {
                    active.insert(-h);
                } else {
                    active.erase(active.find(h));
                }
                i++;
            }
            int currHeight = *active.rbegin();

            if (currHeight != prevHeight) {
                ans.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }
        return ans;
    }
};