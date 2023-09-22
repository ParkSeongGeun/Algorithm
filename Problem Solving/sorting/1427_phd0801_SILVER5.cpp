#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100];

bool compare(char a, char b)
{
    return a > b;
}

int num_len(int N)
{
    int len = 0;
    while (N != 0)
    {
        N = N / 10;
        len++;
    }
    return (len);
}
void itoa(int N)
{
    int len = num_len(N);
    for (int i = len - 1; i >= 0; i--)
    {
        arr[i] = N % 10;
        N = N / 10;
    }
}

int main(){
    cin >> N;
    int len = num_len(N);
    //cout << len<<"\n";
    itoa(N);
    sort(arr, arr + len, compare);
    for(int i = 0; i < len;i++)
        cout << arr[i];
    cout << "\n";
    return 0;
}