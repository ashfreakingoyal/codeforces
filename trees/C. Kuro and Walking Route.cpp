/* An ACEASH Source code  */
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vc vector<char>

#define vvi vector< vector < int > >
#define vvl vector< vector < ll > >

#define pii pair< int , int >
#define pll pair< ll , ll >

#define vpl vector< pll >
#define vpi vector< pii >

#define MOD 1000000007

#define mp make_pair
#define pb push_back

#define sare(v) (v).begin(),(v).end()
#define ulta(v) (v).rbegin(),(v).rend()

#define F first
#define S second

#define tez  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const ld pie = 3.1415926535897932384626 ;
const ll N=3e5 +9;
vl adj[N];
ll n,x,y;

ll vis[N]={0};
ll par[N];
ll subtree[N];

void dfs(ll node,ll parent=-1)
{
    par[node]=parent;
    for(auto it: adj[node])
    {
        if(it==parent){continue;}
        dfs(it,node);
    }
}
void find_parent(ll node)
{
    if(node!=x)
    {
        vis[node]=1;
        find_parent(par[node]);
    }
    
}
void dfs_s(ll node)
{
    subtree[node]=1;
    vis[node]=1;
    for(auto it: adj[node])
    {
        //cout<<it<<" ";
        if(vis[it]){continue;}
        dfs_s(it);
        subtree[node]+=subtree[it];
        //cout<<"it="<<it<<" "<<vis[it]<<"\n";
    }
}

int main()
{
    cin>>n>>x>>y;
    x--; y--;
    for(ll i=0;i<n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(x);
    find_parent(y);
    vis[x]=1;
    vis[y]=1;

    dfs_s(x);
    dfs_s(y);
    ll ans=(n*(n-1))-(subtree[x]*subtree[y]);
    /*cout<<"\n";
    cout<<subtree[x]<<" "<<subtree[y]<<" "<<subtree[1]<<"\n";
    for(ll i=0;i<n;i++)
    {
        cout<<vis[i]<<" ";
    } cout<<"\n";*/
    cout<<ans<<"\n";
    /*for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }*/
   

    return 0;
}


 
