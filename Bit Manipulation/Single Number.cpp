/*
  Given an array of integers, every element appears twice except for one. Find that single one.

  Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

  Input Format:

      First and only argument of input contains an integer array A
  Output Format:

      return a single integer denoting single element
  Constraints:

  2 <= N <= 2 000 000  
  0 <= A[i] <= INT_MAX
  For Examples :
  
  Example Input 1:
      A = [1, 2, 2, 3, 1]
  Example Output 1:
      3
  Explanation:
      3 occurs only once
  Example Input 2:
      A = [1, 2, 2]
  Example Output 2:
      1
*/
/*
  If non repeating number X has 1 in that position we will have odd number of ones or If X has 0 in that position we will have odd number of 0's in that position.
  If you look at the bit operator XOR is exactly what we need.
  XOR will return 1 only when two different bits occur and all even occurrence will cancel out using XOR.
  A ^ A = 0 and A ^ B ^ A = B.
*/
int Solution::singleNumber(const vector<int> &A){
  if(A.size()==0) return 0;
  int number=A[0];
  for(int i=1;i<A.size();i++){
    number=number^A[i];
  }
  return number;
}
Time complexity O(N).
