#include <iostream>
#include <vector>
using namespace std;

// Directions for neighbor cells (8 possibilities)
vector<vector<int>> dir = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},          {0, 1},
    {1, -1},  {1, 0},  {1, 1}
};

// Game of Life function (same as your code)
void gameOfLife(vector<vector<int>>& board) {
    int m = board.size(), n = board.size();

    // First pass: Determine new states using marking 2 (alive->dead) and 3 (dead->alive)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0;
            // Count live neighbors using direction array
            for (vector<int> d : dir) {
                int p = i + d[0], q = j + d[1];
                // If neighboring cell is within bounds and is currently alive (or marked as alive->dead)
                if (p >= 0 && p < m && q >= 0 && q < n &&
                    (board[p][q] == 1 || board[p][q] == 2)) {
                    count++;
                }
            }
            // Rule 1 or 3: Mark alive->dead if <2 or >3 neighbors
            if (board[i][j] == 1) {
                if (count < 2 || count > 3) {
                    board[i][j] = 2; // Alive to dead
                }
            }
            // Rule 4: Mark dead->alive if exactly 3 neighbors
            else {
                if (count == 3) {
                    board[i][j] = 3; // Dead to alive
                }
            }
        }
    }

    // Second pass: Finalize cell states (convert marks to 0 or 1)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] %= 2;
        }
    }
}

// Helper function to print the board
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example input board (feel free to modify)
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };

    cout << "Original board:" << endl;
    printBoard(board);

    // Run Game of Life update
    gameOfLife(board);

    cout << "Next state:" << endl;
    printBoard(board);

    return 0;
}
