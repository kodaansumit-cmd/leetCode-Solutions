class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        vector<vector<int>> id(n, vector<int>(m, -1));

        int trashCount = 0;
        int sr = 0, sc = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = trashCount++;
                }
            }
        }

        if (trashCount == 0) return 0;

        int fullMask = (1 << trashCount) - 1;

        queue<array<int, 5>> q;
        q.push({sr, sc, energy, 0, 0});

        vector<vector<vector<vector<bool>>>> visited(
            n,
            vector<vector<vector<bool>>>(
                m,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << trashCount, false)
                )
            )
        );

        visited[sr][sc][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, e, mask, moves] = q.front();
            q.pop();

            if (mask == fullMask) return moves;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                if (classroom[nr][nc] == 'X')
                    continue;

                if (e == 0)
                    continue;

                int ne = e - 1;

                if (classroom[nr][nc] == 'R')
                    ne = energy;

                int nmask = mask;

                if (classroom[nr][nc] == 'L') {
                    int trashId = id[nr][nc];
                    nmask |= (1 << trashId);
                }

                if (!visited[nr][nc][ne][nmask]) {
                    visited[nr][nc][ne][nmask] = true;

                    q.push({
                        nr,
                        nc,
                        ne,
                        nmask,
                        moves + 1
                    });
                }
            }
        }

        return -1;
    }
};