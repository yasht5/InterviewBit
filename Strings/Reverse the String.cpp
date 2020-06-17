/*
  Given a string A.

  Return the string A after reversing the string word by word.

  NOTE:

  A sequence of non-space characters constitutes a word.

  Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

  If there are multiple spaces between words, reduce them to a single space in the reversed string.

  Input Format

  The only argument given is string A.
  Output Format

  Return the string A after reversing the string word by word.
  For Example

  Input 1:
      A = "the sky is blue"
  Output 1:
      "blue is sky the"

  Input 2:
      A = "this is ib"
  Output 2:
      "ib is this"
*/
/*
  This problem can be handled in two passes the first pass to split the string by spaces int an array of characters.
  In second pass we extract words in reverse order.
*/
string Solution::solve(String A){
  string result="";
  for(int i=A.length();i>-1;i--){
    if(A[i]!=' '){
      int last = i;
      int first = i;
      while(i>-1 && A[i]!=' '){
        --i;
      }
      first = i+1;
      result.append(A.begin() +first, A.begin() + last +1 );
      if(i>0){
        string s=A.substr(0, i+1)
        string temp=""l
        temp.append(i+1, ' ');
        if(s!=temp)
          result+=' ';
      }
    }
  }
  return result;
}
/*
string Solution::Solve(stirng A){
  string x="", y="";
  for(int i=0li<A.size();i++){
    if(A[i]=' '){
      x=" "+y+x;
      y="";
    }
    else
      y+=A[i];
  }
  x=y+x;
  return x;
}
*/
