/* 
  Remove duplicates from Sorted Array
  Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

  Note that even though we want you to return the new length, make sure to change the original array as well in place
  
  Do not allocate extra space for another array, you must do this in place with constant memory.

  Example:
  Given input array A = [1,1,2],
  Your function should return length = 2, and A is now [1,2]. 
*/
/*Approach
  Using two pointers iterate the array and update the pointer only when A[i]!=A[i+1].
  This solution is of O(N^2) time complexity.
*/

int Solution::removeDuplicates(vector<int> &A){
  int n=A.size();
  for(int i=0; i<n-1;i++){
    int j=i+1;
    if(A[i]==A[j]){
      while(A[i]==A[j] && j<A.size()){
        j++;
      }
      j--;
      A.erase(A.begin()+i+1, A.begin()+j+1);
    }
  }
  return A.size();
}


/*
  int Soluton::removeDuplicates(vector<int> &A) {
			int count = 0, n = A.size();
			for (int i = 0; i < n; i++) { 
				if (i < n - 1 && A[i] == A[i+1]) continue;
				else {
					A[count] = A[i];
					count++;
				}
			}
			return count;
		}
   O(N) time compexity.
 */
