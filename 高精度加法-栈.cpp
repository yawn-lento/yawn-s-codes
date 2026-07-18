#include<iostream>
#include<string>
#include<stack>
using namespace std;
string add(string a, string b)
{
    stack<int> A,B,C;
    string c = "";
    for (int i = 0; i < a.size(); i++) A.push(a[i] - '0');
    for (int i = 0; i < b.size(); i++) B.push(b[i] - '0');
    int t = 0;     
    while (!A.empty() || !B.empty() || t) 
    {
        if (!A.empty()) { t += A.top(); A.pop(); } 
        if (!B.empty()) { t += B.top(); B.pop(); }
        C.push(t % 10);
        t /= 10;   
    }    
    while (!C.empty())
    {
        c+=to_string(C.top());
        C.pop();        
    }
    return c;
}

string factorial(int n)
{
	string multi="1";
    for (int i = 1; i < n + 1; i++)
    {
        string temp = multi;
        for (int j = 0; j < i-1; j++)
        {
            multi = add(multi, temp);
        }
    }
	return multi;
}
int main()
{
	int n;
	cin >> n;
    string s[50] = {""};
	for (int i = 0; i <n; i++)
		s[i]=factorial(i + 1);
    string sum = "";
    for (int i = 0; i < n+1; i++)
        sum = add(sum, s[i]);
    cout << sum;
}