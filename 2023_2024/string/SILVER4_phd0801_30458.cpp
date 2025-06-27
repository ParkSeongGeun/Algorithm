#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N;
int alphabet[26];
vector<char> v1;
vector<char> v2;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    int value = N/2;
    for(int i=0;i<N;i++){
        char a;
        cin >> a;
        if(i<value){
            v1.push_back(a);
            alphabet[a-'a']++;
        }
        else if(i+value>=N){
            v2.push_back(a);
            alphabet[a-'a']++;
        }
    }
    for(int i=0;i<26;i++){
        if(alphabet[i]%2!=0){
            cout << "No" << "\n";
            return 0;
        }
    }
    cout << "Yes" << "\n";
    return 0;
}