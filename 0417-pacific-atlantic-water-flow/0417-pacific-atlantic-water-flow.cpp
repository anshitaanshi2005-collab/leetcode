class Solution {
public:

    int m, n;

    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             int r, int c) {

        visited[r][c] = true;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                continue;
            }

            if (visited[nr][nc]) {
                continue;
            }

            // Reverse direction:
            // move from lower/equal height to higher/equal height
            if (heights[nr][nc] >= heights[r][c]) {
                dfs(heights, visited, nr, nc);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific: top row and left column
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);
        }

        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j);
        }

        // Atlantic: bottom row and right column
        for (int i = 0; i < m; i++) {
            dfs(heights, atlantic, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(heights, atlantic, m - 1, j);
        }

        vector<vector<int>> result;

        // Cell must be reachable from both oceans
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};