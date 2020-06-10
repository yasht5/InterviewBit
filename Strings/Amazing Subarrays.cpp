/*
  You are given a string S, and you have to find all the amazing substrings of S.

  Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).

  Input

  Only argument given is string S.
  Output

  Return a single integer X mod 10003, here X is number of Amazing Substrings in given string.
  Constraints

  1 <= length(S) <= 1e6
  S can have special characters
  Example

  Input
      ABEC

  Output
      6

  Explanation
	  Amazing substrings of given string are :
	  1. A
	  2. AB
	  3. ABE
	  4. ABEC
	  5. E
	  6. EC
	  here number of substrings are 6 and 6 % 10003 = 6.

*/
/*  Approach:
  Traverse the string and when you encounter a vowel, add ( length(string) - position_of_curr_char ) to the answer.
*/

#define MOD 10003
bool isVowel(char c){
  if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
    return 1;
  return 0;
}
int Solution::solve(string A){
  int n = A.length();
  int sum=0;
  for(int i=0;i<n;i++){
    A[i]=tolower(A[i]);
    if(isVowel(A[i]))
      sum+=n-i;
  }
  return sum%MOD;
}
// This approach is O(N) in time complexity.
/*
  NAIVE APPROACH
  #define MOD 10003
  bool isVowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
      return 1;
    return 0;
  }
  int Solution::solve(string A){
    int n=A.length();
    vector<string> v;
    for(int i=0;i<n;i++){
      A[i]=tolower(A[i]);
      if(isVowel(A[i]){
        string s="";
        for(int j=i;j<n;j++){
          s+=A[j];
          v.push_back(s);
        }
      }
    }
    return v.size()%MOD;
  }
*/
