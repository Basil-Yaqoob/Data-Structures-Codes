#include <iostream>
using namespace std;
bool isSafe(int** a, int x, int y, int n) {// To check whether the position is in bound and is unblocked to move.
    if (x >= 0 && y >= 0 && x < n && y < n && a[x][y] == 0) {
        return true;
    }
    else {
        return false;
    }
}
bool KnightTour(int** a, int x, int y, int n, int &num) {
    if (num==(n*n)) { // Base Case to Check if array is full
 
        return true;
    }
    if (isSafe(a, x, y, n)) { // To Check whether we can move or not
        if (a[x][y] != 0) {
            return false;
        }
        num++;
        a[x][y] = num;
        if (KnightTour(a, x + 1, y+2, n, num)) {
            return true;
        }
        if (KnightTour(a, x - 1, y + 2, n, num)) {
            return true;
        }
        if (KnightTour(a, x + 1, y - 2, n, num)) {
            return true;
        }
        if (KnightTour(a, x - 1, y - 2, n, num)) {
            return true;
        }
        if (KnightTour(a, x + 2, y + 1, n, num)) {
            return true;
        }
        if(KnightTour(a, x + 2, y - 1, n, num)) {
            return true;
        }
        if (KnightTour(a, x - 2, y + 1, n, num)) {
            return true;
        }
        if (KnightTour(a, x - 2, y - 1, n, num)) {
            return true;
        }

        a[x][y] = 0;// Can Not Move
        num--;
        return false;// So now Backtrack
    }
    return false;//No Solution Exists
}
int main()
{
    int n;
    cout << "Enter the Size of Array: ";
    cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    int num = 0;
    if (KnightTour(a, 0, 0, n, num)) {
        cout << "Solution Found: \n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\nNumber of Moves: " << num << endl;
    }
    
    else {
        cout << "Solution Doesn't Exists\n";
    }
}

