/*
  Given a string S, find the longest palindromic substring in S.

  Substring of string S:

  S[i...j] where 0 <= i <= j < len(S)

  Palindrome string:

  A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

  Incase of conflict, return the substring which occurs first ( with the least starting index ).

  Example :

  Input : "aaaabaaa"
  Output : "aaabaaa"
*/
/*  
  Approach
  1. Brute force solution, O(N^3):
    The obvious brute force solution is to pick all possible starting and ending positions for a substring, and verify if it is a palindrome. There are a total of C(N, 2) such substrings (excluding the trivial solution where a character itself is a palindrome).

    Since verifying each substring takes O(N) time, the run time complexity is O(N^3).
  2. Dynamic Programming.
     We maintain a boolean table[n][n] that is filled in bottom up manner. The value of table[i][j] is true, 
     if the substring is palindrome, otherwise false. To calculate table[i][j], we first check the value of table[i+1][j-1], 
     if the value is true and str[i] is same as str[j], then we make table[i][j] true. 
     Otherwise, the value of table[i][j] is made false.
     This soution O(N^2) in time and O(N^2) in auxiliary space.
  3. We can solve it O(N^2) time and O(1) space.
     We observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only 2N-1 such centers.
  4. We can reduce the time to complexity to O(N) and space complexity to O(1) using Manacher's algorithm.
*/
string Solution::longestPalindrome(string A){
  int start=0;
  int n=A.length();
  int maxLen=1;
  int low=0, high;
  for(int i=0;i<n;i++){
    low=i-1; high=i;
    while((low>=0) && high<n && A[low]==A[high]){
      if(high-low+1>maxLen){
        maxLen=high-low+1;
        start=low;
      }
      low--;
      high++;
    }
    low=i-1;
    high=i+1;
    while(low>=0 && high<n && A[low]==A[high]){
      if(high-low+1>maxLen){
        maxLen=high-low+1;
        start=low;
      }
      low--;
      high++;
    }
  }
  string sol="";
  high=start+maxLen;
  while(start!=high){
    sol+=A[start];
    start++;
  }
  return sol;
}

/*
  DP Solution:
  string Solution::longestPalindrome(string A){
    int n=A.length();
    bool table[n][n]={0};
    int maxLen=1;
    for(int i=0;i<n;i++){
      table[i][i]=true;
    }
    int start=0;
    for(int i=0;i<n-1;i++){
      if(S[i]==s[i+1]){
        table[i][i+1]=true;
        start=i;
        maxLen=2;
      }
    }
    for(int k=3;k<=n;k++){
      for(int i=0;i<n-k+1;i++){
        int j=i+k-1;
        if(table[i+1][j-1] && s[i]==s[j]){
          table[i][j]=true;
          if(k>maxLen){
            start=i;
            maxLen=k;
          }
        }
      }
    }
    return maxLen;
  }
*/
  
    
    
 
