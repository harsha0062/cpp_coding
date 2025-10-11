#include <iostream>
#include <vector>
using namespace std;

// Function to find the starting gas station index
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int totalGas = 0, totalCost = 0;
    int currGas = 0;
    int start = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        totalGas += gas[i];
        totalCost += cost[i];
        currGas += gas[i] - cost[i];

        // If current gas is negative, cannot reach next station from current start
        if (currGas < 0)
        {
            start = i + 1; // choose next station as starting point
            currGas = 0;   // reset current gas
        }
    }

    // If total gas is less than total cost, not possible to complete the circuit
    return (totalGas < totalCost) ? -1 : start;
}

int main()
{
    // Example test case
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int result = canCompleteCircuit(gas, cost);

    if (result == -1)
        cout << "It is not possible to complete the circuit." << endl;
    else
        cout << "Start at gas station index: " << result << endl;

    return 0;
}
