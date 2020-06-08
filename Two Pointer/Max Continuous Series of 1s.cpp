/*
  You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
  Find the position of zeros which when flipped will produce maximum continuous series of 1s.

  For this problem, return the indices of maximum continuous series of 1s in order.

  Example:

  Input : 
  Array = {1 1 0 1 1 0 0 1 1 1 } 
  M = 1

  Output : 
  [0, 1, 2, 3, 4] 

  If there are multiple possible solutions, return the sequence which has the minimum start index.

*/
/*
  Use double pointer method.
  pointer i and j 
        i = j = 0
        iterate till i < N:
        if(Number_of_Zeros_in_Current_range > M) :
                increment j and reduce range till Number_of_Zeros_in_current_range < M
        else :
                add element in range and update all variables
– While zeroCount is no more than m: expand the window to the right (wR++) and update the count zeroCount.
– While zeroCount exceeds m, shrink the window from left (wL++), update zeroCount;
– Update the widest window along the way. The positions of output zeros are inside the best window.
This is an O(N) time approach and O(1) space approach.
*/

vector<int> Solution::maxone(vector<int> &A, int B){
  int i=0, j=0;
  int best =INT_MIN;
  int n=A.size();
  int count0=0;
  int l=0;
  vector<int> res;
  while(j<n){
    if(count0<=B){
      if(A[j]==0) count0++;
      j++;
    }
    if(count0>B){
      if(A[i]==0) count0--;
      i++;
    }
    if((j-i)>best && count0<=B){
      best=j-i;
      l=i;
    }
  }
  for(int i=0;i<best;i++){
    res.push_back(l+i);
  }
  return res;
}

/*
  vector<int> Solution:: maxone(vector<int> &A, int B){
    int l=0, r=0;
    int max=0, count=0;
    int wl=0, wr=0;
    int flag=0;
    while(wr<A.size()){
      if(A[wr]==0) count++;
      if(count>B){
        if(A[wl]==0){
          count--;
        }
        wl++;
      }
      if(wr-wl+1>max){
        max=wr-wl+1;
        r=wr;
        l=wl;
        flag=1;
      }
      wr++;
   }
   vector<int> res(max);
   if(flag==1){
    for(int i=l;i<=r;i++){
      v[i-l]=1;
    }
   }
   return res;
 }
*/ 
