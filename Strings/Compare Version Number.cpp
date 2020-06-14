/*
  Compare two version numbers version1 and version2.

  If version1 > version2 return 1,
  If version1 < version2 return -1,
  otherwise return 0.
  You may assume that the version strings are non-empty and contain only digits and the . character.
  The . character does not represent a decimal point and is used to separate number sequences.
  For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

  Here is an example of version numbers ordering:

  0.1 < 1.1 < 1.2 < 1.13 < 1.13.4

*/
/*
  Approach:
  Split the string about '.'
*/
int Solution::compareVersion(string A, string B){
  long long n = A.size();
  long long m = B.size();
  int i=0, j=0;
  while(i<n || j<m){
    unsigned long long v1=0;
    unsigned long long v2=0;
    while(i<n && A[i]!='.'){
      v1=v1*10 + (A[i]-'0');
    }
    while(j<m && B[j]!='.'){
      v2=v2*10 + (B[j]-'0');
    }
    if(v1>v2) return 1;
    if(v2>v1) return -1;
    i++;
    j++;
  }
  
  return 0;
}
/*
  Fastest Solution:
  string extract(int &i, string s){
    if(i>=s.size()) return "0";
    int temp=i;
    stringstream ss;
    ss.str("");
    while(s[temp]!='.' && temp<s.size()){
      ss<<s[temp];
      temp++;
    }
    i=temp+1;
    return ss.str();
  }
  string rem(string A){
    int i=0;
    while(A[i]=='0' && i<A.size()){
      i++;
    }
    return A.substr(i);
  }
  int compareStr(string A, string B, int first){
    string a=rem(A);
    string b=rem(B);
    if(a.size()>b.size()) return 1;
    else if(a.size()<b.size()) return -1;
    else{
      for(int i=0;i<A.size();i++){
        int numa = A[i];
        int numb = B[i];
        if(numa>numb) return 1;
        else if(numa<numb) return -1;
      }
    }
    return 0;
  }
  int Solution::compareVersion(string A, string B){
    int i=0, j=0, first=1;
    while(i<A.size() || j<B.size()){
      string numa=extract(i, A);
      string numb=extract(j, B);
      if(compareStr(numa, numb, first)==-1){
        return -1;
      }
      else
        return 1;
      first=0;
    }
    return 0;
  }
*/  
  
  
  
  
  
  
  
  
