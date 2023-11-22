#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

int N, res;
bool BOOK[2000];

string s;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    int a;
    while(1){
        for(int i=0;i<2000;i++){
            BOOK[i] = false;
        }
        cin >> a;
        if(a==0){
            break;
        }
        else{
            cin >> s;
            istringstream ss(s);
            string stringBuffer;
            while(getline(ss, stringBuffer, ',')){
                int flag = 0;
                int num1 = 0;
                int num2 = 0;
                for(int i=0;i<stringBuffer.size();i++){
                    if(stringBuffer[i]=='-'){
                        flag = 1;
                        continue;
                    }
                    if(flag == 0){
                        num1 = num1 * 10 + (stringBuffer[i] - '0');
                    }
                    else{
                        num2 = num2 * 10 + (stringBuffer[i] - '0');
                    }
                }  
                if(num2==0){
                    BOOK[num1] = true;
                }
                else if(num1<=num2){
                    for(int i=num1;i<=num2;i++){
                        BOOK[i] = true;
                    }
                }
            }
        }
        for(int i=1;i<=a;i++){
            if(BOOK[i]==true){
                res++;
            }
        }
        cout << res << "\n";
        res = 0;
    }
    return 0;
}