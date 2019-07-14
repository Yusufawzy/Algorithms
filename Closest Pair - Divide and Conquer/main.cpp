#include <bits/stdc++.h>
using namespace std;
struct point
{
    int first;
    int second ;
    int idx;
};
bool compX(point  p1, point p2)
{

    return p1.first<p2.first;;

}
bool compY(point  p1, point p2)
{

    return p1.second<p2.second;;

}

double dist(point p1, point p2)
{
    return sqrt( (p1.first - p2.first)*(p1.first - p2.first) +
                 (p1.second - p2.second)*(p1.second - p2.second)
               );
}
float getMin(vector<point>::iterator start, int &p1,int &p2,int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(*(start+i), *(start+j)) < min)
            {
                min = dist(*(start+i), *(start+j));

                p1 =(start+i)->idx;
                p2 = (start+j)->idx;
            }

    return min;
}


double stripClosest(vector<point>  strip,int actualN,int &p1,int &p2, double d)
{
    double min = d; // Initialize the minimum distance as d

    sort(strip.begin(),strip.end(),compY);

    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < actualN; ++i)
        for (int j = i+1; j < actualN && (strip[j].second - strip[i].second) < min; j++)
            if (dist(strip[i],strip[j]) < min)
            {

                p1 =strip[i].idx;
                p2 = strip[j].idx;
                min = dist(strip[i], strip[j]);

            }


    return min;
}

double closestRec(vector<point>::iterator start,int &p1,int &p2,int n)
{
    ///what I will dooo -> first I have to send the start and length of each time -> I have to modify brute force but now
    ///
    if (n <= 3)
        return getMin(start,p1,p2, n);

    // Find the middle point
    int mid = n/2;
    point midPoint = *(start+mid);

    int c1,c2,c3,c4;
    double dl = closestRec(start,c1,c2, mid);




    double dr = closestRec(start + mid,c3,c4, n - mid);

    // Find the smaller of two distances
    double minDistance;
    if (dl < dr)
    {

        p1 = c1, p2 = c2;
        minDistance = dl ;
        // cout<<"first is "<<p1<<endl;;
    }
    else
    {
        minDistance = dr ;
        p1 = c3, p2 = c4;
        //cout<<"second is "<<p1<<endl;;
    }

    vector<point>  strips;
    strips.reserve(n);
    int j = 0;

    for (int i = 0; i < n; i++)
        if (abs((start)->first - midPoint.first) <minDistance)
            strips[j] = *(start+i), j++;

    // Find the closest points in strip.
    // Return the minimum of d and closest
    // distance is strip[]
    double minnBtwn = stripClosest(strips, j,c1,c2, minDistance);


    if ( minnBtwn< minDistance)
    {
        p1 = c1;
        p2 = c2;

        return minnBtwn;
    }
    return minDistance;
}
void closestV1(vector<point> points)
{
    int n = points.size();
    sort(points.begin(),points.end(),compX);
    int p1,p2; //I will return the cities number in these two variables
    cout<<"The shortest distance is "<<closestRec(points.begin(),p1,p2,n)<<endl;;
    cout<<"Points are "<<p1<<" and the point "<< p2<<endl;
}
int main()
{
     int cnt = 0,n,x,y;
    //shortest dist is between 0 and 5
    cout<<"Enter number of cities\n",cin>>n;

    vector<point>  points;
    for(int i = 0 ; i < n; i++)
        cin>>x>>y,points.push_back({x,y,i});

    /* 2 3 12 30 40 50 5 1 12 10 3 4 */
    closestV1(points);

}





 ///   {{2, 3,0}, {12, 30,1}, {40, 50,2}, {5, 1,3}, {12, 10,4}, {3, 4,5}};
