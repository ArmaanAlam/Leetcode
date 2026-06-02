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

    bool isValid(int nrow, int ncol, int n){
        return nrow >= 0 && ncol >= 0 && nrow < n && ncol < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();

        Disjoint ds(n*n);

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) continue;

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};

                for(int i = 0; i < 4; i++){
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];
                    if(isValid(nrow, ncol, n) && grid[nrow][ncol]){
                        int node = (row * n) + col;
                        int adjnode = (nrow * n) + ncol;
                        ds.Union_size(node, adjnode);
                    }
                }
            }
        }

        int max_island = 0;


        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                set<int> component;

                for(int i = 0; i < 4; i++){
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];
                    if(isValid(nrow, ncol, n) && grid[nrow][ncol]){
                        component.insert(ds.findParent(nrow*n + ncol));
                    }
                }
                int size_total = 0;
                for(auto it: component){
                    size_total += ds.size[it];
                }
                max_island = max(max_island, size_total + 1);
            }
        }



        for(int i = 0; i < n*n; i++){
            max_island = max(max_island, ds.size[ds.findParent(i)]);
        }

        return max_island;

    }
};