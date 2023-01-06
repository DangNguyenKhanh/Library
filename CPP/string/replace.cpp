Cú pháp:    s.replace(pos, len, str);
Tham số:
    pos: vị trí index của chuỗi (tính từ 0)
    len: số lượng kí tự muốn xóa tại vị trí pos trong s
    str: chuỗi muốn chèn vào vị trí pos

Task:
    Input:  a b c
            "0"
    Ouput:  a0b0c
    
// Example 1    // C++
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;   
    getline(cin, s);
    string str; 
    getline(cin, str);
    
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] == ' ') 
            s.replace(i, 1, str);
    
    cout << s << endl;
}
