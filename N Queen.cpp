#include <iostream>
using namespace std;
bool isSafe(int** a, int x, int y, int n) {
    for (int row = 0; row < x; row++) {//to check row , row<x to only check the above one and down ones are empty
        if (a[row][y] == 1) {
            return false;
        }
    }
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0) { // to check north west direction
        if (a[row][col] == 1) {
            return false;
        }
        row--;
        col--;
    }
    row = x;
    col = y;
    while (row >= 0 && col < n) { // to check north east direction
        if (a[row][col] == 1) {
            return false;
        }
        row--;
        col++;
    }
    return true;
}
bool NQueen(int** a, int x, int n) {
    if (x == n) {
        return true;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(a, x, col, n)) {// to check the column of first row
            a[x][col] = 1;
            if (NQueen(a, x + 1, n)) {// to check the next row
                return true;
            }
            a[x][col] = 0; // back tracking
        }
    }
    return false;// NQueen can not be solved
}
int main()
{
    int n;
    cout << "Enter The size of board: ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    if (NQueen(a, 0, n)) {
        cout << "N Queens can be Formed: \n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "N Queen Can Not be Formed\n";
    }
}