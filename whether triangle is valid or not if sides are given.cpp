#include<bits/stdc++.h>
using namespace std;
bool checkValidity(int a,int b,int c)
{
    if(a+b<=c || a+c<=b || b+c<= a)
        return false;
    else
        return true;
}
int main()
{
     int a = 7, b = 10, c = 5;
    if (checkValidity(a, b, c))
        cout << "Valid";
    else
        cout << "Invalid";
}
