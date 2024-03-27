#include <iostream>
#include <string>
#include<cmath>
using namespace std;
int HashFunction(string a) {
    int len = a.length();
    int key = 0;
    for (int i = 0; i < len; i++) {
        key += a[i]*pow(10,i);
    }
    return key;
}
bool StringMatch(string a, string b) {
    int len_a = a.length();
    int len_b = b.length();
    int key = HashFunction(b);
    int flag = false;
    for (int i = 0; i <= len_a - len_b; i++) {
        string temp = a.substr(i,len_b);
        int temp_key = HashFunction(temp);
        if (key == temp_key) {
            for (int j = 0; j < len_b; j++) {
                flag = true;
                if (b[j] != a[i + j]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag == true) {
            return true;
        }
    }
    return false;
}
int main()
{
    string a = "ABCDEFGHIJK";
    string b = "DEF";
    if (StringMatch(a, b)) {
        cout << "The Sub String is Present in The String";
    }
    else {

        cout << "The Sub String is Not Present in The String";
    }
}
