/*
  `Implement strStr().

   strstr - locate a substring ( needle ) in a string ( haystack ). 
   Try not to use standard library string functions for this question.

   Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

   NOTE: Good clarification questions:
   What should be the return value if the needle is empty?
   What if both haystack and needle are empty?
   For the purpose of this problem, assume that the return value should be -1 in both cases. 
*/
/*
  Approach
  Consider every index i for the answer. Find if the following 2 strings are equal:

  1) Needle string and,
  
  2) String haystack from index i with length the same as needle’s length

  Note that the complexity of this solution is O(M*N) where M is length of haystack and N is length of needle.
*/
int Solution::strStr(const string A, const string B){
  int n_hz=A.length();
  int n_nz=B.length();
  int start=0, tempstart=start;
  int j=0;
  while(tempstart<n_hz && j<n_nz){
    if(A[tempstart]==B[j]){
      tempstart++;
      j++;
    }
    else{
      j=0;
      tempstart=++start;
    }
    if(j==n_nz){
       return start;
    }
  }
  return -1;
}
