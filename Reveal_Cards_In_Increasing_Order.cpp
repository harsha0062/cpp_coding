#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

// Function to reveal the deck in increasing order
vector<int> deckRevealedIncreasing(vector<int>& deck) {
    // Sort the deck to have cards in ascending order
    sort(deck.begin(), deck.end());

    int n = deck.size();
    vector<int> ans(n);       // Result vector to store the revealed order
    deque<int> q;

    // Initialize the queue with indices 0 to n-1
    for (int i = 0; i < n; i++) {
        q.push_back(i);
    }

    // Simulate the revealing process
    for (int i = 0; i < n; i++) {
        ans[q.front()] = deck[i];  // Place the smallest card at the front index
        q.pop_front();
        if (!q.empty()) {
            // Move the next index from front to back of the queue
            q.push_back(q.front());
            q.pop_front();
        }
    }
    return ans;
}

int main() {
    // Example input deck
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};

    // Get the revealed order
    vector<int> revealed = deckRevealedIncreasing(deck);

    cout << "Revealed deck in increasing order:" << endl;
    for (int card : revealed) {
        cout << card << " ";
    }
    cout << endl;

    return 0;
}
