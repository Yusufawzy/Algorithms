#include <bits/stdc++.h>
using namespace std;
float power(int a,int n)
{
    if (n==0)
        return 1;
    else if (n==1 || a==1)
        return a;
    if (n>1)return a*power(a,n-1);
    return (power(a,n+1))/a;
}

float power_float(int a,int n)
{
    float t;
    if (n==0)return 1;
    t = power_float(a,n/2);//we calculate it one time then use it in below calling so it is O(log n)
    if (n%2==0)
    {
        return t * t;
    }
    else
    {
        if (n>0)
        {
            return (a*t*t);   // because if 6^5 it will be 6 * 6^2 * 6^2
        }
        else return (t*t)/a;
    }

}

int main()
{
    int a,n;
    cout<<"Enter The Base: ";cin>>a;
    cout<<"Enter The Power: ";cin>>n;
    cout<<"The Result using first Function "<<power(a,n)<<endl;
    cout<<"The Result using second Function "<<power_float(a,n)<<endl;
    return 0;
}
