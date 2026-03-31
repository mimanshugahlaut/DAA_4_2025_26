class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> price(n,INT_MAX);
        price[src]=0;

        for(int i=0;i<=k;i++){
            vector<int> temp=price;
            for(auto &f:flights){
                int u=f[0];
                int v=f[1];
                int w=f[2];
                
                if(price[u]==INT_MAX) continue;

                if(price[u]+w<temp[v]){
                    temp[v]=price[u]+w;
                }
            }
            price=temp;
            
        }
        return price[dst]==INT_MAX?-1:price[dst];
    }
};
// Time Complexity: O(k*E)
// where k = maximum stops, E = number of flights (edges)

// Space Complexity: O(n)
// where n = number of cities (nodes)
