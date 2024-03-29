/*
  Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.

  Input Format:

    First and only argument of input contains an integer array A
  Output Format:

    return a single integer denoting minimum xor value
  Constraints:

  2 <= N <= 100 000  
  0 <= A[i] <= 1 000 000 000
  For Examples :

  Example Input 1:
    A = [0, 2, 5, 7]
  Example Output 1:
    2
  Explanation:
    0 xor 2 = 2
  Example Input 2:
    A = [0, 4, 7, 9]
  Example Output 2:
    3
*/
int Solution::findMinXor(vector<int> &A){
  sort(A.begin(), A.end());
  int ans=INT_MAX;
  int x;
  for(int i=0;i<A.size();i++){
      x=A[i]^A[i+1];
      ans=min(ans, x);
  }
  return ans;
}
// The above solution is of O(NlogN) complexity.
