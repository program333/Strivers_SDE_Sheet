https://takeuforward.org/data-structure/count-the-number-of-subarrays-with-given-xor-k/

int Solution::solve(vector<int> &A, int B) {

    unordered_map<int,int>m;
    int n1=A.size();
    int xor1=0;
    int count=0;
    for(int i=0;i<n1;i++){
        xor1=xor1^A[i];
        if(xor1==B)count++;
        
        if(m.find(xor1^B)!=m.end()){
            count+=m[xor1^B];
        }
        
        m[xor1]++;
    }
    
    return count;
}
