/*
  Validate if a given string is numeric.

  Examples:

  "0" => true
  " 0.1 " => true
  "abc" => false
  "1 a" => false
  "2e10" => true
  Return 0 / 1 ( 0 for false, 1 for true ) for this problem

  Clarify the question using “See Expected Output”

  1.  Is 1u ( which may be a representation for unsigned integers valid?
      For this problem, no.
  2.  Is 0.1e10 valid?
      Yes
  3  -01.1e-10?
      Yes
  4.  Hexadecimal numbers like 0xFF?
      Not for the purpose of this problem
  5.  3. (. not followed by a digit)?
      No
  6.  Can exponent have decimal numbers? 3e0.1?
      Not for this problem.
  7.  Is 1f ( floating point number with f as prefix ) valid?
      Not for this problem.
  8.  How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
      Not for this problem. 
  9.  How about integers preceded by 00 or 0? like 008?
      Yes for this problem
*/
/*
  Approach:
  To start with, make sure you skip the whitespaces.

  Then ignore the ‘+’ or ‘-‘ sign.

  Scan the following string till you find numbers and ‘.’ and confirm at least one digit, less than one ‘.’ and the string not ending with ‘.’.

  Now the remaining string could have ‘e’ followed by a number.

  Confirm if the next character is ‘e’, then again repeat the process of skipping the sign and looking for digits.
*/
//useful set {., +, -, e, [0,9]}
bool isNum(char c){
  return (c>='0' && c<='9') ? true : false;
}
bool usefulset(char c){
  if(c=='+' || c=='-' || c=='e' || isNum(c)) return true;
  return false;
}
int Solution::isNumber(const string A){
  int i=0;
  int j=A.length()-1;
  while(i<A.length() && A[i]==' ')  
    i++;
  while(j>=0 && A[j]==' ')
    j--;
  if(i>j) return 0;
  // If string is of length 1 and the character is not digit return 0
  if(i==j && !(A[i]>='0' && A[i]<='9')) 
    return 0;
  // If first character is not from useful set return 0.
  if(A[i]!='.' && A[i]!='+' && A[i]!='-' && A[i]!='e' && !(A[i]>='0' && A[i]<='9'))
    return 0;
  bool dot_e = false;
  for(;i<=j;i++){
    if(A[i]!='+' && A[i]!='-' && A[i]!='e' && !(A[i]>='0' && A[i]<='9'))
      return 0;
    if(A[i]=='.'){
      if(dot_e==true) return 0;
      if(i+1>A.length()) return 0;
      if(!isNum(A[i])) return 0;
    }
    else if(A[i]=='e'){
      dot_e=true;
      if(!isNum(A[i-1])) return 0;
      if(i+1>A.length()) return 0;
      if(A[i+1]!='+' && A[i+1]!='-' && !(A[i+1]>='0' && A[i+1]<='9')) return 0;
    }
  }
  return 1;
}
  
  
  
  
