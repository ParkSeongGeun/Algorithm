#include <iostream>
#include <string>

using namespace std;

string  s;
string  line = "--------------------------------------------------------------------------------";
int cnt;
int check;

int check_uni(string s)
{
    if (s == "<br>")
        return 1;
    else if (s == "<hr>")
        return 2;
    else   
        return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    while(cin >> s)
    {
        if (check_uni(s) == 1)
        {
            cout << "\n";
            cnt = 0;
        }
        else if (check_uni(s) == 2)
        {
            if(cnt != 0)
            {
                cout << "\n";
            }
            cout << line << "\n";
            cnt = 0;
        }
        else
        {
            int len = s.length();
            if (len + cnt < 80)
            {
                if (cnt != 0)
                {
                    cout << " ";
                    cnt++;
                }
                cout << s;
                cnt += len;
            }
            else
            {
                cout << "\n";
                cnt = 0;
                cout << s;
                cnt += len;
            }

        }
    }
    return 0;
}