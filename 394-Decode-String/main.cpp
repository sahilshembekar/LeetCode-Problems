//BFS

/*
Time Complexity = O(K*N)
Space Complexity = O(K*N)
where K is the sum of the digits and N is the total number of characters.
*/
class Solution {
public:
    string decodeString(string s) {
        if(s.size() ==0 ) return "";
        
        int num=0;
        stack<int> numstack;
        stack<string> strstack;
        string curr;
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            if(isdigit(c)) {//if it is a number
                num = num*10 + (c-'0'); //Add its ASCII value
            }
            else if(c == '[') {
                //push the num and parent string in the stack
                numstack.push(num);
                strstack.push(curr);
                
                //reset num and curr
                curr ="";
                num=0;
            }
            else if(c ==']') {
                int times = numstack.top();
                numstack.pop();
                //Number of times to repeat the babies of parent
                
                string newstr;
                for (int j=0;j<times;j++) {
                    newstr.append(curr); // Also can do, newstr = newstr+curr;
                }
                curr = strstack.top().append(newstr); //append the baby with parent // Also can do, curr = strstack.top()+newstr;
                strstack.pop();
            }
            else {
                curr+=c;
            }
        }
        return curr;
    }
};


//DFS //Recursive

/*
Time Complexity = O(K*N)
Space Complexity = O(K*N)
where K is the sum of the digits and N is the total number of characters.
*/
class Solution {
public:
    int i = 0;
    string decodeString(string s) {
        if(s.size() ==0 ) return "";
        
        int num=0;
        string curr;
        
        while(i<s.size()) {
            char c = s[i];
            if(isdigit(c)) {//if it is a number
                num = num*10 + (c-'0'); //Add its ASCII value
                i++;
            }
            else if(c == '[') {
                i++;
                string decoded = decodeString(s);
                //st.pop() ->auto // parent is popped
                
                
                string newstr;
                //times will come from num 
                for (int j=0;j<num;j++) {
                    newstr.append(decoded);
                }
                curr.append(newstr); //append the baby with parent
                
                //Reset num
                num=0;
            }
            else if(c ==']') {
                i++;
                return curr;
            }
            else {
                i++;
                curr+=c;
            }
        }
        return curr;
    }
};