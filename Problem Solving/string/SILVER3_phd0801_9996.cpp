#include <bits/stdc++.h>

using namespace std;

string input, s1;
int n;
vector<string> s;
vector<string> cut;

int main(){
    cin >> n;
    cin >> input;
    size_t idx = input.find('*');
    size_t end = input.size();
    cut.push_back(input.substr(0, idx));
    cut.push_back(input.substr(idx+1, end));
    for(int i=0;i<n;i++){
        cin >> s1;
        s.push_back(s1);
    }
    for(int i=0; i< s.size(); i++){
        // 반례
        if(cut[0].length() + cut[1].length() > s[i].length()){
            cout << "NE" <<"\n";
            continue;
        }
        if(cut[0] == s[i].substr(0, cut[0].size()) && cut[1] == s[i].substr(s[i].size() - cut[1].size(), s[i].size())){
            cout << "DA" << "\n";
        }
        else{
            cout << "NE" << "\n";
        }
    }
    return 0;
}