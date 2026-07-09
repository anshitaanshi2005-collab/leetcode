class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<bool>>& visited) {

        visited[r][c] = true;

        for (auto &dir : directions) {

            int nr = r + dir[0];
            int nc = c + dir[1];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if (visited[nr][nc])
                continue;

            // Reverse flow
            if (heights[nr][nc] < heights[r][c])
                continue;

            dfs(nr, nc, heights, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific
        for (int i = 0; i < m; i++)
            dfs(i, 0, heights, pacific);

        for (int j = 0; j < n; j++)
            dfs(0, j, heights, pacific);

        // Atlantic
        for (int i = 0; i < m; i++)
            dfs(i, n - 1, heights, atlantic);

        for (int j = 0; j < n; j++)
            dfs(m - 1, j, heights, atlantic);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};