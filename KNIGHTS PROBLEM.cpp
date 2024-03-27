#include <iostream>
using namespace std;

bool isSafe(int** a, int x, int y, int n) {
    if (x >= 0 && y >= 0 && x < n && y < n && a[x][y] == 0) {
        if (x - 1 >= 0 && y - 2 >= 0) {
            if (a[x - 1][y - 2] == 1) {
                return false;
            }
        }
        if (x - 2 >= 0 && y - 1 >= 0) {
            if (a[x - 2][y - 1] == 1) {
                return false;
            }
        }
        if (x - 1 >= 0 && y + 2 < n) {
            if (a[x - 1][y + 2] == 1) {
                return false;
            }
        }
        if (x - 2 >= 0 && y + 1 < n) {
            if (a[x - 2][y + 1] == 1) {
                return false;
            }
        }
        if (x + 1 < n && y - 2 >= 0) {
            if (a[x + 1][y - 2] == 1) {
                return false;
            }
        }
        if (x + 2 < n && y - 1 >= 0) {
            if (a[x + 2][y - 1] == 1) {
                return false;
            }
        }
        if (x + 1 < n && y + 2 < n) {
            if (a[x + 1][y + 2] == 1) {
                return false;
            }
        }
        if (x + 2 < n && y + 1 < n) {
            if (a[x + 2][y + 1] == 1) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Knights(int** a, int x, int n, int& move) {
    if (move == ((n * n) / 2)) {
        return true;
    }
    if (x >= n) {
        x = 0;
    }
    for (int col = 0; col < n; col++) {

        if (isSafe(a, x, col, n)) {
            move++;
            a[x][col] = 1;
            if (Knights(a, x + 1, n, move)) {
                return true;
            }
            a[x][col] = 0;
            move--;
        }
    }

    return false;
}

int main() {
    cout << "Enter The Size of Board: ";
    int move = 0, n;
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    if (Knights(a, 0, n, move)) {
        cout << "Problem Solved: \n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout <<"\nTotal Knights Placed are: "<< move << endl;
    }
    else {
        cout << "Problem Can not be Solved...\n";
    }

    return 0;
}