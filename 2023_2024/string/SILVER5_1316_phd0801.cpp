#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, res;
string s;
vector< pair<char, int> > v;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    char c = 'a';
    for(int i=0;i<26;i++){
        v.push_back(make_pair(c, 0));
        c++;   
    }
    cin >> N;
    for(int i=0;i<N;i++){
        int flag = 0;
        int big_flag = 0;
        cin >> s;
        for(int j=0;j<26;j++){
            if(s[0]==v[j].first){
                v[j].second = 1;
            }
        }
        for(int i=1;i<s.length();i++){
            if(s[i] != s[i-1]){
                for(int j=0;j<26;j++){
                    if(s[i]==v[j].first){
                        if(v[j].second > 0){
                            big_flag = 1;
                            flag = 1;
                            break;
                        }
                        else{
                            v[j].second++;
                        }
                    }
                }
                if(flag==1){
                    break;
                }
            }
            else{
                for(int j=0;j<26;j++){
                    if(s[i]==v[j].first){
                        v[j].second++;
                    }
                }
            }
        }
        if(big_flag == 0){
            res++;
        }
        for(int i=0;i<26;i++){
            v[i].second = 0;
        }
    }
    cout << res <<"\n";
    return 0;
}