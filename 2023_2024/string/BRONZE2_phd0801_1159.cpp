#include <bits/stdc++.h>

using namespace std;

int N, flag;
string s;
int arr[26]; 

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> s;
        arr[s[0]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(arr[i]>=5){
            flag++;
            cout << (char)(i + 'a');
        }
    }
    if(flag == 0){
        cout << "PREDAJA" << "\n";
    }
    return 0;
}