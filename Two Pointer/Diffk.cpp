/*
  Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

  Example: Input : 
    A : [1 3 5] 
    k : 4
  Output : YES as 5 - 1 = 4 
  Return 0 / 1 ( 0 for false, 1 for true ) for this problem

  Try doing this in less than linear space complexity.
*/
int Solution::diffPossible(vector<int> &A, int B){
  //if array contains zero or one element than return false.
  if(A.size()==0 || A.size()==1)
    rerturn 0;
  int i=0, j=1;
  while(i<A.size() && j<A.size()){
    if(i!=j && A[j]-A[i]==B){
      return 1;
    }
    else if(A[j]-A[i]<B){
      j++;
    else
      i++;
  }
  return 0;
}  
