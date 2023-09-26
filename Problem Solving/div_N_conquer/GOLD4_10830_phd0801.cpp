#include <iostream>
#include <algorithm>

using namespace std;

int N;
unsigned long long B;
unsigned long long arr[5][5];
unsigned long long one[5][5];
unsigned long long temp[5][5];

void    matrix_mul(unsigned long long arr1[][5], unsigned long long arr2[][5])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            unsigned long long sum = 0;
            for(int k=0;k<N;k++)
            {
                sum += arr1[i][k] * arr2[k][j];
            }
            temp[i][j] = sum;
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            arr1[i][j] = temp[i][j] % 1000;
        }
    }
}

void    go(unsigned long long count)
{
    while(count > 0)
    {
        if(count % 2 == 1)
        {
            matrix_mul(one, arr);
        }
        matrix_mul(arr, arr);
        count /= 2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> N >> B;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
        one[i][i] = 1;
    }
    go(B);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << one[i][j] <<" ";
        }
        cout << "\n";
    }
}