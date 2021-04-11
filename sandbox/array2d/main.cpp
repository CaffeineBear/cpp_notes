#include <iostream>
#include <cassert>

void TwoD(int row, int column, int ***result) {
  int** a = new int* [row];
  for(int i = 0; i < row; i++){
    int *currRow = new int[column];
    a[i] = currRow;
  }
  *result = a;
}

void TwoD(int row, int column, int **&result) {
  result = new int* [row];
  for(int i = 0; i < row; i++){
    int *currRow = new int[column];
    result[i] = currRow;
  }
}

void freeTwoD(int row, int ***result) {
  int **a = *result;
  for(int i = 0; i < row; i++){
    delete[] a[i];
  }
  delete[] a;
  *result = nullptr;
}

void freeTwoD(int row, int **&result) {
  for(int i = 0; i < row; i++){
    delete[] result[i];
  }
  delete[] result;
  result = nullptr;
}

int main() {
  using namespace std;
  int **new2DArray, **b;
  int row = 2;
  int column = 2;
  TwoD(row, column, &new2DArray);
  new2DArray[0][0] = 0;
  new2DArray[0][1] = 1;
  new2DArray[1][0] = 2;
  new2DArray[1][1] = 3;
  for(int i = 0; i < row; i++){
    for (int j = 0; j < column; j++) {
      cout << new2DArray[i][j];
    }
  }
  cout << endl;
  freeTwoD(row, &new2DArray);
  assert(new2DArray == nullptr);

  TwoD(row, column, b);
  b[0][0] = 4;
  b[0][1] = 5;
  b[1][0] = 6;
  b[1][1] = 7;
  for(int i = 0; i < row; i++){
    for (int j = 0; j < column; j++) {
      cout << b[i][j];
    }
  }
  cout << endl;
  freeTwoD(row, b);
  assert(b == nullptr);

  return 0;
}