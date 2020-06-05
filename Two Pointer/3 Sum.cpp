/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution

Example:
given array S = {-1 2 1 -4},
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
*/
/*Approach
  1. Use three loops to fit the answer.
     This solution will rum O(N^3) time complexity.
  2. Start by sorting the array and try to fix the least integer by treaversing it.
     Now find the pair of integers j & k such that A[j]+A[k] is closest to (target - A[i]) since A[i]+A[j]+A[k]=target.]
     This solution will takeO(logN) time for sorting and O(N^2) time for calculating the best sum.
     So total time complexity will be O(N^2Log(N)).
*/
int Solution::threeSumClosest(vector<int> &A, int B){
  //If array does not contain three elements.
  if(A.size()<3)
    return 0;
  sort(A.begin(), A.end());
  int n=A.size();
  int i=0, l=n-1;
  int sum=0;
  int diff=INT_MAX;
  while(i<n-2){
    int left = i+1, right = n-1;
    while(left<right){
      int temp = A[i]+A[left]+A[right];
      int d=abs(B-temp);
      if(d==0)
        return B;
      if(d<diff){
        diff=d;
        sum=temp;
      }
      if(temp<B){
        left++;
      }else{
        right--;
      }
   }
   i++;
 }
 return sum;
}



/*
int Solution::threeSumClosest(vector<int> &A, int B){
  if(A.size()<3)
    return 0;
  sort(A.begin(), A.end());
  int bestsum=INT_MAX;
  int sum=0;
  for(int i=0;i<n-2;i++){
    int ptr1=i+1, ptr2=n-1;
    while(ptr1<ptr2){
      sum=A[i]+A[ptr1]+A[ptr2];
      if(abs(B-sum)<abs(B-bestsum)){
        bestsum=sum;
      }
      if(sum>target)
        ptr2--;
      else
        ptr1++;
    }
  }
  return bestsum;
}
  The above the solution is O(N^2LogN).
*/
