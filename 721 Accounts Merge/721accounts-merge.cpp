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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();

        Disjoint d(n);

        unordered_map<string, int> mapMail;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mapMail.find(mail) == mapMail.end()){
                    mapMail[mail] = i;
                }
                else{
                    d.Union_rank(i, mapMail[mail]);
                }
            }
        }

        vector<string> mergeMail[n];
        for(auto it : mapMail){
            string mail = it.first;
            int node = d.findParent(it.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(mergeMail[i].size() == 0) continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
        
    }
};