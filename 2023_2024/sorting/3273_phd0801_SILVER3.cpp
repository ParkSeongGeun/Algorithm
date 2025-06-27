#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100000];
int x;
int res;

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cin >> x;
    sort(arr, arr + N);
    for (int i = 0; i < N ; i++)
    {
        if (arr[i] >= x)
        {
            break;
        }
        for (int j = N - 1 ; j > i; j--)
        {
            if (arr[i] + arr[j] == x)
            {
                //printf("i , j = %d %d\n", i, j);
                res++;
                break;
            }
        }
    }
    cout << res << "\n";
    return 0;
}