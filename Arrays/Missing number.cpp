


int missingNumber(int A[], int N)
{
    // Your code goes here
    int NnumberSum=(N*(N+1))/2;
    int ASum=0;
    for(int i=0;i<N-1;i++){
        ASum+=A[i];
    }
    
    return NnumberSum-ASum;
}
