#include <iostream>
#include <vector>
using namespace std;

bool isvalid(vector<int> &arr, int n, int m, int max) {
    int st = 1, p = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            return false;
        if (p + arr[i] <= max)
            p += arr[i];
        else {
            st++;
            p = arr[i];
        }
    }
    return st <= m;
}

int all(vector<int> &ar, int n, int m) {
    int s = 0;

    for (int i = 0; i < n; i++)
        s += ar[i];

    int a = -1;
    int start = 0, end = s;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isvalid(ar, n, m, mid)) {
            a = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return a;
}

int main() {
    vector<int> ar = {15, 17, 20};
    int n = ar.size();
    int m = 2;

    int result = all(ar, n, m);
    cout  << result << endl;

    return 0;
}
