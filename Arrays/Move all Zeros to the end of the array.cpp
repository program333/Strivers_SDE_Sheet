https://takeuforward.org/data-structure/move-all-zeros-to-the-end-of-the-array/

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
