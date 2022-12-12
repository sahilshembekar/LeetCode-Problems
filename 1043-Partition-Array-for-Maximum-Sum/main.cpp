/*
Time Complexity = O(n*k)
Spcae Complexity = O(n)
where n is the size of the arr and k is the partition size.
*/
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        //NULL case
        if(arr.size() == 0) {
            return 0;
        }
        int m,i,j;
        int n = arr.size();
        
        vector <int> dp(n);
        dp[0]=arr[0];
        //The single partition for first element will be the element itself
        // e.g. 1 i.e. arr[0] in [1,15,7...]
        for(i=1; i<n; i++) {
            m = dp[i]; //element set as max initially
            for(j=1; (j<=k)&&(i-j+1>=0); j++) {
                m = max(m, arr[i-j+1]); //incoming element is arr[i-j+1]
                //dp[i]=max(dp[i],((i>=j)?dp[i-j]:0)+m*j);
                if(i-j>=0) { //i-j can go less than 0 even when i-j+1 >=0, hence check if it is >=0 
                    dp[i] = max(dp[i], (m*j)+dp[i-j]); //m= max in that partition // j= length of partition
                }
                else {
                    dp[i] = max(dp[i], m*j);
                }
            }
        }
        return dp[n-1];
    }
};