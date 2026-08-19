class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> mp;

        for (auto seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }
        int ans = (n - mp.size()) * 2;

        for (auto row : mp) {

            int r = row.first;
            set<int> seats = row.second;
            bool left = true;
            for (int s = 2; s <= 5; s++) {
                if (seats.count(s)) {
                    left = false;
                    break;
                }
            }
            bool right = true;
            for (int s = 6; s <= 9; s++) {
                if (seats.count(s)) {
                    right = false;
                    break;
                }
            }
            if (left && right) {
                ans += 2;
            }
            else {
                bool middle = true;

                for (int s = 4; s <= 7; s++) {
                    if (seats.count(s)) {
                        middle = false;
                        break;
                    }
                }

                if (left || right || middle) {
                    ans += 1;
                }
            }
        }

        return ans;
    }
};