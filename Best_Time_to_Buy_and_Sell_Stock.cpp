#include <iostream>
#include <vector>
#include <algorithm> // for min and max functions

using namespace std; // so we don’t prefix with std::

/*
   Function: maxProfit
   - Takes a vector of stock prices
   - Finds the maximum profit we can achieve by buying and selling once
   - Logic:
        * Keep track of the minimum price seen so far (b)
        * At each step, calculate potential profit: current_price - b
        * Update the maximum profit (mp) if this profit is larger
        * Update the minimum price (b) if current price is smaller
*/
int maxProfit(vector<int>& prices) {
    int mp = 0;         // maximum profit, initially 0
    int b = prices[0];  // buy price = first element

    // Loop over all days
    for (int i = 1; i < prices.size(); i++) {
        // If selling today gives more profit, update maximum profit
        if (prices[i] > b)
            mp = max(mp, prices[i] - b);

        // Update buy price if current price is lower
        b = min(b, prices[i]);
    }
    return mp;
}

int main() {
    // Input is given inside the code (not user entered)
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Call the function
    int result = maxProfit(prices);

    // Print the result
    cout << "Maximum Profit = " << result << endl;

    return 0;
}
