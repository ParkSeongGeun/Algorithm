#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
string arr[20000];

int str_len(string a)
{
    int i;
    i = 0;
    while (a[i] != '\0')
        i++;
    return (i);
}

int sort_arr(string dest, string src)
{
    int dest_len = str_len(dest);
    int src_len = str_len(src);
    
    if (dest_len == src_len)
        return dest < src;
    else
        return dest_len < src_len;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >>arr[i];
    }
    sort(arr, arr + N, sort_arr);
    for (int i=0;i<N;i++)
    {
        if (arr[i - 1] == arr[i])
            continue ;
        cout << arr[i] << "\n";
    }
    return 0;
}