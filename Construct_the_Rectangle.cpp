#include <iostream>
#include <vector>
using namespace std;

// Function to construct a rectangle with minimal difference between length and width
vector<int> constructRectangle(int area) {
    int aw = 1, al = area; // aw = width, al = length initially
    for (int w = 2; w * w <= area; w++) {
        if (area % w != 0)
            continue;
        int diff = (area / w) - w;
        if (diff < 0)
            break;
        if (diff < al - aw)
            al = area / w, aw = w;
    }
    return {al, aw};
}

int main() {
    int area = 37; // Example input area
    vector<int> result = constructRectangle(area);

    cout << "Length: " << result[0] << ", Width: " << result[1] << endl;

    return 0;
}
