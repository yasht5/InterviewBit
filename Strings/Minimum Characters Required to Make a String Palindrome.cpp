/*
  Given an string A. The only operation allowed is to insert characters in the beginning of the string.

  Find how many minimum characters are needed to be inserted to make the string a palindrome string.



  Input Format

  The only argument given is string A.
  Output Format

  Return the minimum characters that are needed to be inserted to make the string a palindrome string.
  For Example

  Input 1:
      A = "ABC"
  Output 1:
      2 
      Explanation 1:
          Insert 'B' at beginning, string becomes: "BABC".
          Insert 'C' at beginning, string becomes: "CBABC".

  Input 2:
      A = "AACECAAAA"
  Output 2:
      2
      Explanation 2:
          Insert 'A' at beginning, string becomes: "AAACECAAAA".
          Insert 'A' at beginning, string becomes: "AAAACECAAAA".
*/
/*
  This Problem is KMP String algorithm problem.
  Approach:
  Each index of LPS array contains the longest prefix which is also a suffix. 
  Now take the string and reverse of a string and combine them with a sentinal character in between them and compute the LPS array of this combined string. 
  Now take the last value of the LPS array and subtract it with the length of the original string, 
  This will give us the minimum number of insertions required in the begining of the string .
*/  
 int Solution::solve(string A){
  int n=A.length();
  int x=1; //x=0;
  if(n==0) return 0;
  for(int i=1 //i=0;;i<n;i++){
    // Idea is to find longest palindrome length starting from index 1 . Differece of this length from string length is the required value
    //If you want to start from index 0 then use x=0 and pass return result as n-1-x.
    int start=0, end=i, p=1;
    while(start<=end){
      if(A[start]!=A[end]){
        p=0;
        break;
      }
      start++;
      end--;
    }
    if(p)
      x=i+1; //x=i;
  }
  return n-x; //n-x-1;
}
// This O(N) time solution.        
