#include <iostream>
#include <set>

using namespace std;

int checkConditions(int array[][3], int rowSize, int colSize, set<int> conditions) {
    bool found = false;
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            for (int condition : conditions) {
                if (array[i][j] == condition) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return -1;
            }
        }
    }
    return 0;
}

int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    set<int> conditions = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result = checkConditions(arr, 3, 3, conditions);
    if (result == 0) {
        cout << "All elements are contained in the conditions set." << endl;
    } else {
        cout << "An element in the array is not in the conditions set." << endl;
    }
    return 0;
}
