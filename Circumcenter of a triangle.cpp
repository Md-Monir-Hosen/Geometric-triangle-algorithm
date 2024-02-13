#include<bits/stdc++.h>
using namespace std;
#define pdd pair<double,double>
void lineFromPoints(pdd P, pdd Q, double &a,
                        double &b, double &c)
{
    a = Q.second - P.second;
    b = P.first - Q.first;
    c = a*(P.first)+ b*(P.second);
}
void perpendicularBisectorFromLine(pdd P, pdd Q,
                 double &a, double &b, double &c)
{
    pdd mid_point = make_pair((P.first + Q.first)/2,
                            (P.second + Q.second)/2);
    c = -b*(mid_point.first) + a*(mid_point.second);

    double temp = a;
    a = -b;
    b = temp;
}
pdd lineLineIntersection(double a1, double b1, double c1,
                         double a2, double b2, double c2)
{
    double determinant = a1*b2 - a2*b1;
    if (determinant == 0)
    {
        return make_pair(FLT_MAX, FLT_MAX);
    }

    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return make_pair(x, y);
    }
}

void findCircumCenter(pdd P, pdd Q, pdd R)
{

    double a, b, c;
    lineFromPoints(P, Q, a, b, c);
    double e, f, g;
    lineFromPoints(Q, R, e, f, g);
    perpendicularBisectorFromLine(P, Q, a, b, c);
    perpendicularBisectorFromLine(Q, R, e, f, g);
    pdd circumcenter =
           lineLineIntersection(a, b, c, e, f, g);

    if (circumcenter.first == FLT_MAX &&
        circumcenter.second == FLT_MAX)
    {
        cout << "The two perpendicular bisectors "
                "found come parallel" << endl;
        cout << "Thus, the given points do not form "
                "a triangle and are collinear" << endl;
    }

    else
    {
        cout << "The circumcenter of the triangle PQR is: ";
        cout << "(" << circumcenter.first << ", "
             << circumcenter.second  << ")" << endl;
    }
}
int main()
{
    pdd P = make_pair(6, 0);
    pdd Q = make_pair(0, 0);
    pdd R = make_pair(0, 8);
    findCircumCenter(P, Q, R);
    return 0;
}
