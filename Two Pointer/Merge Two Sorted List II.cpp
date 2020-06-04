/*Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
TIP: C users, please malloc the result into a new array and return the result. 
If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

Example :

Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]
*/

//Approach-1:

void Solution::merge(vector<int> &A, vector<int> &B){
  for(int i=0;i<B.size();i++){
    A.push_back(B[i]);
  }
  sort(A.begin(), A.end());
}

//Approach-2
void Solution::merge(vector<int> &A, vector<int> &B)[
  int i=A.size()-1;
  int j=B.size()-1;
  int last = A.size()+B.size()-1;
  //Resize the original vector
  A.resize(A.size()+B.size());
  //Start a loop to fill the new array from largest element to smallest element.
  while(j>=0){
    //Check for bound on i for A.
    if(i>=0 && A[i]>B[j]){
      A[last]==A[i];
      last--;
      i--;
    }
    else{
      A[last]=B[j];
      last--;
      j--;
    }
  }
}
