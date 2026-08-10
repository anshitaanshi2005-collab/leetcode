class Solution {
public:

    vector<vector<string>> ans;
    vector<string> board;

    bool isSafe(int row, int col, int n) {

        // check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // check upper-left diagonal
        int i = row - 1;
        int j = col - 1;

        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;

            i--;
            j--;
        }

        // check upper-right diagonal
        i = row - 1;
        j = col + 1;

        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q')
                return false;

            i--;
            j++;
        }

        return true;
    }

    void solve(int row, int n) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isSafe(row, col, n)) {

                board[row][col] = 'Q';

                solve(row + 1, n);

                // remove queen and try another position
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        board = vector<string>(n, string(n, '.'));

        solve(0, n);

        return ans;
    }
};