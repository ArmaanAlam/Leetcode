class Disjoint{
        public:
        vector<int> rank, parent, size;
        Disjoint(int n){
            rank.resize(n, 0);
            parent.resize(n);
            size.resize(n, 1);
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
        
        
        void Union_size(int u, int v){
            int plu = findParent(u);
            int plv = findParent(v);            
            if(plu == plv) return;
            else if(size[plu] < size[plv]) {
                parent[plu] = plv;
                size[plv] += size[plu];
            }
            else{
                parent[plv] = plu;
                size[plu] += size[plv];
            }
        }
    };

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();

        int row = 0;
        int col = 0;
        for(auto it : stones){
            row = max(row, it[0]);
            col = max(col, it[1]);
        }

        Disjoint ds(row + col + 2);
        unordered_map<int, int> stone;

        for(auto it : stones){
            int rownode = it[0];
            int colnode = row + it[1] + 1;

            ds.Union_rank(rownode, colnode);

            stone[rownode] = 1;
            stone[colnode] = 1;

        }

        int cnt = 0;
        for(auto it : stone){
            int node = it.first;
            if(ds.findParent(node) == node){
                cnt++;
            }
        }

        int ans = n - cnt;

        return ans;
    }
};