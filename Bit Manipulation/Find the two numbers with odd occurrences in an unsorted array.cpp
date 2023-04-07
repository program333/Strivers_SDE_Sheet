https://www.geeksforgeeks.org/find-the-two-numbers-with-odd-occurences-in-an-unsorted-array/
https://takeuforward.org/data-structure/two-odd-occurring/

// C++ Program to find the two odd occurring elements
#include <bits/stdc++.h>
using namespace std;

/* Prints two numbers that occur odd number of times. The
function assumes that the array size is at least 2 and
there are exactly two numbers occurring odd number of times.
*/

void printTwoOdd(int arr[], int size)
{
	/*Create map and calculate frequency of array of
	* elements using array.*/

	unordered_map<int, int> m;
	for (int i = 0; i < size; i++) {
		m[arr[i]]++;
	}

	/*Traverse through the map and check if its second
	element that is the frequency is odd or not.Then this
	is the odd occurring element .It is clearly mentioned
	in problem that there are only two odd occurring
	elements so this will print those two elements.*/

	cout << "The two ODD elements are ";
	for (auto& x : m) {
		if (x.second % 2 != 0)
			cout << x.first << ", ";
	}
}

/* Driver code */
int main()
{
	int arr[] = { 4, 2, 4, 5, 2, 3, 3, 1 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	printTwoOdd(arr, arr_size);
	return 0;
}

/*
Output
The two ODD elements are 1, 5, 
Time Complexity: O(n)
Auxiliary Space: O(n)
*/
