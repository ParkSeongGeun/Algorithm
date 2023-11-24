#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int MAP[1001][1001];
string from, to;

int main(){
	cin >> from;
	cin >> to;
	for(int i=0;i<=to.length();i++){
		MAP[i][0] = i;
	}
	for(int j=0;j<=from.length();j++){
		MAP[0][j] = j;
	}

	for(int i=1;i<=to.length();i++){
		for(int j=1;j<=from.length();j++){
			if(from[j-1]==to[i-1]){
				MAP[i][j] = MAP[i-1][j-1];
			}
			else{
				MAP[i][j] = min(MAP[i-1][j], min(MAP[i-1][j-1], MAP[i][j-1]))+1;
			}
		}
	}

	cout << MAP[to.length()][from.length()] << "\n";
	for(int i=0;i<=to.length();i++){
		for(int j=0;j<=from.length();j++){
			cout << MAP[i][j] <<" ";
		}
		cout << "\n";
	}
	return 0;
}