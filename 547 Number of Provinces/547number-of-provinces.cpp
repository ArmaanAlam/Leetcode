class Solution {

    class Disjoint {
        vector<int> rank, parent;

    public:
        Disjoint(int n) {
            rank.resize(n, 0);
            parent.resize(n);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int findParent(int node) {
            if (node == parent[node]) {
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }

        void Union_rank(int u, int v) {
            int plu = findParent(u);
            int plv = findParent(v);

            if (plu == plv)
                return;
            else if (rank[plu] < rank[plv]) {
                parent[plu] = plv;
            } else if (rank[plv] < rank[plu]) {
                parent[plv] = plu;
            } else {
                parent[plv] = plu;
                rank[plu]++;
            }
        }
    };

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        Disjoint d(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    d.Union_rank(i, j);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (d.findParent(i) == i) {
                cnt++;
            }
        }

        return cnt;
    }
};