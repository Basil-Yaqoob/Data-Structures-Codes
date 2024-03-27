#include <iostream>
using namespace std;
bool isSafe(int **a, int row, int col, int num) {
    for (int i = 0; i < 9; i++) {// checking row 
        if (a[row][i] == num)
            return false;
    }
    for (int i = 0; i < 9; i++) {// checking column
        if (a[i][col] == num)
            return false;
    }
    int SR = row - row % 3; //to get the starting first element of each 3*3 matrix
    int SC = col - col % 3;
    for (int i = 0; i < 3; i++) { //Checking 3*3 inner box
        for (int j = 0; j < 3; j++) {
            if (a[i + SR][j + SC] == num)
                return false;
        }
    }
    return true;
}
bool Suduko(int** a, int row, int col) {
    if (row == 8 && col == 9) {//to check is it finish or not
        return true;
    }
    if (col >= 9) {// to shift to next row when all column are done
        row++;
        col = 0;
    }
    if (a[row][col] != 0) {//if the box is already filled so going to the next column
        return Suduko(a, row, col + 1);
    }
    for (int num = 1; num <= 9; num++) {
        if (isSafe(a, row, col, num)) {
            a[row][col] = num;
            if (Suduko(a, row, col + 1)) { //Reccursion
                return true;
            }
            a[row][col] = 0;//Backtrack
            
        }
    }
    return false;
}
int main()
{
    //int  InitialArray[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, //Soluble
    //        {   5, 2, 0, 0, 0, 0, 0, 0, 0 },
    //        {   0, 8, 7, 0, 0, 0, 0, 3, 1 },
    //        {   0, 0, 3, 0, 1, 0, 0, 8, 0 },
    //        {   9, 0, 0, 8, 6, 3, 0, 0, 5 },
    //        {   0, 5, 0, 0, 9, 0, 6, 0, 0 },
    //        {   1, 3, 0, 0, 0, 0, 2, 5, 0 },
    //        {   0, 0, 0, 0, 0, 0, 0, 7, 4 },
    //        {   0, 0, 5, 2, 0, 6, 3, 0, 0 } };
          
      //int  InitialArray[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, //Soluble
      //      { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
      //      { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
      //      { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
      //      { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
      //      { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
      //      { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
      //      { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
      //      { 0, 0, 5, 2, 0, 6, 3, 0, 0 }};

    //int  InitialArray[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  //Soluble
    //    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    //    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    //    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    //    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    //    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    //    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    //    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    //    {0, 0, 5, 2, 0, 6, 3, 0, 0}
    //};

    int  InitialArray[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
      
      int** a = new int* [9];
          for (int i = 0; i < 9; i++) {
              a[i] = new int[9];
              for (int j = 0; j < 9; j++) {
                  a[i][j] = InitialArray[i][j];
              }
          }
          cout << "Printing Unsloved Suduko : \n";
          for (int i = 0; i < 9; i++) {
              for (int j = 0; j < 9; j++) {
                  cout << a[i][j] << "\t";
              }
              cout << endl;
          }
    if(Suduko(a,0,0)){
        cout << "\nSuduko Solved: \n";
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    cout << a[i][j] << "\t";
                }
                cout << endl;
            }
    }
    else {
        cout << "Suduko can not be solved\n";
    }
}

