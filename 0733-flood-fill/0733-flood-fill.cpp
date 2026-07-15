class Solution {
public:
    int m, n;
    int originalColor;
    vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    void dfs(vector<vector<int>>& image, int r, int c, int newColor) {
        image[r][c] = newColor;

        for (auto &dir : directions) {
            int nr = r + dir.first;
            int nc = c + dir.second;

            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                image[nr][nc] == originalColor) {
                dfs(image, nr, nc, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();

        originalColor = image[sr][sc];

        // No change needed
        if (originalColor == color)
            return image;

        dfs(image, sr, sc, color);

        return image;
    }
};