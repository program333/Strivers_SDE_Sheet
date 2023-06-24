
https://www.geeksforgeeks.org/search-in-a-row-wise-and-column-wise-sorted-2d-array-using-divide-and-conquer-algorithm/

#include <bits/stdc++.h>
#define ROW 4
#define COL 4
using namespace std;

bool binary_search(int mat[ROW][COL], int row, int start,
				int end, int key)
{
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (mat[row][mid] == key) {
			return true;
		}
		else if (mat[row][mid] < key) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return false;
}

void search(int mat[ROW][COL], int key)
{
	// search in each row
	for (int i = 0; i < ROW; i++) {
		// perform binary search in current row
		if (mat[i][0] <= key && mat[i][COL - 1] >= key) {
			if (binary_search(mat, i, 0, COL - 1, key)) {
				cout << "Found " << key << " at " << i
					<< " " << endl;
				return;
			}
		}
	}
	cout << key << " not found" << endl;
}

// Driver code
int main()
{
	int mat[ROW][COL] = { { 10, 20, 30, 40 },
						{ 15, 25, 35, 45 },
						{ 27, 29, 37, 48 },
						{ 32, 33, 39, 50 } };
	int key = 50;
	search(mat, key);
	return 0;
}

