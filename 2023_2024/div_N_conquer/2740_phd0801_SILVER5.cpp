#include <iostream>
#include <algorithm>

using namespace std;

int dest[100][100];
int src[100][100];
int row1, row2;
int col1, col2;

void    multi_matrix(int dest[][100], int src[][100])
{
    int cnt;
    for(int i = 0; i < row1; i++)
    {
        cnt = 0;
        for (int j = 0; j < col2; j++)
        {
            cnt = 0;
            for (int k = 0; k < row2; k++)
            {
                cnt += dest[i][k] * src[k][j];
            }
            cout << cnt << " ";
        }
        cout << "\n";
    }
}
int main(){
    cin >> row1 >> col1;
    for(int j = 0;j < row1;j++)
    {
        for(int k = 0;k < col1;k++)
            cin >> dest[j][k];
    }
    cin >> row2 >> col2;
    for(int j = 0;j < row2;j++)
    {
        for(int k = 0;k < col2;k++)
            cin >> src[j][k];
    }
    multi_matrix(dest, src);
    return (0);
}

