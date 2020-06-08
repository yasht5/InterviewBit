/*
  Write a function that takes an unsigned integer and returns the number of 1 bits it has.

  Example:

  The 32-bit integer 11 has binary representation

  00000000000000000000000000001011
  so the function should return 3.

  Note that since Java does not have unsigned int, use long for Java
*/

int Solution::numSetBits(unsigned int A){
  int s=0;
  while(A){
    if(A&1)
      s++;
      A<<=1;
  }
  return s;
}

/*
  int Solution::numSetBits(unsigned int A){
    int total_ones=0;
    while(x!=0){
      x=x&(x-1);
      total_ones++;
    }
    return total_ones;
  }
*/
