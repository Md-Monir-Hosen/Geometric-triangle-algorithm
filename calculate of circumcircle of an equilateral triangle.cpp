#include <iostream>
#include <math.h>
const double pi = 3.14159265358979323846;

using namespace std;
float area_circumscribed(float a)
{
    return (a * a * (pi / 3));
}

int main()
{
    float a, Area;
    a = 6;

    Area = area_circumscribed(a);
    cout << "Area of CircumCircle :" << Area;
    return 0;
}
