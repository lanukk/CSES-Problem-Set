#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define vll vector<ll>
#define ld long double
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define osetll tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ook order_of_key
#define fbo find_by_order
const int MOD=1000000007;
long long int inverse(long long int i){
    if(i==1) return 1;
    return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
ll POW(ll a,ll b)
{
    if(b==0) return 1;
    if(b==1) return a%MOD;
    ll temp=POW(a,b/2);
    if(b%2==0) return (temp*temp)%MOD;
    else return (((temp*temp)%MOD)*a)%MOD;
}

vector<pll> AdjList[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,k,a,b,c;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        a--; b--;
        AdjList[a].PB({b,c});
    }
    vll ans;
    ll cnt=0;
    vll dist(n, 0); 
    priority_queue< pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq; 
    pq.push(make_pair(0, 0));
    while (!pq.empty())
    {
        pair<ll,ll> front = pq.top(); pq.pop(); 
        ll d = front.first, u = front.second;
        if (dist[u]>k) continue;
        if(u==n-1)
        {
            cnt++;
            ans.PB(d);
            if(cnt==k) break;
        }
        dist[u]++;
        for (int j = 0; j < (int)AdjList[u].size(); j++)
        {
            pair<ll,ll> v = AdjList[u][j];
            if(dist[v.first]>k) continue;
            pq.push(make_pair(d+v.second, v.first));
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
