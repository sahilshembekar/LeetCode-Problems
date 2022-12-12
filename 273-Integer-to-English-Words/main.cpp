/*
Time Complexity = O(1)
Space Complexity = O(1)
Time complexity is O(1) because we will only traverse through each digit of the number given which will be at max 10-12(constant). the Space complexity is O(1) beacause all the three arrays taken are of constant size.
*/

class Solution {
public:
    string below_20[20] = {"","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    
    string tens[10] = {"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string thousand[5] = {"","Thousand","Million","Billion"};
    
    string helper(int num) {
        if (num==0) {
            return ""; //Zeros is the middle
        }
        else if (num<20) {
            return below_20[num] + " ";
        }
        else if (num<100) {
            return tens[num/10] + " " + helper(num%10);
        }
        else {
            return below_20[num/100] +" Hundred " + helper(num%100);
        }   
    }
    
    
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        
        string result ="";
        int i=0;
        while (num){
            if (num%1000 != 0) {
                result = helper(num%1000) + thousand[i] + " " + result;
            }
            num= num/1000;
            i++;
        }
        // return result.trim(); // Not possible in cpp
        
        for (i = result.size()-1; i>0; i--) {
            if (result[i] != ' '){
                break;
            }
        }
        int l = i;
        string final;
        for (int i=0; i<=l;i++) {
            final+=result[i];
        }
        return final;
    }
};