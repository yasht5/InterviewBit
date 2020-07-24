/*  There are two sorted arrays A and B of size m and n respectively.

    Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

    The overall run time complexity should be O(log (m+n)).

    Sample Input

    A : [1 4 5]
    B : [2 3]

    Sample Output

    3
    NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element.   
          For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5 
*/
double Solution::findMedianSortedArrays(const vector<int>&A, const vector<int> &B){
  if(A.size()>B.size())
    return findMedianSortedArray(B, A);
  int x=A.size();
  int y=B.size();
  
  int low=0;
  int high=x;
  while(low<=high){
    int partX=(low+high)/2;
    int partY=(x+y-1)/2-partX;
    
    int maxLeftX = (partX==0)?INT_MIN:A[partX-1];
    int minRightX = (patrX==x)>INT_MAX:A[partX];
    
    int maxLeftY = (partY==0)?INT_MIN:B[partY-1];
    int minRightY = (partY==y)?INT_MAX:B[party];
    if(maxLeftX<=minRightY && maxLeftY<=minRightX){
      if((x+y)%2==0)
        return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
      else
        return (double)(max(maxLeftX, maxLeftY));
    }
    else if(maxLeftX>minRightY)
      high = partX-1;
    else if(maxLeftY>minRightX)
      low = partX+1;
  }
  return 0.0;
}

/* Alternate Approach
  double Solution::findMedianSortedArray(vector<int>&A, vecotr<int>&B){
    int m=A.size();
    int n=B.size();
    if(m>n){
      vector<int> temp=A;
      A=B;
      B=temp;
      int t=m;
      m=n;
      n=t;
    }
    int iMin=0, iMaX=m, half = (m+n+1)/2;
    while(iMin<=iMax){
      int i=(iMin+iMax)/2;
      int j=half-i;
      if(i<iMax && B[j-1]>A[i])
        iMin = i+1;
      else if(i>iMin && A[i-1]>B[j])
        iMax=i-1;
      else{
        int maxLeft=0;
        if(i==0)
          maxLeft=B[j-1];
        else if(j==0)
          maxLeft=A[i-1];
        else
          maxLeft = max(A[i-1], B[j-1]);
        if((m+n)%2==1){
          return maxLeft;
        }
        int minRight=0;
        if(i==m)
          minRight = B[j];
        else if(j==n)
          minRight = A[i];
        else
          minRight = min(A[i], B[j]);
        return (maxleft+minRight)/2.0;
      }
    }
    return 0.0;
  }
      
      
