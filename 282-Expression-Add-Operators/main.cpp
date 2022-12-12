//Without StringBuilder

/*
Time Complexity = Exponential
Space Complexity = Exponential
*/

class Solution {
public:
    vector<string> result;
    vector<string> addOperators(string num, int target) {
        helper(num,target,0,0,0, "");
        return result;
    }
    void helper(string num, int target, int index, long calc, long tail, string path) {
        //base case
        if (index == num.size()) { // we have used all the elements
            if(calc == target) {//we have reached the target
                result.push_back(path);
            }
            
            return;
            
        }
        
        //logic
        
        for (int i=index; i<num.size();i++) {  // we start at the pivot each time as we first cover 12,123,1234,12345 then go to 2 and do 2,23,234,2345 and so on
            
            //for preceding 0 //to handle test case with 105
            
            if(num[index] == '0' && index!=i) { //make sure it is char 0 i.e. '0' and not 0
                continue;
            }
            string s = num.substr(index,i-index+1);
            
            long curr = stol(s,nullptr,10);
            
            if(index == 0) {//pivot at 0 tht is we are at root
                helper(num,target,i+1,curr,curr,path+to_string(curr)); 
                //calc and tail are curr and move to the next index value, concat curr to the contents of the path 
            }
            else {
                // + case
                helper(num,target,i+1,calc+curr,curr,path+"+"+to_string(curr));
                
                //- case
                helper(num,target,i+1,calc-curr,-1*curr,path+"-"+to_string(curr));
                
                //* case
                helper(num,target,i+1,calc-tail + (tail*curr),tail*curr,path+"*"+to_string(curr));
                
            }
        }
    }
};