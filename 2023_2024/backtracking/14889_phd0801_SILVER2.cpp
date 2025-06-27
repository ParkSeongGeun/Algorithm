#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[21][21];
int visited[21];
int min_value = 1000;

void    go(int temp, int num)
{
    vector<int> start;
    vector<int> link;

    int start_value = 0;
    int link_value = 0;

    if (temp == N / 2)
    {
        for (int i = 0; i < N; i++)
        {
            if (visited[i] == 1)
                start.push_back(i);
            else
                link.push_back(i);
        }
        for(int i=0;i < N / 2;i++)
        {
            for(int j = 0; j < N / 2;j++)
            {
                start_value += arr[start[i]][start[j]];
                link_value += arr[link[i]][link[j]];
            }
        }
        if(min_value > abs(start_value - link_value))
            min_value = abs(start_value - link_value);
        return ;
    }
    for (int i = num; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            go(temp + 1, i);
            visited[i] = 0;
        }
        else
            continue;
    }
    
}
int main(){
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for (int j = 0; j < N;j++)
        {
            cin >> arr[i][j];
        }
    }
    go(0,0);
    cout<< min_value <<"\n";
    return 0;
}