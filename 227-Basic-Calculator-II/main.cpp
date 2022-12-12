//With a stack
/*
Time Complexity = O(N)
Space Complexity = O(N)
where n is the size of the given string.
*/

class Solution {
public:
    int calculate(string s) {
        if (s.length() == 0) {
            return 0;
        }

        //s = s.trim() // Not possible maybe use lambda?
        
        stack <int> st;
        int result = 0;
        int curr=0;
        char lastSign = '+';
        for (int i=0;i<s.length();i++) {
            //iterate over each character of the string s
            
            if(isdigit(s[i])){
                curr = (curr*10)+(s[i]- '0'); // latter part to get the ascii value of the digit //be careful -> '0'
            } 
            
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.length()-1) {
                // we need to skip spaces if they occur
                //for the last char we have to calc the value which might be a digit hence to pass that through this loop we do || case
                // thats why if not elif
                
                if (lastSign == '+') {
                    st.push(curr);
                }
                
                else if (lastSign == '-') {
                    st.push(-1*curr);
                }
                
                else if (lastSign == '*') {
                    //In order to follow BODMAS/PEMDAS rule
                    int temp = st.top()*curr;
                    st.pop();
                    st.push(temp);
                    
                }
                // else { //Imporatant follow up if curr becomes 0 then what
                //     if(curr!=0 ) {
                //     int temp = st.top()/curr;
                //     st.pop();
                //     st.push(temp);
                //     else {
                //     return INT_MAX; 
                //      }
                //   }
                //}
                else if (lastSign == '/') {
                    //tail is the mess that we create previously
                    int temp = st.top()/curr;
                    st.pop();
                    st.push(temp);
                }
                
                lastSign = s[i]; // update the lastSign with the current character
                curr = 0; //reset the curr
            }
        }
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};


/*
Time Complexity = O(N)
Space Complexity = O(1)
where n is the size of the given string.
*/


class Solution {
public:
    int calculate(string s) {
        if (s.length() == 0) {
            return 0;
        }

        //s = s.trim() // Not possible maybe use lambda?
        
        int curr=0,calc=0,tail=0;
        char lastSign = '+';
        for (int i=0;i<s.length();i++) {
            //iterate over each character of the string s
            
            if(isdigit(s[i])){
                curr = (curr*10) +(s[i]- '0'); // latter part to get the ascii value of the digit
            } 
            
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.length()-1) {
                // we need to skip spaces if they occur
                //for the last char we have to calc the value which might be a digit hence to pass that through this loop we do || case
                // thats why if not elif
                
                if (lastSign == '+') {
                    calc = calc+curr;
                    tail = curr;
                }
                
                if (lastSign == '-') {
                    calc = calc-curr;
                    tail = -curr;
                }
                
                if (lastSign == '*') {
                    //tail is the mess that we create previously
                    //In order to follow BODMAS/PEMDAS rule
                    calc = (calc-tail) + (tail*curr);
                    tail = tail*curr;
                }
                // else { //Imporatant follow up if curr becomes 0 then what
                //     if(curr!=0 ) {
                //      //tail is the mess that we create previously
                //      calc = (calc-tail) + (tail/curr);
                //      tail = tail/curr;
                //     else {
                //     return INT_MAX; 
                //      }
                //   }
                //}
                if (lastSign == '/') {
                    //tail is the mess that we create previously
                    calc = (calc-tail) + (tail/curr);
                    tail = tail/curr;
                }
                
                lastSign = s[i]; // update the lastSign with the current character
                curr = 0; //reset the curr
            }
        }
        return calc;
    }
};