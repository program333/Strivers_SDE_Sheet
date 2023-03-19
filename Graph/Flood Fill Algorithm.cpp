https://www.geeksforgeeks.org/flood-fill-algorithm/
https://takeuforward.org/graph/flood-fill-algorithm-graphs/
/*
An Approach using DFS:

Change the color of source row and source column with given color
Do dfs in four direction
*/

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Floodfill function
void floodFill(vector<vector<int> >& screen, int sr, int sc,
			int row, int col, int source, int color)
{
	// Condition for checking out of bounds
	if (sr < 0 || sr >= row || sc < 0 || sc >= col)
		return;

	if (screen[sr][sc] != source)
		return;

	screen[sr][sc] = color;
	floodFill(screen, sr - 1, sc, row, col, source,
			color); // left
	floodFill(screen, sr + 1, sc, row, col, source,
			color); // right
	floodFill(screen, sr, sc + 1, row, col, source,
			color); // top
	floodFill(screen, sr, sc - 1, row, col, source,
			color); // bottom
}

// Driver code
int main()
{
	vector<vector<int> > screen
		= { { 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 1, 0, 0, 1, 1, 0, 1, 1 },
			{ 1, 2, 2, 2, 2, 0, 1, 0 },
			{ 1, 1, 1, 2, 2, 0, 1, 0 },
			{ 1, 1, 1, 2, 2, 2, 2, 0 },
			{ 1, 1, 1, 1, 1, 2, 1, 1 },
			{ 1, 1, 1, 1, 1, 2, 2, 1 } };

	// Row of the display
	int m = 8;

	// Column of the display
	int n = 8;

	// Co-ordinate provided by the user
	int x = 4;
	int y = 4;

	// Current color at that co-ordinate
	int prevC = screen[x][y];

	// New color that has to be filled
	int newC = 3;

	floodFill(screen, x, y, m, n, prevC, newC);

	// Printing the updated screen
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << screen[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

/*
Output
1 1 1 1 1 1 1 1 
1 1 1 1 1 1 0 0 
1 0 0 1 1 0 1 1 
1 3 3 3 3 0 1 0 
1 1 1 3 3 0 1 0 
1 1 1 3 3 3 3 0 
1 1 1 1 1 3 1 1 
1 1 1 1 1 3 3 1 
Time Complexity: O(m*n)
Auxiliary Space: O(m + n), due to the recursive call stack
*/
