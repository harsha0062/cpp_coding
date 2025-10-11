#include <iostream>
#include <vector>
using namespace std;

// Function to calculate maximum profit from stock prices
// You are allowed to make as many transactions as needed
int maxProfit(vector<int>& prices) {
    int max_profit = 0;

    // Traverse through prices and add profit whenever the next day's price is higher
    for (int i = 0; i < (prices.size() - 1); i++) {
        if (prices[i] < prices[i + 1]) {
            max_profit += prices[i + 1] - prices[i];
        }
    }

    return max_profit;
}

int main() {
    // Example stock prices for each day
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Call the function and store result
    int result = maxProfit(prices);

    // Print the profit
    cout << "Maximum Profit: " << result << endl;

    return 0;
}
