/*
  Implement atoi to convert a string to an integer.

  Example :

  Input : "9 2704"
  Output : 9
  Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

  Questions: Q1. Does string contain whitespace characters before the number?
  A. Yes Q2. Can the string have garbage characters after the number?
  A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
  A. Return 0. Q4. What if the integer overflows?
  A. Return INT_MAX if the number is positive, INT_MIN otherwise. 
  Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.
  If you do, we will disqualify your submission retroactively and give you penalty points.
*/
int Solution::atoi(const string A){
  int i=0, sign=1, base=0;
  while(isspace(A[i]))
    i++;
  if(A[i]=='+' || A[i]=='-'){
    sign=(A[i++]=='+')?1:-1;
  }
  while(A[i]>='0' && A[i]<='9'){
    if(base>INT_MAX/10 || (base==INT_MAX/10 && A[i]-'0'>7)){
      if(sign==1) return INT_MAX;
      else return INT_MIN;
    }
    base = base*10 + (A[i++]-'0');
  }
  return base*sign;
}
/*
    bool isnum(char c){
       return ('0'<=c && c<='9')?true:false;
    }
    int Solution::atoi(const string A) {
      long long int num=0;
      int i=0;
      bool isNegative=false;
      while(i<A.size() && isspace(A[i])){
         i++;
      }
      if(i<A.size() && (A[i]=='+' || A[i]=='-')){
         if(A[i]=='-'){
             isNegative=true;
         }
         i++;
      } 
      for(;i<A.size();i++){
          if(!isnum(A[i]) || isspace(A[i]))
            break;
          if(num*10 + (A[i]-'0')>INT_MAX)
            return isNegative?INT_MIN:INT_MAX;
          num=num*10 + (A[i]-'0');
      }
      return isNegative?-1*num:num;
    }
*/
