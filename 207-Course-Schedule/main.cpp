/*
Time Complexity = O(V+E)
Space Complexity = O(V+E)
where V is the number pf courses and E is the dependencies.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0) {
            return true;
        }
        
        //1st Array // indegree array for each vertex
        
        vector <int> indegrees (numCourses, 0); //(size,value)
        for (int i =0;i <prerequisites.size(); i++) {
            indegrees[prerequisites[i][0]]++; //iterate over rows with cloumn as 0 
            //for [1,0] to take course 1 you need to take 0 so 1 is dependent on 0 so index of 1 will be ++
        }
        
        //storing the dependencies in the map to efficiently access the courses dependent on that particular course.
        //Adjacency List
        map <int, vector <int>> m;
        for (int i =0;i <prerequisites.size(); i++) {
            if (m.find(prerequisites[i][1]) != m.end()) {
                m[prerequisites[i][1]].push_back(prerequisites[i][0]);
                // 0 is independent in the map and 1 is dependent on it so for the key 0 i.e. prerequisites[i][1]
                // add 1 i.e. prerequisites[i][0] to its value which is a vector (list of int)
            }
            else { //Make a vector at the location/key and add the value to the vector
                vector <int> temp;
                temp.push_back(prerequisites[i][0]);
                m[prerequisites[i][1]] = temp; // Add a new vector to that location/key
            }
        }
        
        //using queue to check if we can undertake all the courses.
        
        queue <int> q;
        int count = 0;
        for (int i =0; i<indegrees.size(); i++) { // can also do < numCourses since both of those are equal
            if (indegrees[i] == 0) { //Basically a course which is independent
                q.push(i); 
                count ++; //Since we take the course we add it to our count
            }
            }
            if (q.size() == 0) { //Basically we cant take any course or all course are dependent on each other or cycle exists
                return false;
            }
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                //Check the courses that are depended on this course curr from the map
                vector <int> ans( m[curr] ); //Can have more than 1 courses dependent on it i.e. a vector store that in new vec for processing
                if (ans.size()!=0) { //check only if we have anything there 
                    for (int i=0; i < ans.size(); i++) {
                        indegrees[ans[i]]--; // reduce the indgree count by 1 since one of the course required by it has been taken
                        if (indegrees[ans[i]] == 0) { // if the course has now become independent, add it to the queue
                            q.push(ans[i]);
                            count++;
                        }
                    }
                    
                }
                
            }
            
        
        // cout << count <<endl;
        // cout << numCourses;
        return (count == numCourses);
        //Can also do without count variable but we will have to iterate over the indegrees vector and check if all the depenedcies are 0 or not
        //if yes only then true
            
    }
};