class Solution {
  public:
    vector<vector<int>> adj;
    bool dfs(int u,vector<int>& vis, int cnt,int n){
        if(cnt==n)
        return true;
        
        for(int v:adj [u]){
            if(!vis[v]){
                vis[v]=1;
                if(dfs(v,vis,cnt+1,n))
                    return true;
                vis[v]=0;
            }
        }
        return false;
    }
    bool check(int n,int m,vector<vector<int>> edges) {
        adj.resize(n+1);

        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int i=1;i<=n;i++) {
            vector<int> vis(n+1,0);
            vis[i] = 1;
            if (dfs(i,vis,1,n))
                return true;
        }
        return false;
    }
};
