#include <iostream>
#include <vector>

using namespace std;

int N,K;
long long a;

vector<long long> v;
vector<long long> temp(5000000);

void    merge(int start, int end)
{
    int mid = (start+end)/2;
    int left = start;
    int right = mid+1;
    int temp_index = start;
    while(left<=mid&&right <= end)
    {
        if(v[left]<=v[right])
        {
            temp[temp_index] = v[left];
            temp_index++;
            left++;
        }
        else
        {
            temp[temp_index] = v[right];
            temp_index++;
            right++;
        }
    }
    // 오른쪽 남은 경우
    if(left>mid)
    {
        for(int i=right;i<=end;i++)
        {
            temp[temp_index] = v[i];
            temp_index++;
        }
    }
    else
    {
        for(int i=left;i<=mid;i++)
        {
            temp[temp_index] = v[i];
            temp_index++;
        }
    }

}
void    merge_sort(int start, int end)
{
    if(start < end)
    {
        int mid = (start+end)/2;
        merge_sort(start, mid);
        merge_sort(mid+1, end);
        merge(start, end);
        for(int i=start;i<=end;i++)
        {
            v[i] = temp[i];
        }
    }
    return;
}
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
        cin >> a;
        v.push_back(a);
    }
    if(N==1)
    {
        cout << v[0] << "\n";
        return 0;
    }
    merge_sort(0, N-1);
    cout << v[K-1] << "\n";
    return 0;
}