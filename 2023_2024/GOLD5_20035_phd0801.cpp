#include <iostream>
#include <string.h>

using namespace std;

string arr[10001];

int N, i;
int first, second, third, result, rest;

int main()
{
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> arr[i];

	for (i = 0; i < N; i++)
	{
		if (arr[i] == "1/4")
			first++;
		else if (arr[i] == "1/2")
			second++;
		else
			third++;
	}
	if (second % 2 == 0)
		result += second / 2;
	else
	{
		result += second / 2;
		rest += 2;
	}

	if (first == third)
		result += first;
	else if (first > third)
	{
		result += third;
		rest += first - third;
	}
	else if (first < third)
	{
		result += first + (third - first);
	}

	if (result % 4 == 0)
		result += rest / 4;
	else
		result += rest / 4 + 1;

	cout << result << "\n";

	return 0;
}