/*
  We define f(X, Y) as number of different corresponding bits in binary representation of X and Y. For example, f(2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively. The first and the third bit differ, so f(2, 7) = 2.

  You are given an array of N positive integers, A1, A2 ,…, AN. Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer modulo 109+7.

  For example,

  A=[1, 3, 5]

  We return

  f(1, 1) + f(1, 3) + f(1, 5) + 
  f(3, 1) + f(3, 3) + f(3, 5) +
  f(5, 1) + f(5, 3) + f(5, 5) =

  0 + 1 + 1 +
  1 + 0 + 2 +
  1 + 2 + 0 = 8 .
*/
/*
  Assume that all bits are 0 or 1 in input(i.e, Ai=0 or Ai=1). Let say A= count of bits which are 0
  B= count of bits which are 1
  In this case our answer is 2AB since each such pair contributes 1 to answer
  Since A is an integer we just have to do this with 31 bits so our solution is O(31*N).
*/
#define MOD 1000000007
int Solution::cntBits(vector<int> &A){
  long long int ans=0;
  for(int i=0;i<31;i++){
    int count=0;
    for(int j=0;j<A.size();j++){
      if(A[j] & 1<<i){
        count++;
      }
    }
    ans+=(count*(A.size()-count)*2); //(Number of 0's)*(Number of 1's)*2
    ans=ans%MOD;
  }
  return ans;
}
    
