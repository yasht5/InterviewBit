/*
Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:

1
Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.
*/
/* Approach
  In every step, the only possible way to decrease the difference is to decrease the maximum element out of the three elements of the arrays.
*/
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C){
  int minima=INT_MAX, current, maxima;
  int i=A.size()-1;
  int j=B.size()-1;
  int k=C.size()-1;
  while(i!=-1 && j!=-1 && k!=-1){
    current = abs(max(A[i], max(B[j], c[k])) - min(A[i], min(B[j], C[k])));
    if(current<minima){
      minima = current;
    maxima=max(A[i], max(B[j], c[k]));
    //updating the indexes of arrays based on maxima.
    if(A[i]==maxima) i--;
    else if(B[j]==maxima)j--;
    else k--;
  }
  return minima;
}
