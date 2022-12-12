//Recursive call solution

/*
Time Complexity = O(logn)
Space Complexity = O(logn)
where n is the power of the number
*/

class Solution {
public:
    double myPow(double x, int n) {
        //base case
        if (n == 0) {
            // when the n becomes 0 ultimately
            return 1.00;
        }
        
        
        
        //logic
        double result = myPow(x,n/2); //recursive call on power i.e. n divide by 2 i.e. half
        if (n%2 == 0) {
            //if power is even
            //equally divided
            return result*result;
        }
        else {
            //when it is odd
            if (n>0) {
                //postive power
                return result*result*x;
            }
            else { // when negative and odd
                return result*result*(1/x);
            }
        }
    }
};