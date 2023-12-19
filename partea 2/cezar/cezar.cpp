#include <bits/stdc++.h>
using namespace std;

ifstream f("cezar.in");
ofstream g("cezar.out");


int n, k;
int costFinal = 0;

vector<int> cost;
vector<bool> viz;
vector<vector<int>> vecini;
vector<int> grad;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

void init()
{
    f >> n >> k;
    cost = vector<int>(n+1,1);
    viz = vector<bool>(n+1,false);
    grad = vector<int>(n+1,0);
    vecini = vector<vector<int>>(n+1);

    for(int i=1; i<n; i++)
    {
        int x,y;
        f >> x >> y;
        cout << x << " - " << y << endl;
        vecini[x].push_back(y);
        vecini[y].push_back(x);
        grad[x]++;
        grad[y]++;
    }


//    for(int i=1;i<=n;i++)
//        cout << grad[i] << endl;
//    cout << "\n";
}





int main()
{
    init();

    for(int i=1;i<=n;i++)
        if(grad[i] == 1)
        {
            minHeap.push( {1, i} );
//            cout << i << endl;
        }


    int aux = n-k-1;
    while(aux>0)
    {
        int currentId = minHeap.top().second;
//        cout << currentId << " -- " << cost[currentId] << endl;
        minHeap.pop();
        viz[currentId] = true;
        aux--;
        costFinal += cost[currentId];


        for(auto& vecin : vecini[currentId])
        {
            //cout << "vecin " << vecin << endl;
            if(viz[vecin])
                continue;
            //cout << "Procesare " << vecin << endl;
            cost[vecin] += cost[currentId];
            grad[vecin]--;
            if(grad[vecin] == 1)
            {
                minHeap.push( {cost[vecin], vecin} );
               // cout << "Adaugat " << vecin << endl;
            }


        }
    }

    g << costFinal << endl;
    //cout << costFinal << endl;

    return 0;
}
