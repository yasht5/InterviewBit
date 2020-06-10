/*
  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

  Example:

  "A man, a plan, a canal: Panama" is a palindrome.

  "race a car" is not a palindrome.

  Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/
bool alphanum(char c){
  if(('0'<= c && c<='9') || ('a'<=c && c<='z'))
    return 1;
  return 0;
}
int Solution::isPalindrome(string A){
  int l=0;
  int h=A.size()-1;
  while(l<=h){
    if(!alphanum(tolower(A[l])))
      l++;
    else if(!alphanum(tolower(A[h])))
      h--;
    else if(tolower(A[l])==tolower(A[h])){
      l++;
      h--;
    }
    else
      return 0;
  }
  return 1;
}

// This apporach takes O(LogN) time.

