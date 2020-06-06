/*
  You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
  Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.

  Notes:

  You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.

  Return answer modulo 109 + 7.

  For example,

  A = [1, 1, 1, 2, 2]

  Return: 4
*/
/* Approach
   We will sort the array so that Ai < Aj< Ak for i<j<k and then we will fix a maximum edge and then check if Ai+Aj>Ak.
   This solution will be of O(N^2) time complexity.
*/


#define MOD 1000000007
int Solution::nTriang(vector<int> &A){
  int n=A.size();
  long long int ans=0;
  //If array does not conatin three elements return 0
  if(n<3)
    return 0;
  //Sort the given array.
  sort(A.begin(), A.end());
  for(int k=n-1;k>=0;k--){
    int i=0;
    int j=k-1;
    while(i<j){
      long long maxi = A[k];
      long long minimSum = A[i]+A[j];
      if(minimSum>maxi){
        ans=(ans+(j-i)%MOD)%MOD;
        j--;
      }
      else
        i++;
    }
  }
  return ans;
}
