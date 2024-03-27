#include <iostream>
using namespace std;
bool isSafe(int** a, int x, int y, int n) {// To check whether the position is in bound and is unblocked to move.
    if (x >= 0 && y >= 0 && x < n && y < n && a[x][y] == 1) {
        return true;
    }
    else { 
        return false;
        }
}
bool RatInMaze(int** a, int x, int y, int n, int** sol) {
    if (x == n - 1 && y == n - 1) { // Base Case to Check the Finish Point is Reached
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(a, x, y, n)) { // To Check whether we can move or not
        if (sol[x][y] == 1) {
            return false;
        }
        sol[x][y] = 1;
        if (RatInMaze(a, x + 1, y, n, sol)) {// To Check down 
            return true;
        }
        if (RatInMaze(a, x , y+1, n, sol)) {// To check right
            return true;
        }
        sol[x][y] = 0;// Can Not Move
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
    }
    cout << "Enter 1 for Unblocked region and 0 For Block region: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter Value at Index [" << i << "][" << j << "]: " << endl;
            cin >> a[i][j];
        }
    }
    cout << "Printing Maze: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    //Creating Solution Empty Array
    int** sol = new int* [n];
    for (int i = 0; i < n; i++) {
        sol[i] = new int[n];
        for (int j = 0; j < n; j++) {
            sol[i][j] = 0;
        }
    }

    if (RatInMaze(a, 0, 0, n, sol)) {
        cout << "Solution Found: \n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Solution Doesn't Exists\n";
    }
}

