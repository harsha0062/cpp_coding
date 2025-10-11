#include <iostream>
#include <vector>
using namespace std;

/**
 * DFS method 1: Standard Up/Right/Down/Left chaining.
 * This function explores all boundary-connected 'O's.
 */
void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    vis[row][col] = 1;

    // Move Up
    if (row - 1 >= 0 && !vis[row - 1][col] && board[row - 1][col] == 'O') {
        dfs(row - 1, col, vis, board);
    }
    // Move Right
    if (col + 1 < m && !vis[row][col + 1] && board[row][col + 1] == 'O') {
        dfs(row, col + 1, vis, board);
    }
    // Move Down
    if (row + 1 < n && !vis[row + 1][col] && board[row + 1][col] == 'O') {
        dfs(row + 1, col, vis, board);
    }
    // Move Left
    if (col - 1 >= 0 && !vis[row][col - 1] && board[row][col - 1] == 'O') {
        dfs(row, col - 1, vis, board);
    }
}

/**
 * DFS method 2: Uses direction arrays to compact 4-direction logic.
 * This function also explores all boundary-connected 'O's.
 */
void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, int delrow[], int delcol[]) {
    int n = board.size();
    int m = board[0].size();
    vis[row][col] = 1;

    // Try all 4 directions (Up, Right, Down, Left)
    for (int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        // If in bounds, not visited, and is 'O', continue DFS
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
            dfs(nrow, ncol, vis, board, delrow, delcol);
        }
    }
}

/**
 * solve1: Uses the first DFS method.
 */
void solve1(vector<vector<char>>& board) {
    int n = board.size();
    if (n == 0) return;
    int m = board[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    // Traverse first and last row
    for (int j = 0; j < m; j++) {
        if (!vis[0][j] && board[0][j] == 'O') {
            dfs(0, j, vis, board);
        }
        if (!vis[n-1][j] && board[n-1][j] == 'O') {
            dfs(n-1, j, vis, board);
        }
    }

    // Traverse first and last column
    for (int i = 0; i < n; i++) {
        if (!vis[i][0] && board[i][0] == 'O') {
            dfs(i, 0, vis, board);
        }
        if (!vis[i][m-1] && board[i][m-1] == 'O') {
            dfs(i, m-1, vis, board);
        }
    }

    // Flip all unvisited 'O's to 'X'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}

/**
 * solve2: Uses DFS with direction arrays.
 */
void solve2(vector<vector<char>>& board) {
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    int n = board.size();
    if (n == 0) return;
    int m = board[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    // Traverse first and last row
    for (int j = 0; j < m; j++) {
        if (!vis[0][j] && board[0][j] == 'O') {
            dfs(0, j, vis, board, delrow, delcol);
        }
        if (!vis[n-1][j] && board[n-1][j] == 'O') {
            dfs(n-1, j, vis, board, delrow, delcol);
        }
    }

    // Traverse first and last column
    for (int i = 0; i < n; i++) {
        if (!vis[i][0] && board[i][0] == 'O') {
            dfs(i, 0, vis, board, delrow, delcol);
        }
        if (!vis[i][m-1] && board[i][m-1] == 'O') {
            dfs(i, m-1, vis, board, delrow, delcol);
        }
    }

    // Flip all unvisited 'O's to 'X'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}

// Helper to print board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char c : row) cout << c << " ";
        cout << endl;
    }
}

int main() {
    // Sample board input
    vector<vector<char>> board1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    // Using Method 1
    cout << "Board before solve1:\n";
    printBoard(board1);
    solve1(board1);
    cout << "\nBoard after solve1:\n";
    printBoard(board1);

    // Sample board input for method 2 (can use same or different sample as needed)
    vector<vector<char>> board2 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    cout << "\nBoard before solve2:\n";
    printBoard(board2);
    solve2(board2);
    cout << "\nBoard after solve2:\n";
    printBoard(board2);

    return 0;
}
