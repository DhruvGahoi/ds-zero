// Using BFS

class Solution {
public:

    int bfs(int node, unordered_map<int, vector<int>> &adj){ 
        queue<int> que;
        que.push(0); // Source
        vector<int> vis(node, 0); // SPACE : O(n)
        vis[0] = 1;

        int level = 0;
        while(!que.empty()){
            int n = que.size();
            while(n--){
                int curr = que.front();
                que.pop();

                if(curr == node - 1) return level;

                for(int &nbr : adj[curr]){
                    if(!vis[nbr]){
                        que.push(nbr);
                        vis[nbr] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj; // O(V+E)
        for(int i = 0; i <= n-2; i++){
            adj[i].push_back(i+1);
        }

        vector<int> result;
        for(auto &query : queries){
            int u = query[0];
            int v = query[1];
            adj[u].push_back(v);
            int d = bfs(n, adj); // Its better to pass unordered_map<int, vector<int>> adj; int the function
            result.push_back(d);
        }

        return result;

    }
};


// USING DIJKSTRA

class Solution {
public:
    #define P pair<int, int> 
    int dij(int n, unordered_map<int, vector<P>> &adj){
        vector<int> result(n, INT_MAX);
        // result[i] = Shortest path from source to ith node
        // 0 --> n-1
        // result[n-1] = Shortest path from 0 to n-1
        result[0] = 0;
        priority_queue<P, vector<P>, greater<P>> pq; // Min heap
        pq.push({0, 0});

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node == n-1) return result[n-1];

            for(auto &p : adj[node]){
                int adjNode = p.first;
                int wt = p.second;
                if(d + wt < result[adjNode]){
                    result[adjNode] = d + wt;
                    pq.push({d+wt, adjNode});
                }
            }
        }

        return result[n-1]; // Shortest path from n-1
    }
    // Edge, Weight
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<P>> adj;
        for(int i = 0; i <= n-2; i++){
            adj[i].push_back({i+1, 1}); // Treating each edge as a unit weight
        }

        vector<int> result;
        for(auto &query : queries){
            int u = query[0];
            int v = query[1];
            adj[u].push_back({v, 1});
            int d = dij(n, adj); // Its better to pass unordered_map<int, vector<int>> adj; int the function
            result.push_back(d);
        }

        return result;

    }
};