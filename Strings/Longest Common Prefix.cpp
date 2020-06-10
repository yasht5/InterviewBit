/*
  Given the array of strings A,
  you need to find the longest string S which is the prefix of ALL the strings in the array.

  Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1
  and S2.

  For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".



  Input Format

  The only argument given is an array of strings A.
  Output Format

  Return longest common prefix of all strings in A.
  For Example

  Input 1:
      A = ["abcdefgh", "aefghijk", "abcefgh"]
  Output 1:
      "a"
      Explanation 1:
          Longest common prefix of all the strings is "a".

  Input 2:
      A = ["abab", "ab", "abcd"];
  Output 2:
      "ab"
      Explanation 2:
          Longest common prefix of all the strings is "ab". 
          
*/
string commonpref(string A, string B){
  int n1=A.length();
  int n2=B.length();
  string res;
  for(int i=0, j=0; i<n1 && j<n2;i++,j++){
    if(A[i]!=B[i])
      break;
    res.push_back(A[i]); //res.psuh_back(B[j]);
  }
  return res;
}
string Solution::longestCommonPrefix(vector<string> &A){
  string x=A[0];
  for(int i=1;i<A.size();i++){
    x=commonpref(x, A[i]);
  }
  return x;
}

/*
  string Solution::longestCommonPrefix(vector<string> &strs) {
            if (strs.size() == 0) return "";
            string ans = "";
            for (int i = 0; i < strs[0].length(); i++) {
                // checking if character i qualifies to be in the answer. 
                bool isQualified = true; 
                for (int j = 1; j < strs.size(); j++) {
                    if (i >= strs[j].length() || strs[j][i] != strs[0][i]) {
                        isQualified = false;
                        break;
                    }
                }
                if (!isQualified) break;
                ans.push_back(strs[0][i]);
            }
            return ans;
  }
  */
