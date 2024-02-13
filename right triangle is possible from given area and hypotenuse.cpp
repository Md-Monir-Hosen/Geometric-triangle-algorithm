#include<bits/stdc++.h>
using namespace std;
void findRightAngle(int A,int H)
{
    long D=pow(H,4)-16*A*A;
    if(D>=0)
    {
         long root1 = (H * H + sqrt(D)) / 2;
        long root2 = (H * H - sqrt(D)) / 2;

        long a = sqrt(root1);
        long b = sqrt(root2);

        if (b >= a)
        cout << a << " " << b << " " << H;
        else
        cout << b << " " << a << " " << H;
    }
    else
    cout<<"-1";
}
int main()
{
    findRightAngle(6, 5);
    return 0;
}
