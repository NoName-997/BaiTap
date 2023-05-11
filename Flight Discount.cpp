#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAX = 2e5 + 5;
long long n, m, ans = 1e18;
long long dFrom1[MAX], dFromN[MAX];
vector <pair <ll, int>> adj[MAX], reAdj[MAX];

void dijkstra1(){
    priority_queue <pair <ll, int>, vector <pair <ll, int>>, greater <pair <ll, int>>> pq;
    dFrom1[1] = 0; pq.push({dFrom1[1], 1});
    while(pq.size()){
        pair <ll, int> u = pq.top(); pq.pop();
        if(u.first <= dFrom1[u.second]){
            for(pair <ll, int> v : adj[u.second]){
                if(dFrom1[v.second] > dFrom1[u.second] + v.first){
                    dFrom1[v.second] = dFrom1[u.second] + v.first;
                    pq.push({dFrom1[v.second], v.second});
                }
            }
        }
    }
}

void dijkstra2(){
    priority_queue <pair <ll, int>, vector <pair <ll, int>>, greater <pair <ll, int>>> pq;
    dFromN[n] = 0; pq.push({dFromN[n], n});
    while(pq.size()){
        pair <ll, int> u = pq.top(); pq.pop();
        if(u.first <= dFromN[u.second]){
            for(pair <ll, int> v : reAdj[u.second]){
                if(dFromN[v.second] > dFromN[u.second] + v.first){
                    dFromN[v.second] = dFromN[u.second] + v.first;
                    pq.push({dFromN[v.second], v.second});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
        reAdj[v].push_back({w, u});
    }
    for(int i = 1; i <= n; i++) dFrom1[i] = dFromN[i] = 1e18;    
    dijkstra1(); dijkstra2();
    for(int u = 1; u <= n; u++){
        for(pair <ll, int> v : adj[u])
            ans = min(ans, dFrom1[u] + dFromN[v.second] + v.first / 2);
    }
    cout << ans;
    return 0;
}
