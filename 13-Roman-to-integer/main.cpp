// https://leetcode.com/problems/roman-to-integer/
    //13. Roman to Integer

    // Brute force Approach
    class Solution {
    public:
    int romanToInt(string s) {
    int i = s.size()-1;
    int result {0};

    while (i>=0) {
    if (s[i] == 'V') {
    if (i!=0) {
    if (s[i-1] == 'I') {
    result = result + 4;
    i=i-1;
    }
    else {
    result = result + 5;
    }    
    }
    else {
    result = result + 5;
    }
    }

    else if (s[i] == 'I') {
    result = result + 1;
    }
    else if (s[i] == 'X') {
    if (i!=0) {
    if (s[i-1] == 'I') {
    result = result + 9;
    i=i-1;
    }
    else {
    result = result + 10;
    }    
    }
    else {
    result = result + 10;
    }
    }
    else if (s[i] == 'L') {
    if (i!=0) {
    if (s[i-1] == 'X') {
    result = result + 40;
    i=i-1;
    }
    else {
    result = result + 50;
    }    
    }
    else {
    result = result + 50;
    }
    }

    else if (s[i] == 'C') {
    if (i!=0) {
    if (s[i-1] == 'X') {
    result = result + 90;
    i=i-1;
    }
    else {
    result = result + 100;
    }    
    }
    else {
    result = result + 100;
    }
    }

    else if (s[i] == 'D') {
    if (i!=0) {
    if (s[i-1] == 'C') {
    result = result + 400;
    i=i-1;
    }
    else {
    result = result + 500;
    }    
    }
    else {
    result = result + 500;
    } 
    }

    else if (s[i] == 'M') {
    if (i!=0) {
    if (s[i-1] == 'C') {
    result = result + 900;
    i=i-1;
    }
    else {
    result = result + 1000;
    }    
    }
    else {
    result = result + 1000;
    }

    }
    i--;
    }
    return result;
    }
    };