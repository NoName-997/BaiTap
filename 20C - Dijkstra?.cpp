#include <bits/stdc++.h> 
#define ll long long
using namespace std;

const int MAXN = 1e5 + 5;
int n, m, trace[MAXN];
vector <pair <int, ll>> adj[MAXN];

void dijkstra(){
    vector <ll> d(n + 1, LLONG_MAX);
    priority_queue <pair <ll, int>, vector <pair <ll, int>>, greater <pair <ll, int>>> pq;
    d[1] = trace[1] = 0;
    pq.push({d[1], 1});
    while(pq.size()){
        pair <int, int> u = pq.top(); pq.pop();
        if(u.first <= d[u.second]){
            for(auto v : adj[u.second]){
                if(d[v.first] > d[u.second] + v.second){
                    d[v.first] = d[u.second] + v.second;
                    trace[v.first] = u.second;
                    pq.push({d[v.first], v.first});
                }
            }
        }
    }
}

void solve(){
    if(!trace[n]) {cout << -1;  return;}
    stack <int> st;
    while(n != 0){
        st.push(n);
        n = trace[n];
    }
    while(st.size()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(); solve();
    return 0;
}
