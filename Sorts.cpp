//Shell Sort ascending order
//#include <iostream>
//using namespace std;
//int main()
//{
//    int a[] = { 23,29,15,19,31,7,9,5,2 };
//    int n = 9;
//    for (int gap = n / 2; gap >= 1; gap /= 2) {
//        for (int j = gap; j < n; j++) {
//            for (int i = j - gap; i >= 0; i -= gap) {
//                if (a[i + gap] >= a[i]) {//= for stable sort
//                    break;
//                }
//                else {
//                    swap(a[i + gap], a[i]);
//                }
//            }
//        }
//    }
    //for (int i = 0; i < n; i++) {
    //    cout << a[i] << "\t";
    //}
//}


// Shell sort Descending order
//#include <iostream>
//using namespace std;
//int main()
//{
//    int a[] = { 23,29,15,19,31,7,9,5,2 };
//    int n = 9;
//    for (int gap = n / 2; gap >= 1; gap /= 2) {
//        for (int j = gap; j < n; j++) {
//            for (int i = j - gap; i >= 0; i -= gap) {
//                if (a[i + gap] <= a[i]) {
//                    break;
//                }
//                else {
//                    swap(a[i + gap], a[i]);
//                }
//            }
//        }
//    }
//
//        for (int i = 0; i < n; i++) {
//            cout << a[i] << "\t";
//        }
//}\

// Insertion sort
//i element ko sorted array se compare karake jo ke j=i-1 se chl raha usse compare karate
//#include<iostream>
//using namespace std;
//int main(){
//    int a[] = { 3,6,1,10,2,4 };
//    int n = 6;
//    for (int i = 1; i < n; i++) {
//        int temp = a[i];
//        int j = i - 1;
//        while (j >= 0 && a[j] > temp) {
//            a[j + 1] = a[j];
//            j--;
//        }
//        a[j + 1] = temp;
//    }
//
//    for (int i = 0; i < n; i++) {
//        cout << a[i] << "\t";
//    }
//}

// Opptimize Bubble sort
//#include<iostream>
//using namespace std;
//int main() {
//    int a[] = { 3,6,1,10,2,4 };
//    int n = 6;
//    for (int i = 0; i < n-1; i++) {//bcz the last element is already sorted so n-1
//        int flag = 0;
//        for (int j = 0; j < n - i - 1; j++) {//bcz the last elements are already sorted so n-i-1
//            if (a[j] > a[j + 1]) {
//                int temp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = temp;
//                flag = 1;
//            }
//        }
//        if (flag == 0) {
//            break;
//        }
//    }
//
//    for (int i = 0; i < n; i++) {
//        cout << a[i] << "\t";
//    }
//}

// Selection sort
// minimum element ka index leke aagge ke index se compare karate aur agr j chota hou tou min=j krdete
//#include<iostream>
//using namespace std;
//int main() {
//    int a[] = { 3,6,1,10,2,4 };
//    int n = 6;
//    for (int i = 0; i < n-1; i++) { //bcz last elemnt is already sorted by the end of the loop
//        int min = i;
//        for (int j = i + 1; j < n; j++) {
//            if (a[j] < a[min]) {
//                min = j;
//            }
//        }
//        if (min != i) {
//            swap(a[i], a[min]);
//        }
//    }
//
//    for (int i = 0; i < n; i++) {
//        cout << a[i] << "\t";
//    }
//}

                                //Bubble sort in 2D Array
#include<iostream>
using namespace std;
int main() {
	int a[4][4] = { {3,4,1,2},{6,4,5,7},{3,4,1,2},{6,4,5,7} };
	int col = 4, row = 4;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl; cout << endl;

	//Column wise bubbule sort
	//write j loop first of column and use k opposite to where we want to swap
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row - 1; i++) {
			for (int k = 0; k < row - i - 1; k++) {
				if (a[k][j] > a[k + 1][j]) {
					swap(a[k][j], a[k + 1][j]);
				}
			}

		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl; cout << endl;

	//Row wise bubbule sort
	//write i loop first of rows and use k opposite to where we want to swap
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col - 1; j++) {
			for (int k = 0; k < col - j - 1; k++) {
				if (a[i][k] > a[i][k + 1]) {
					swap(a[i][k], a[i][k + 1]);
				}
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

