https://takeuforward.org/data-structure/set-matrix-zero/

/*
Examples 1:

Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]

Output: [[1,0,1],[0,0,0],[1,0,1]]

Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.


Approach: Take two dummy arrays one of size of the row and the other of size of column. Now traverse through the array.
If matrix[i][j]==0 then set dummy1[i]=0(for row) and dummy2[j]=0(for column).
Now traverse through the array again and if dummy1[i]==0  || dummy2[j]==0 then arr[i][j]=0,else continue.
*/

#include<bits/stdc++.h>
using namespace std;
void setZeroes(vector < vector < int >> & matrix) {
  int rows = matrix.size(), cols = matrix[0].size();
  vector < int > dummy1(rows,-1), dummy2(cols,-1);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 0) {
        dummy1[i] = 0;
        dummy2[j] = 0;
      }
    }

  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (dummy1[i] == 0 || dummy2[j]==0) {
        matrix[i][j] = 0;
      }
    }
  }

}

int main() {
  vector < vector < int >> arr;
  arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  setZeroes(arr);
  cout<<"The Final Matrix is "<<endl;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}

/*
Output:

The Final Matrix is
0 0 0 0
0 4 5 0
0 3 1 0

Time Complexity: O(N*M + N*M)

Space Complexity: O(N)
*/

