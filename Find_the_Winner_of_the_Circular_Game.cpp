#include <iostream>
#include <deque>
using namespace std;

// Function to find the winner in the Josephus problem
int findTheWinner(int n, int k) {
    deque<int> q;
    // Initialize queue with players numbered 1 to n
    for (int i = 1; i <= n; i++) {
        q.push_back(i);
    }
    
    // Loop until only one remains
    while (q.size() > 1) {
        // Move first k-1 players to the back of the queue
        for (int count = 1; count < k; count++) {
            q.push_back(q.front());
            q.pop_front();
        }
        // Remove the kth player
        q.pop_front();
    }
    
    // The last remaining player is the winner
    return q.front();
}

int main() {
    // Example input: n players, k step count
    int n = 5;
    int k = 2;
    
    // Call the function and print the winner
    int winner = findTheWinner(n, k);
    cout << "The winner is: " << winner << endl;
    
    return 0;
}
