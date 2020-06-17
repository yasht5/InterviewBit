/*
  Validate if a given string is numeric.

  Examples:

  "0" => true
  " 0.1 " => true
  "abc" => false
  "1 a" => false
  "2e10" => true
  Return 0 / 1 ( 0 for false, 1 for true ) for this problem

  Clarify the question using “See Expected Output”

  1.  Is 1u ( which may be a representation for unsigned integers valid?
      For this problem, no.
  2.  Is 0.1e10 valid?
      Yes
  3  -01.1e-10?
      Yes
  4.  Hexadecimal numbers like 0xFF?
      Not for the purpose of this problem
  5.  3. (. not followed by a digit)?
      No
  6.  Can exponent have decimal numbers? 3e0.1?
      Not for this problem.
  7.  Is 1f ( floating point number with f as prefix ) valid?
      Not for this problem.
  8.  How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
      Not for this problem. 
  9.  How about integers preceded by 00 or 0? like 008?
      Yes for this problem
*/
/*
  Approach:
  To start with, make sure you skip the whitespaces.

  Then ignore the ‘+’ or ‘-‘ sign.

  Scan the following string till you find numbers and ‘.’ and confirm at least one digit, less than one ‘.’ and the string not ending with ‘.’.

  Now the remaining string could have ‘e’ followed by a number.

  Confirm if the next character is ‘e’, then again repeat the process of skipping the sign and looking for digits.
*/
//useful set {., +, -, e, [0,9]}
int Solution::isNumber(const string &S) 
        {
            const char *s = S.c_str();
            int i = 0;

            // skip the whilespaces
            while (s[i] == ' ') { 
                i++;
            }
            if (s[i] == '\0') return false;

            // check the significand
            if (s[i] == '+' || s[i] == '-') i++; // skip the sign if exist
            int num_digits, num_points;
            for (num_digits=0, num_points=0; (s[i] <= '9' && s[i] >= '0') || s[i]=='.'; i++) {
                if (s[i] == '.') {
                    num_points++;
                } else {
                    num_digits++;
                }
            }

            // no more than one point, at least one digit. Should not end with .
            if (num_points > 1 || num_digits < 1 || s[i - 1] == '.') 
                return false;

            // check the exponent if exist
            if(s[i] == 'e') {
                i++;
                if (s[i] == '+' || s[i] == '-') i++; // skip the sign

                num_digits = 0;
                while (s[i] >= '0' && s[i] <= '9') { 
                    i++; 
                    num_digits++;
                }

                if (num_digits < 1)
                    return false;
            }

            // skip the trailing whitespaces
            while (s[i] == ' ') {
                i++;
            }

            return s[i] == '\0';  // must reach the ending \0 of the string
        }
  
  /*
  int Solution::isNumber(const string A) {
 int i=0;
 int len=A.length();
 int flag=0;
 while(A[i]==' ' && i<len)
  i++;
 while(i<len)
  {
      flag=1;
      if((A[i]>='0' && A[i]<='9') || (A[i]=='.')||(A[i]=='-' && i==0)|| (A[i]==' '))
       i++;
      else if(A[i]=='e' && A[i-1]!='.')
       {
           i++;
           while(A[i]!='.' && i<len)
            i++;
           if(i!=len)
            return 0;
       }
      else
       return 0;
  }
  if(A[i-1]!='.' && flag)
   return 1;
  return 0;
}
Above solution is O(N).
*/ 
