/*
  Given a string containing only digits, restore it by returning all possible valid IP address combinations.

  A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

  Example:

  Given “25525511135”,

  return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)
*/
// we have to place three dots in middle in the given string and then check if it is a valid IP address or not.
//This solution will be of O(N^3) time complexity.
int generate(string s, int i, int j){
  int ans=0;
  for(int idx=i;idx<j;idx++){
    ans=ans*10 + (s[idx]-'0');
  }
  return ans;
}
bool isValid(string s){
  int n=s.length();
  int i=0;
  while(i<n){
    int j=i;
    while(j<n && s[j]!='.'){
      j++;
    }
    if(j-i>3 || j-i==0){
      return false;
    }
    int num = generate(s, i, j):
    if(num>255){
      return false;
    }
    if(j-i>1 && (num==0 || s[i]=='0')){
      return false;
    }
    i=j+1;
  }
  return true;
}
string generateString(string s, int i, int j, int k){
  stirng temp;
  for(int idx=0; idx<s.length();idx++){
    temp=temp+s[idx];
    if(idx==i || idx==j ||idx==k){
      temp+='.';
    }
  }
  return temp;
}
vector<string> Solution::restoreIpAddresses(string A){
  int n=A.length();
  vector<string> ans;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n-1;j++){
      for(int k=j+1;k<n-1;k++){
        string s=generate(A, i, j, k);
        if(isValid(s)){
          ans.push_back(s);
        }
      }
    }
  }
  return ans;
}

/*
bool isValid(string s){
  if(s.size()>1 && s[0]=='0') return false;
  if(stoi(s)<=255 && stoi(s)>=0) return true;
  else 
    return false;
}
vector<string> Solution::restoreIpAddrresses(string A){
  vector<string> ans;
  if(A.size()>12 || A.size()<4) return ans;
  for(int i=1;i<4;i++){
    string first=A.substr(0,i);
    if(!isValid(first)) continue;
    for(int j=1;i+j<A.size() && j<4;j++){
      string second=A.substr(i, j);
      if(!isValid(second)) continue;
      for(int k=1;i+j+k<A.size() && k<4;k++){
        string thrid=A.substr(i+j, k);
        string fourth=A.substr(i+j+k);
        if(isValid(third) && isValid(fourth)){
          string curr = first+"."+second+"."+third+"."+fourth;
          ans.push_back(curr);
        }
      }
    }
  }
  return ans;
}
*/


