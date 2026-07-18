#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<int> add(stack<int>& A, stack<int>& B)
{
    stack<int> C; 
    int t = 0;    
    while (!A.empty() || !B.empty() || t) 
    {
        if (!A.empty()) { t += A.top(); A.pop(); } 
        if (!B.empty()) { t += B.top(); B.pop(); }
        C.push(t % 10); 
        t /= 10;   
    }
    return C;
}
void accumulation() {string 
   
    cin >> a >> b;
    stack<int> A, B;
    for (int i = 0; i < a.size(); i++) A.push(a[i] - '0');
    for (int i = 0; i < b.size(); i++) B.push(b[i] - '0');    
    stack<int> C = add(A, B);        
    while (!C.empty())
    {
        cout << C.top();
        C.pop();
    }
    return 0;
}