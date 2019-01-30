#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin("hok.txt");

    int n, m;

    fin>>n>>m;

    string honapok[12] = {"januar", "februar", "marcius", "aprilis", "majus", "junius", "julius", "augusztus", "szeptember", "oktober", "november", "december"};
    string szakok[n][m], x;
    int k = 1;

    for(int i = 0; i<n; i++)
    {
        fin>>x;
        for(int j = 0; j<m; j++)
            szakok[i][j] = x;
    }

    for(int i = 1; i<m; i++)
    {
        int z = 1;
        while(z <= k)
        {
            x = szakok[n-1][i];
            for(int j = n-2; j>=0; j--)
            {
                szakok[j+1][i] = szakok[j][i];
            }
            szakok[0][i] = x;
            z++;
        }
        k++;
    }

    cout<<"  ";
    for(int i = 0; i<m; i++)
    {
        cout<<honapok[i]<<" ";
    }
    for(int i = 0; i<n; i++)
    {
        cout<<endl<<i+1<<" ";
        for(int j = 0; j<m; j++)
            cout<<szakok[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
