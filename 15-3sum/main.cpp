//Time Complexity = O(N*N*N)
//Space Complexity = O(N) approximately
//Where N is the size of the vector nums.
//here the time limit will exceed.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i,j,k;
        sort(nums.begin(),nums.end());
        set <vector<int>> ans1;
        for(i=0;i<nums.size()-2;i++)
        {
            for(j=i+1;j<nums.size()-1;j++)
            {
                for(k=j+1;k<nums.size();k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        vector <int> temp{nums[i],nums[j],nums[k]};
                        ans1.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto i : ans1)
            ans.push_back(i);
        return ans;
    }
};


//Time Complexity = O(N*N)
//Space Complexity = O(1)
//Where N is the size of the vector nums.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size()==0)  {
            return result;
        }
        sort(nums.begin(), nums.end());
        
        for (int i =0; i <nums.size(); i++) { //outside iterations
            if (i>0 && nums[i]== nums[i-1]) { //If new number is same as previous i.e. not unique, skip this iteration
                continue;
            }
            int low = i+1; //Next to fixed element
            int high = nums.size()-1; //Last element
            while (low < high) { //to make sure low and high don't cross each other
                
                int sum = nums[i] + nums[low] + nums[high];
                
                if (sum ==0) { // We found the triplets
                    vector <int> triplet {nums[i], nums[low], nums[high]}; // Save it as vector
                    result.push_back(triplet); // Store the vector in the 2d vector
                    low++; 
                    high--;
                    while (low <high && nums[low]==nums[low-1]) { // need to check low<high again as we only do it once when starting the while loop
                        // Done in order to avoid inner duplicate values
                        low++;
                    }
                    while (low <high && nums[high]==nums[high+1]) {
                        high--;
                    }
                }
                else if (sum<0) { 
                    low++; //Move closer to larger number to make the sum =0
                }
                else {
                    high--; //Move closer to smaller number to make the sum =0
                }
            }
        }
        return result;
    }
};