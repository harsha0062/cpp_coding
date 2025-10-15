#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;

    Employee(int id, int importance, vector<int> subordinates) {
        this->id = id;
        this->importance = importance;
        this->subordinates = subordinates;
    }
};

/*
 * Helper function does DFS to sum up importance.
 * It accumulates the importance of the current employee and all its subordinates recursively.
 */
void helper(unordered_map<int,Employee*> mp, int id, int &sum) {
    Employee* e = mp[id];
    sum += e->importance;
    for (int sub : e->subordinates)
        helper(mp, sub, sum);
}

/*
 * Returns the total importance of an employee with given id,
 * including all direct and indirect subordinates.
 */
int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int,Employee*> mp;
    for (Employee* e : employees)
        mp[e->id] = e;
    int sum = 0;
    helper(mp, id, sum);
    return sum;
}

int main() {
    /*
        Example input:
        Employee 1: importance = 5, subordinates = [2,3]
        Employee 2: importance = 3, subordinates = []
        Employee 3: importance = 3, subordinates = []
        id = 1
        Total importance should be 5 + 3 + 3 = 11.
    */
    Employee* emp1 = new Employee(1, 5, {2, 3});
    Employee* emp2 = new Employee(2, 3, {});
    Employee* emp3 = new Employee(3, 3, {});

    vector<Employee*> employees = {emp1, emp2, emp3};
    int id = 1;

    int result = getImportance(employees, id);
    cout << "Total importance for employee " << id << " is: " << result << endl;

    // Clean up memory (not necessary in competitive programming, but good practice)
    delete emp1;
    delete emp2;
    delete emp3;

    return 0;
}
