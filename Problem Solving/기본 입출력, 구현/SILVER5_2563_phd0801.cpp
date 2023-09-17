#include <iostream>

using namespace std;

int arr[101][101];
int cnt;
int N;

int main()
{
    int a, b;
    cin >> N;
    for(int i = 0; i < N;i++)
    {
        cin >> a >> b;
        for(int j = b - 1; j < (b + 9); j++)
        {
            for (int k = a - 1; k < (a + 9); k++)
            {
                arr[j][k]++;
            }
        }
    }
    for(int i = 0; i <= 100 ;i++)
    {
        for(int j = 0; j <= 100;j++)
        {
            if (arr[i][j] > 0)
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}