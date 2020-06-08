/*
    You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

    Find i, j, k such that :
    max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
    Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

    **abs(x) is absolute value of x and is implemented in the following manner : **

      if (x < 0) return -x;
      else return x;
    Example :

    Input : 
            A : [1, 4, 10]
            B : [2, 15, 20]
            C : [10, 12]

    Output : 5 
            With 10 from A, 15 from B and 10 from C.   
*/
/*
    Approach:
        Take three poniters x, y, z.
        Initialize them to start of A, B, C.
        Find minimum of x, y, z.
        Compute max(x, y, z) - min(x, y, z).
        If new result is less than current change new result and increment pointer of array that contains minimum.
    " We increment the pointer of the array which has minimum, because our goal is to decrease the differnece. Increasing the max pointer is going to increase this difference. "
    This solution approach is of time O(p+q+r) complexity where p, q, r are the sizes of arrays A, B, and C.
*/

int Solution::minimize(vector<int> &A, vector<int> &B, vector<int> &c){
    int i=0, j=0, k=0;
    int minm=INT_MAX;
    while(i<A.size() && j<B.size() && k<C.size()){
        int minima = min(A[i], min(B[j], C[k]));
        int maxima = max(A[i], max(B[j], C[k]));
        if(maxima - minima < minm){
            minm=maxima-minima;
        }
        if(minm==0) break;
        if(A[i]==maxima) i++;
        else if(B[j]==maxima) j++;
        else k++;
    }
    return minm;
}
      
