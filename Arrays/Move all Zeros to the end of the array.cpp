https://takeuforward.org/data-structure/move-all-zeros-to-the-end-of-the-array/
https://www.geeksforgeeks.org/move-zeroes-end-array/

#include<bits/stdc++.h>
using namespace std;

void zerosToEnd(int arr[],int n) {

        int temp[n];
        int k=0;
        for (int i=0;i<n;i++){
            if (arr[i]!=0){
                temp[k]=arr[i];
                k++;
            }
        }
       
        while (k<n){
            temp[k]=0;
            k++;
        }
        for(int i=0;i<n;i++)
        {
            cout<<temp[i]<<" ";
        }
    }

int main() {
      int arr[] ={ 1,2,0,1,0,4,0};
       zerosToEnd(arr,7);
}
/*
Output: 1 2 1 4 0 0 0

Time complexity: o(n)

Space complexity: o(n)
*/


// C++ Program to move all zeros to the end

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int A[] = { 5, 6, 0, 4, 6, 0, 9, 0, 8 };
	int n = sizeof(A) / sizeof(A[0]);
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] != 0) {
			swap(A[j], A[i]); // Partitioning the array
			j++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << A[i] << " "; // Print the array
	}

	return 0;
}

