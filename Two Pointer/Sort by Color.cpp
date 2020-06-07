/*
  Given an array with n objects colored red, white or blue,
  sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

  Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

  Note: Using library sort function is not allowed.

  Example :

  Input : [0 1 2 0 1 2]
  Modify array so that it becomes : [0 0 1 1 2 2]
*/

//Approach-1 Count the number of zeros, ones and two's in one pass and then in second pass resize the array.

/* Approach-2
  Swap the 0s to the start of the array maintaining a pointer, and 2s to the end of the array.
  1s will automatically be in their right position. 
*/

void Solution::sortColors(vector<int> &A){
  int n=A.size();
  int cnt0=0;
  int cnt1=0;
  int cnt2=0;
  for(int i=0;i<n;i++){
    if(A[i]==0) cnt0++;
    else if(A[i]==1) cnt1++;
    else cnt2++;
  }
  int i=0;
  while(cnt0>0){
    A[i]=0;
    i++;
    cnt0--;
  }
  while(cnt1>0){
    A[i]=1;
    i++;
    cnt1--;
  }
  while(cnt2>0){
    A[i]=2;
    i++;
    cnt2--;
  }
}

/*
  void Solution::sortColors(vector<int> &A) {
    int i,j=-1,k=-1;
    for(i=0;i<A.size();i++)
    {
        if(A[i]==0)
        {
            A[i]=A[k+1];
            A[k+1]=A[j+1];
            A[j+1]=0;
            j++;k++;
        }
        else if(A[i]==1)
        {
            A[i]=A[k+1];
            A[k+1]=1;
            k++;
        }
        else
        {
            A[i]=2;
        }
    }
}
*/
/*
  void Solution::sortColors(vector<int> &A){
    int low=0, mid=0;
    int high=A.size()-1;
    while(mid<=high){
      switch(A[mid]){
        case 0:
          swap(A[low], A[mid]);
          low++;
          mid++;
          break;
        case 1:
          mid++;
          break;
        case 2:
          swap(A[mid], A[high]);
          high--;
          break;
      }
    }
  }
*/
