#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Depth-first search helper function to check if word exists starting at board[r][c]
bool dfs(int r, int c, int i, int row, int col, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited) {
    // If all characters matched
    if (i == word.size())
        return true;

    // Boundary checks and character match check and visited check
    if (r < 0 || c < 0 || r >= row || c >= col || board[r][c] != word[i] || visited[r][c])
        return false;

    visited[r][c] = true; // Mark this cell visited

    // Explore all 4 directions: down, up, right, left
    bool ans = dfs(r + 1, c, i + 1, row, col, board, word, visited) ||
               dfs(r - 1, c, i + 1, row, col, board, word, visited) ||
               dfs(r, c + 1, i + 1, row, col, board, word, visited) ||
               dfs(r, c - 1, i + 1, row, col, board, word, visited);

    visited[r][c] = false; // Backtrack

    return ans;
}

// Main function to check if word exists in the board
bool exist(vector<vector<char>>& board, string word) {
    int row = board.size();
    int col = board[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    // Try to find the word starting from every cell
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            if (dfs(r, c, 0, row, col, board, word, visited))
                return true;
        }
    }
    return false;
}

int main() {
    // Example board input
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED"; // Example word to search

    // Check if the word exists in the board
    if (exist(board, word)) {
        cout << "The word \"" << word << "\" exists in the board." << endl;
    } else {
        cout << "The word \"" << word << "\" does NOT exist in the board." << endl;
    }

    // Demonstration of NULL pointer usage (for example only)
    int* ptr = NULL;
    if (ptr == NULL) {
        cout << "Pointer is NULL (example only)" << endl;
    }

    return 0;
}
