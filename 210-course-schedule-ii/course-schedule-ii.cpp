class Solution {
private:
    bool isCycleDFS(int src, vector<bool>& vis, vector<bool>& recPath, vector<vector<int>>& edges){
        vis[src] = true;
        recPath[src] = true;

        for(int i=0; i<edges.size(); i++){
            int v = edges[i][0]; //Neighbour //We do this because their for source neighbour is not given directly
            int u = edges[i][1]; //Source

            if(src == u){
                if(!vis[v]){
                    if(isCycleDFS(v, vis, recPath, edges)){
                        return true;
                    }
                }
                else if(recPath[v]){ //Back Edge -> For cycle
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;
    }

    void topoOrder(int src, vector<bool>& vis, stack<int>& s, vector<vector<int>>& edges){ //Topological Order
        vis[src] = true;

        for(int i=0; i<edges.size(); i++){
            int v = edges[i][0]; //Neighbour //We do this because their for source neighbour is not given directly
            int u = edges[i][1]; //Source

            if(src == u){
                if(!vis[v]){
                    topoOrder(v, vis, s, edges);   
                }
            }
        }
        s.push(src);
    }

public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(isCycleDFS(i, vis, recPath, edges)){ //Continuos nahi hua toh so ye kar rahe hai
                    return ans;
                }
            }
        }

        //Toplological Sorted Array
        stack<int> s;
        vis.assign(n, false); //Stack redefined kar rahe hai

        for(int i=0; i<n; i++){
            if(!vis[i]){
                topoOrder(i, vis, s, edges);
            }
        }

        while(s.size() > 0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};