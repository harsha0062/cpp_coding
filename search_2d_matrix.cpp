#include<iostream>
#include<vector>
using namespace std;
bool searchinrow(vector<vector<int>>& matrix, int target, int midrow) {
    int n = matrix[0].size();
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (matrix[midrow][mid] == target)
            return true;
        else if (matrix[midrow][mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // bs on total no of rows
    int m = matrix.size(), n = matrix[0].size();

    int startrow = 0, endrow = m - 1;

    while (startrow <= endrow) {
        int midrow = (startrow + endrow) / 2;
        if (matrix[midrow][0] <= target &&
            matrix[midrow][n - 1] >= target) {
            return searchinrow(matrix, target, midrow);
        } else if (matrix[midrow][n - 1] <= target) {
            startrow = midrow + 1;
        } else {
            endrow = midrow - 1;
        }
    }
    return false;
}


int main(){
    vector<vector<int>> v={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int t=37;
    cout<<"the key is present in this matrix:"<<searchMatrix(v,t)<<endl;
}