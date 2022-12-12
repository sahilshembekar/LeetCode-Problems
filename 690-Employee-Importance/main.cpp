//BFS approach
/*
Time Complexity = O(N)
Space Complexity = O(N)
where N is the number of elements in the vector employees.
*/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int result =0;
        map<int, Employee*> m;
        for (int i =0; i < employees.size();i++) {
            m[employees[i]->id] = employees[i]; 
            // map of employee id as the key
            // Value is the emmployee object DS which contains imporatance and vector of subordinates
        }
        queue <int> q;
        q.push(id); //we push only the IDs in the queue
        
        while(!q.empty()) {
            int Eid = q.front();
            q.pop();
            
            Employee* e = m[Eid];
            //can also do Employee* e = m[q.front()]; 
            //basically value containing the employee DS is returned and stored in e which is Employee class datatype
            
            result +=e->importance; //Add the importance of itself
            
            vector <int> vec {e->subordinates};
            
            for(int i=0; i<vec.size(); i++) {
                q.push(vec[i]); //push the id of each subordinate in the queue
            }
            
        }
        return result;
    }
};