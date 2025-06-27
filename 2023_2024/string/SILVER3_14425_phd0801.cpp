#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<string> MAP;
string input;
int res;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        MAP.push_back(s);
    }
    sort(MAP.begin(), MAP.end());
    for(int j=0;j<M;j++){
        cin >> input;
        if(binary_search(MAP.begin(), MAP.end(), input)){
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}