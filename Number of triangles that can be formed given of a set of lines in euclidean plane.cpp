#include <bits/stdc++.h>
using namespace std;

#define EPSILON numeric_limits<double>::epsilon()
bool compareDoubles(double A, double B)
{
    double diff = A-B;
    return (diff<EPSILON) && (-diff<EPSILON);
}
int numberOfTringles(int a[], int b[], int c[], int n)
{

int i;
    double slope[n];
    for ( i=0; i<n; i++)
        slope[i] = (a[i]*1.0)/b[i];
    sort(slope, slope+n);
    int count[n], k = 0;
    int this_count = 1;
    {
        if (compareDoubles(slope[i], slope[i-1]))
            this_count++;
        else
        {
            count[k++] = this_count;
            this_count = 1;
        }
    }
    count[k++] = this_count;

    int sum1 = 0;
    for (int i=0; i<k; i++)
        sum1 += count[i];
    int sum2 = 0;
    int temp[n];
    for (int i=0; i<k; i++)
    {
        temp[i] = count[i]*(sum1-count[i]);
        sum2 += temp[i];
    }
    sum2 /= 2;

    int sum3 = 0;
    for (int i=0; i<k; i++)
        sum3 += count[i]*(sum2-temp[i]);
    sum3 /= 3;

    return sum3;
}

int main()
{

    int a[] = {1, 2, 3, 4};
    int b[] = {2, 4, 5, 5};
    int c[] = {5, 7, 8, 6};
    int n = sizeof(a)/sizeof(a[0]);

    cout << "The number of triangles that"
            " can be formed are: "
         << numberOfTringles(a, b, c, n);

    return 0;
}
