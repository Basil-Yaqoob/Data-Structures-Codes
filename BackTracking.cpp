////Rat in a Maze
//#include <iostream>
//using namespace std;
//bool isSafe(int** a, int x, int y, int n) {// To check whether the position is in bound and is unblocked to move.
//    if (x >= 0 && y >= 0 && x < n && y < n && a[x][y] == 1) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//bool RatInMaze(int** a, int x, int y, int n, int** sol) {
//    if (x == n - 1 && y == n - 1) { // Base Case to Check the Finish Point is Reached
//        sol[x][y] = 1;
//        return true;
//    }
//    if (isSafe(a, x, y, n)) { // To Check whether we can move or not
//        if (sol[x][y] == 1) {
//            return false;
//        }
//        sol[x][y] = 1;
//        if (RatInMaze(a, x + 1, y, n, sol)) {// To Check down 
//            return true;
//        }
//        if (RatInMaze(a, x, y + 1, n, sol)) {// To check right
//            return true;
//        }
//        sol[x][y] = 0;// Can Not Move
//        return false;// So now Backtrack
//    }
//    return false;//No Solution Exists
//}
//int main()
//{
//    int n;
//    cout << "Enter the Size of Array: ";
//    cin >> n;
//    int** a = new int* [n];
//    for (int i = 0; i < n; i++) {
//        a[i] = new int[n];
//    }
//    cout << "Enter 1 for Unblocked region and 0 For Block region: \n";
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << "Enter Value at Index [" << i << "][" << j << "]: " << endl;
//            cin >> a[i][j];
//        }
//    }
//    cout << "Printing Maze: \n";
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    //Creating Solution Empty Array
//    int** sol = new int* [n];
//    for (int i = 0; i < n; i++) {
//        sol[i] = new int[n];
//        for (int j = 0; j < n; j++) {
//            sol[i][j] = 0;
//        }
//    }
//
//    if (RatInMaze(a, 0, 0, n, sol)) {
//        cout << "Solution Found: \n";
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                cout << sol[i][j] << " ";
//            }
//            cout << endl;
//        }
//    }
//    else {
//        cout << "Solution Doesn't Exists\n";
//    }
//}
//
//Knight tour
//#include<iostream>
//using namespace std;
//bool isSafe(int** a, int x, int y, int n) {
//	if (x >= 0 && y >= 0 && x < n && y < n && a[x][y] == 0)
//		return true;
//	return false;
//}
//bool KnightTour(int** a, int x, int y, int n,int &no) {
//	if (no == (n * n)) {
//		return true;
//	}
//	if (isSafe(a, x, y, n)) {
//		if (a[x][y] != 0) {
//			return false;
//		}
//		no++;
//		a[x][y] = no;
//		
//		if (KnightTour(a, x + 2, y + 1, n, no))
//			return true;
//		if (KnightTour(a, x + 2, y - 1, n, no))
//			return true;
//		if (KnightTour(a, x - 2, y + 1, n, no))
//			return true;
//		if (KnightTour(a, x - 2, y - 1, n, no))
//			return true;
//		if (KnightTour(a, x + 1, y + 2, n, no))
//			return true;
//		if (KnightTour(a, x + 1, y - 2, n, no))
//			return true;
//		if (KnightTour(a, x - 1, y + 2, n, no))
//			return true;
//		if (KnightTour(a, x - 1, y - 2, n, no))
//			return true;
//		a[x][y] = 0;
//		no--;
//		return false;
//	}
//	return false;
//}
//int main()
//{
//	int n;
//	cout << "Enter the Size of Array: ";
//	cin >> n;
//	int** a = new int* [n];
//	for (int i = 0; i < n; i++) {
//		a[i] = new int[n];
//		for (int j = 0; j < n; j++) {
//			a[i][j] = 0;
//		}
//	}
//	int num = 0;
//	if (KnightTour(a, 0, 0, n, num)) {
//		cout << "Solution Found: \n";
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				cout << a[i][j] << " ";
//			}
//			cout << endl;
//		}
//		cout << "\nNumber of Moves: " << num << endl;
//	}
//
//	else {
//		cout << "Solution Doesn't Exists\n";
//	}
//}

//#include <iostream>
//using namespace std;
//bool isSafe(int** a, int x, int y, int n) {
//	for (int row = 0; row < x; row++) {
//		if (a[row][y] == 1)
//			return false;
//	}
//	int row = x, col = y;
//	while (row >= 0 && col >= 0) {
//		if (a[row][col] == 1) {
//			return false;
//		}
//		row--;
//		col--;
//	}
//	row = x;
//	col = y;
//	while (row >= 0 && col < n) {
//		if (a[row][col] == 1)
//			return false;
//		row--;
//		col++;
//	}
//	return true;
//}
//bool NQUEEN(int** a, int x, int n) {
//	if (x == n) {
//		return true;
//	}
//	for (int col = 0; col < n; col++) {
//		if (isSafe(a, x, col, n)) {
//			a[x][col] = 1;
//			if (NQUEEN(a, x + 1, n)) {
//				return true;
//			}
//			a[x][col] = 0;
//		}
//	}
//	return false;
//}
//int main()
//{
//	int n;
//	cout << "Enter The size of board: ";
//	cin >> n;
//
//	int** a = new int* [n];
//	for (int i = 0; i < n; i++) {
//		a[i] = new int[n];
//		for (int j = 0; j < n; j++) {
//			a[i][j] = 0;
//		}
//	}
//
//	if (NQUEEN(a, 0, n)) {
//		cout << "N Queens can be Formed: \n";
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				cout << a[i][j] << " ";
//			}
//			cout << endl;
//		}
//	}
//	else {
//		cout << "N Queen Can Not be Formed\n";
//	}
//}
