#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

// Helper: Convert square number to (row, col) on the board after zigzag
vector<int> intToPos(int square, int len) {
    int r = (square - 1) / len;
    int c = (square - 1) % len;
    // If row is odd, reverse column for zigzag pattern
    if (r % 2)
        c = (len - 1 - c);
    return {r, c};
}

// Returns the minimum moves to reach the last square, or -1 if impossible
int snakesAndLadders(vector<vector<int>>& board) {
    int len = board.size();
    // The algorithm expects rows 0 is bottom; reverse to simplify math
    reverse(board.begin(), board.end());

    deque<vector<int>> q;
    q.push_back({1, 0}); // Start from square 1 with 0 moves
    set<int> vis;

    while (!q.empty()) {
        vector<int> curr = q.front();
        q.pop_front();
        int square = curr[0];
        int moves = curr[1];

        // Try all dice outcomes [1,6]
        for (int i = 1; i < 7; i++) {
            int nextSquare = square + i;
            if (nextSquare > len * len) continue;

            vector<int> ins = intToPos(nextSquare, len);
            int r = ins[0];
            int c = ins[1];

            // If there's a snake or ladder, move to its destination
            if (board[r][c] != -1)
                nextSquare = board[r][c];

            // Goal is to reach last square
            if (nextSquare == len * len)
                return moves + 1;

            // Visit each node only once (BFS shortest path)
            if (vis.find(nextSquare) == vis.end()) {
                vis.insert(nextSquare);
                q.push_back({nextSquare, moves + 1});
            }
        }
    }
    return -1; // If end is unreachable
}

int main() {
    // Example input board
    vector<vector<int>> board = {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}
    };

    int result = snakesAndLadders(board);
    cout << "Minimum moves to finish: " << result << endl;
    return 0;
}
