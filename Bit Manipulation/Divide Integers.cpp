/*
  Divide two integers without using multiplication, division and mod operator.

  Return the floor of the result of the division.

  Example:

  5 / 2 = 2
  Also, consider if there can be overflow cases. For overflow case, return INT_MAX.

  Note: INT_MAX = 2^31 - 1  
  
*/
/*Approach 
  dividend = divisor*quotient + remainder
  As every number can be expressed in binary, represent quotient in binary form by using shift operators as given below:
  1. Determine most significant bit in quotient. This can be easily calculated by iterating o bit position from 31 to 1.
  2. Find the first bit for which divisor<<i is less than dividend and keep updating ith bit for which it is true.
  3. Add result in temp variable for checking net position such that (temp + (divisor<<i)) < dividend.
  4. Return final answer of quotient after updating with corresponding sign.
  
*/
int Solution::divide(int A, int B){
  if(A==0 && B==0) return INT_MAX;
  if(A==0) return 0;
  if(B==0) return INT_MAX;
  long long dividend=A;
  long long divisor=B;
  int sign=((dividend<0)^(divisor<0))? -1 : 1;
  if(dividend<0) dividend*=-1;
  if(divisor<0) divisor*=-1;
  divisor = abs(divisor);
  long long quotient=0, temp=0;
  for(int i=31;i>=0;i--){
    if((temp+(divisor<<i))<=dividend){
      temp += divisor<<i;
      quotient |= 1LL<<i;
    }
  }
  return (sign*quotient>=INT_MAX || sign*quotient<INT_MIN) ? sign*INT_MAX : sign*quotient;
}
// Time complexity id O(log(a)).
/*
  int Solution::divide(int A, int B){
    long logn ans=0;
    long long a=A, b=B;
    bool neg =false;
    if(a<0 && b<0){ a*=-1; b*=-1;}
    else if(a<0){
      neg=true;
      a*=-1;
    }
    else if(b<0){
      neg=true;
      b*=-1;
    }
    while(true){
      long long temp=b;
      long long count=0;
      while(a>=temp){
        if(count==0) count++;
        else
          count=count<<i;
      }
      temp=temp>>1;
      ans+=count;
      a=a-temp;
      if(a<b) break;
   }
   if(neg) ans*=-1;
   if(ans<INT_MIN || ans>INT_MAX)
    ans=INT_MAX;
   return ans;
  }
*/
