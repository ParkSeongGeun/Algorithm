#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[500001];
int temp[500001];
long long res;

void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int left = start; 
    int right = mid + 1;
    int temp_index = start;
    long long count = 0;

    while (left <= mid && right <= end) // 합병 과정
    {
        if(arr[left] <= arr[right])
        {
            temp[temp_index] = arr[left];
            temp_index++;
            left++;
            res += count;
        }
        else
        {
            temp[temp_index] = arr[right];
            temp_index++;
            right++;
            count++;
        }
    }
    // 오른쪽 남은 경우
    if (left > mid)
    {
        for(int t = right; t <=end; t++)
        {
            temp[temp_index] = arr[t];
            temp_index++;
            count++;
        }
    }
    // 왼쪽 남은 경우
    else
    {
        for(int t = left; t <= mid;t++)
        {
            temp[temp_index] = arr[t];
            temp_index++;
            res += count;
        }
    }
    // 정렬된 거를 다시 합쳐줌
    for(int i=start;i<=end;i++)
    {
        arr[i] = temp[i];
    }
}

void merge_sort(int start, int end)
{
    if(start < end)
    {
        int mid = (start + end)/2;
        merge_sort(start, mid);
        merge_sort(mid+1, end);
        merge(start, end);
    }
    return ;
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    merge_sort(0, N - 1);
    cout << res;
    return 0;
}