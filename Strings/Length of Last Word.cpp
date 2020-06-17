/*
    Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

  If the last word does not exist, return 0.

  Note: A word is defined as a character sequence consists of non-space characters only.

  Example:

  Given s = "Hello World",

  return 5 as length("World") = 5.

  Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.
*/
// This solution is of O(N) tiem complexity.
int Solution::lengthOfLastWord(const string A){
  int n=A.length();
  if(n==0) return 0;
  int j=n-1;
  while(A[j]==' ' && j>=0){
    j--;
  }
  if(A[j]!=' '){
    while(A[j]!=' ' &&j>=0){
      ans+=A[j];
      j--;
    }
  }
  return ans.length();
}
