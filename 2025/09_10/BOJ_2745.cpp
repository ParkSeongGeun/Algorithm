#include <iostream>

using namespace std;

typedef long long ll;

string s;
int n, res;
char c[36];

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    cin >> s >> n;

    for(int i=0;i<10;i++){
        c[i] = '0'+i;
    }
    for(int i=0;i<26;i++){
        c[10+i] = 'A' + i;
    }

    for(int i=0;i<s.length();i++){
        for(int j=0;j<36;j++){
            if (c[j] == s[i]){
                // cout << "c[j]: " << c[j] << "\n";
                // cout << "j: " <<  j << "\n";
                // cout << "res: " << res << "\n";
                res = res * n + j;
            }
        }
    }
    cout << res << "\n";
}