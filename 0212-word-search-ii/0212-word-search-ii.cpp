class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        string word;

        TrieNode() {
            word = "";
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (string& word : words) {
            TrieNode* node = root;

            for (char c : word) {
                int idx = c - 'a';

                if (!node->children[idx])
                    node->children[idx] = new TrieNode();

                node = node->children[idx];
            }

            node->word = word;
        }

        return root;
    }

    void dfs(vector<vector<char>>& board,
             int r,
             int c,
             TrieNode* node,
             vector<string>& result) {

        char ch = board[r][c];

        if (ch == '#' || node->children[ch - 'a'] == nullptr)
            return;

        node = node->children[ch - 'a'];

        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";
        }

        board[r][c] = '#';

        if (r > 0)
            dfs(board, r - 1, c, node, result);

        if (c > 0)
            dfs(board, r, c - 1, node, result);

        if (r < board.size() - 1)
            dfs(board, r + 1, c, node, result);

        if (c < board[0].size() - 1)
            dfs(board, r, c + 1, node, result);

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = buildTrie(words);

        vector<string> result;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};