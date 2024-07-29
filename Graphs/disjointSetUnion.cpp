#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class DisjointSet
{
    vector<ll> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 1);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }

    int findUpar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        else
        {
            return parent[node] = findUpar(parent[node]);
        }
    }

    void unionByRank(int u, int v)
    {
        int ul_pu = findUpar(u);
        int ul_pv = findUpar(v);

        if (ul_pu == ul_pv)
            return;
        else
        {
            if (rank[ul_pu] > rank[ul_pv])
            {
                parent[ul_pv] = ul_pu;
            }
            else if (rank[ul_pu] < rank[ul_pv])
            {
                parent[ul_pu] = ul_pv;
            }
            else
            {
                parent[ul_pv] = ul_pu;
                rank[ul_pu]++;
            }
        }
    }

    void unionBySize(int u, int v)
    {
        int ul_pu = findUpar(u);
        int ul_pv = findUpar(v);

        if (ul_pu == ul_pv)
            return;
        else
        {
            if (size[ul_pu] > size[ul_pv])
            {
                parent[ul_pv] = ul_pu;
                size[ul_pu] += size[ul_pv];
            }
            else
            {
                parent[ul_pu] = ul_pv;
                size[ul_pv] += size[ul_pu];
            }
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    ds.unionByRank(3, 7);
}