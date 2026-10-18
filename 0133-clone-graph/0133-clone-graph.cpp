
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;
        queue<Node*> q;

        mp[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* next : curr->neighbors) {
                if (mp.find(next) == mp.end()) {
                    mp[next] = new Node(next->val);
                    q.push(next);
                }

                mp[curr]->neighbors.push_back(mp[next]);
            }
        }

        return mp[node];
    }
};
