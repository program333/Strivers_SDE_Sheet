

class Solution{
public:	
	int search(int A[], int N){
	    //code
	    unordered_map<int,int>m;
	    for(int i=0;i<N;i++){
	        m[A[i]]++;
	    }
	    for(auto it:m){
	        if(it.second==1){
	            return it.first;
	        }
	    }
	    
	    return -1;
	}
};
