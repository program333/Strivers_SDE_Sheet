https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

#include <bits/stdc++.h>
using namespace std;

void printTwoElements(int arr[], int n){\
// sorting the array
sort(arr,arr+n);
cout << "The repeating element is ";
for(int i=0;i<n-1;i++){
	if(arr[i]==arr[i+1]){
		cout<<arr[i]<<endl;
		break;
	}
}

cout << "and the missing element is ";
for(int i=1;i<=n;i++){
	if(i!=arr[i-1]){
		cout<<i<<endl;
		break;
	}
}

}

int main() {

	int arr[] = { 7, 3, 4, 5, 5, 6, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printTwoElements(arr, n);
	return 0;
}

/*
Output
The repeating element is 5
and the missing element is 1
Time Complexity: O(nLogn)
Auxiliary Space: O(1) (No extra array was used
*/


// C++ program to find the repeating
// and missing elements using Maps
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int arr[] = { 4, 3, 6, 2, 1, 1 };
	int n = 6;
	
	unordered_map<int, bool> numberMap;
	
	for(int i : arr)
	{
		if (numberMap.find(i) ==
			numberMap.end())
		{
			numberMap[i] = true;
		}
		else
		{
			cout << "Repeating = " << i;
			break;
		}
	}
	cout << endl;
	
	for(int i = 1; i <= n; i++)
	{
		if (numberMap.find(i) ==
			numberMap.end())
		{
			cout << "Missing = " << i;
			break;
		}
	}
	return 0;
}

/*
Output
Repeating = 1
Missing = 5
Time Complexity: O(N)
Auxiliary Space: O(N)
*/

