class Solution {
private:   
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& visPath){
        vis[node] = 1;
        visPath[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, visPath)){
                    return true;
                }
            }
            else if(visPath[it]){
                return true; //Cycle found
            }
        }
        visPath[node] = 0; //BackTrack
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prere) {
        vector<vector<int>> adj(numCourses);

        for(auto it : prere){
            adj[it[1]].push_back(it[0]); //Because we first take course b then a
        }

        vector<int> vis(numCourses, 0);
        vector<int> visPath(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, visPath)){
                    return false; //Because if cycle exists then we cannot complete all courses as in question
                }
            }
        }
        return true;
    }
};