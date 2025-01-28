class Solution {
public:
    typedef long long ll;
    const int LARGE_VAL = 2e9;
    typedef pair<int, int> P;

    ll DijkstraAlgo(vector<vector<int>>& edges, int n, int src, int dest){
        // make the graph excluding -1 et edges
        unordered_map<ll, vector<pair<ll, ll>>> adj;

        for(vector<int>& edge : edges){
            if(edge[2] != -1){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<ll> result(n, INT_MAX); // result[i] = shortest path dist from src to ith node
        // vector<bool> vis(n, false) // You dont need vis array coz anyway u will not viisit the same node as its dist will be increased next time Dj you will skip

        result[src] = 0; 
        pq.push({0, src});

        while(!pq.empty()){
            ll currDist = pq.top().first;
            ll currNode = pq.top().second;
            pq.pop();

            for(auto& [nbr, wt] : adj[currNode]) {
                if(result[nbr] > currDist + wt){
                    result[nbr] = currDist + wt;
                    pq.push({result[nbr], nbr});
                }
            }
        }

        return result[dest];

    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currShortestDist = DijkstraAlgo(edges, n, source, destination);

        if(currShortestDist < target){
            return {};
        }

        bool matchedTarget = (currShortestDist == target);

        for(vector<int>& edge : edges){
            if(edge[2] == -1){
                edge[2] = (matchedTarget == true) ? LARGE_VAL : 1; // assign lowest number
                if(!matchedTarget){
                    ll newShortestDist = DijkstraAlgo(edges, n, source, destination);
                    if(newShortestDist <= target){
                        matchedTarget = true;
                        edge[2] += (target - newShortestDist);
                    }
                }
            }
        }

        if(!matchedTarget){
            return {};
        }

        return edges;
    }
};
