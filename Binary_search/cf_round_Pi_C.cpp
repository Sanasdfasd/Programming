#include <bits/stdc++.h>
using namespace std;

int n;
long long k;

long long tab[1000007];

long long wyn;

map <long long,long long> mapa1;
map <long long,long long> mapa2;

int main()
{
    scanf("%d%lld", &n, &k);
    for (int i=1; i<=n; i++)
    {
    	cout<<"the iteration is  "<<i<<endl;
        scanf("%lld", &tab[i]);
        if (!(tab[i]%(k*k)))
        {
        	cout<<" res added is "<<mapa2[tab[i]/k]<<endl;
        wyn+=mapa2[tab[i]/k];
       }
        if (!(tab[i]%k))
        { cout<<" the elements less than and added are"<<mapa1[tab[i]/k]<<endl;
          mapa2[tab[i]]+=mapa1[tab[i]/k];
       }
        mapa1[tab[i]]++;
    }
    printf("%lld\n", wyn);
    return 0;
}