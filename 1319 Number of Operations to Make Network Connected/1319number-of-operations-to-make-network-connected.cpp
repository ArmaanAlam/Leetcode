class Solution {
    class Disjoint{
        vector<int> rank, parent;
        public:
        Disjoint(int n){
            rank.resize(n, 0);
            parent.resize(n);

            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }

        
        
        int findParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
        
        
        void Union_rank(int u, int v){
            int plu = findParent(u);
            int plv = findParent(v);
            
            if(plu == plv) return;
            else if(rank[plu] < rank[plv]) {
                parent[plu] = plv;
            }
            else if(rank[plv] < rank[plu]) {
                parent[plv] = plu;
            }
            else{
                parent[plv] = plu;
                rank[plu]++;
            }
        }
    };


public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        Disjoint d(n);
        int extra = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(d.findParent(u) == d.findParent(v)){
                extra++;
            }
            else{
                d.Union_rank(u, v);
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(d.findParent(i) == i) cnt++;
        }

        int ans = cnt - 1;
        if(extra >= ans) return ans;

        return -1;
    }
};