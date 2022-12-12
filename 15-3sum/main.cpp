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