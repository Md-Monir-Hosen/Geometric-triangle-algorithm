#include <bits/stdc++.h>
using namespace std;

float cal_cos(float n)
{
    float accuracy = 0.0001, x1, denominator, cosx, cosval;

    n = n * (3.142 / 180.0);

    x1 = 1;

    cosx = x1;

    cosval = cos(n);
    int i = 1;
    do {
        denominator = 2 * i * (2 * i - 1);
        x1 = -x1 * n * n / denominator;
        cosx = cosx + x1;
        i = i + 1;
    } while (accuracy <= fabs(cosval - cosx));

    return cosx;
}

float third_side(int a, int b, float c)
{
    float angle = cal_cos(c);
    return sqrt((a * a) + (b * b) - 2 * a * b * angle);
}

int main()
{
    float c = 49;
    int a = 5, b = 8;
    cout << third_side(a, b, c);

    return 0;
}
