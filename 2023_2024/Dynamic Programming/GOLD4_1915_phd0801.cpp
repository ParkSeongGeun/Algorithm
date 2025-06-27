#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M;
string input;
int res;
int MAP[1001][1001];

// int find_min_value(int a, int b, int c)
// {
//     int first = min(a, b);
//     if (c > first)
//         return (first);
//     else
//         return (c);
// }

int is_valid(int a, int b, int c)
{
    if (a>=1&&b>=1&&c>=1)
        return (1);
    return (0);
}

void    go()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if (MAP[i][j] != 0)
            {
                //MAP[i][j] = find_min_value(MAP[i-1][j], MAP[i-1][j-1], MAP[i][j-1]) + 1;
                if(is_valid(MAP[i-1][j], MAP[i-1][j-1], MAP[i][j-1]) == 1)
                    MAP[i][j]++;
                if(res < MAP[i][j])
                    res = MAP[i][j];
            }
        }
    }
}
int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        cin >> input;
        for(int j = 0; j < M;j++)
        {
            MAP[i][j+1] = input[j] - '0';
        }
    }
    go();
    //print MAP
    for(int i = 1 ;i <= N;i++)
    {
        for(int j = 1; j <= M;j++)
            cout<<MAP[i][j] << " ";
        cout<<"\n";
    }
    cout << res * res <<"\n";
    return 0;
}