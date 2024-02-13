#include<bits/stdc++.h>
using namespace std;
#define PI 3.1416
int lengthSquare(pair<int,int>x,pair<int,int>y)
{
    int m=x.first-y.first;
    int n=x.second-y.second;
    return m*m+n*n;
}
void printAngle(pair<int,int>A,pair<int,int>B,pair<int,int>C)
{
    int a2=lengthSquare(B,C);
    int b2=lengthSquare(A,C);
    int c2=lengthSquare(A,B);

    float a=sqrt(a2);
    float b=sqrt(b2);
    float c=sqrt(c2);

    float alpha=acos((b2+c2-a2)/(2*b*c));
    float beta=acos((a2+c2-b2)/(2*a*c));
    float gamma=acos((b2+a2-c2)/(2*a*b));

    alpha=alpha*180/PI;
    beta=beta*180/PI;
    gamma=gamma*180/PI;

    cout << "alpha : " << alpha << endl;
    cout << "beta : " << beta << endl;
    cout << "gamma : " << gamma << endl;
}
int main()
{
     pair<int,int> A = make_pair(0,0);
    pair<int,int> B = make_pair(0,1);
    pair<int,int> C = make_pair(1,0);

    printAngle(A,B,C);

    return 0;
}
