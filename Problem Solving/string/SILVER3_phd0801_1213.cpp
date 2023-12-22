#include <bits/stdc++.h>

using namespace std;

string s, ret;
int cnt[200], flag;
char mid;

int main() {
    cin >> s;
    for(char a : s){
        cnt[a]++;
    }
    for(int i='Z'; i>='A'; i--){
        if(cnt[i]){
            if(cnt[i]%2!=0){
                mid = char(i);
                flag++;
                cnt[i]--;
            }
            if(flag == 2){
                break;
            }
            for(int j=0; j<cnt[i]; j+=2){
                ret = char(i) + ret;
                ret += char(i);
                // 앞뒤로 붙여주기
            }
        }
    }
    if(mid){
        ret.insert(ret.begin() + ret.size() / 2, mid);
    }
    if(flag==2){
        cout << "I'm Sorry Hansoo\n";
    } else {
        cout << ret << "\n";
    }
    return 0;
}
// int main(){
//     ios_base :: sync_with_stdio(false); 
//     cin.tie(NULL); 
//     cout.tie(NULL);
    
//     cin >> s;
    
//     sort(s.begin(), s.end());
    
//     do {
//         int flag = 0;
//         for(int i=0; i < s.length()/2; i++){
//             if(s[i] != s[s.length()-i-1]){
//                 flag = 1;
//                 break;
//             }
//         }
//         if(flag != 1){
//             cout << s << "\n";
//             return 0;
//         }
//     }while(next_permutation(s.begin(), s.end()));
//     cout << "I'm Sorry Hansoo" << "\n";
//     return 0;
// }
