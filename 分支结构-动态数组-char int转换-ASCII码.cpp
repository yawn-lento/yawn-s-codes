#include <iostream>
#include <vector>
#include <string> 
using namespace std;
int main() {
    string str;
    getline(cin, str);
    vector<char> charVec(str.begin(), str.end());
    // 核心代码：直接用一个 vector 接收 string 的迭代器范围
    if (charVec.empty()) 
        return 0; // 如果读到了空输入，直接退出，防止崩溃
    int product = 0;
    int count = 0;
    for (int i = 0; i < charVec.size()-1; i++) 
    {
        if (charVec[i]-'0' >= 0 && charVec[i] -'0' <= 9)
        {
            count++;
            product = product + (charVec[i] - '0') * count;
        }
    }
    char last;
    if (product % 11 == 10)
        last = 'X';
    else
        last = product%11+'0';
    if (last == charVec[charVec.size() - 1])
        cout << "Right";
    else
    {
        charVec[charVec.size() - 1] = last;
        for (int i = 0; i < charVec.size(); i++)
            cout << charVec[i];
    }
    return 0;
}