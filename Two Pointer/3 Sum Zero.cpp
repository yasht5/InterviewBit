/*
  Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2) 

*/
/* Approach
Firstly sort the array and fix a minimum integer ( say A[i]) and for corresponding minimum element iterate using two the remaining elements 
(say A[j] & A[k]) such that A[j]+A[k]=-A[i].
*/
/*Important check for 32 bit and 64 bit numbers.*/

vector<vector<int>> Solution::threeSum(vector<int> &A){
  int i=0;
  int j=0;
  int k=0;
  vector<vector<int>> ans;
  map<vector<int>, bool> m;
  //If size of array is less than three.
  if(A.size()<3)
    return ans;
  sort(A.begin(), A.end());
  int n=A.size();
  for(i=0;i<n-2;i++){
    j=i+1;
    k=n-1;
    while(j<k){ 
      long long sum = 0LL+A[i]+A[k]+A[j]; //Convert the sum to long long otherwise overflow may occur.
      if(sum<0)
        j++;
      else if(sum>0)
        k--;
      else{
        vector<int> temp;
        temp.push_back(A[i]);
        temp.push_back(A[j]);
        temp.push_back(A[k]);
        if(m.find(temp)==m.end()){
          m[temp]=m[temp]+1;
          ans.push_back(temp);
        }
        j++;
        k--;
      }
    }
  }
  return ans;
}
