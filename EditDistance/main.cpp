#include <bits/stdc++.h>
///Name: Yusuf Fawzy Elnady         ID: 20160299        Subject:Edit Distance with three versions
using namespace std;
int M[1000][1000], M2[1000][1000],D[1000][1000];
string str1="abcd", str2="agc";
int n =  str1.length(),m =  str2.length();
int editDist1(string a,string b,int i, int j) ///Edit Distance without DP
{
    if (!i) return j ;
    if (!j) return i ;
    int replacee = a[i]==b[j]?0:1;
    int RM = editDist1(a,b,i-1,j-1)+replacee;
    int D = editDist1(a,b,i-1,j)+1;
    int I = editDist1(a,b,i,j-1)+1;
    return (min(I,min(RM,D)));
}
int editDist2(string a,string b,int i, int j) ///Edit Distance - DP - Top-Down
{
    if (!i) return j ;
    if (!j) return i ;
    if (M[i][j]!=-1)return M[i][j];
    int replacee = a[i]==b[j]?0:1;
    int RM = editDist2(a,b,i-1,j-1)+replacee;
    int D = editDist2(a,b,i-1,j)+1;
    int I = editDist2(a,b,i,j-1)+1;
    int minn = min(I,min(RM,D));
    M[i][j]= minn;
    return minn;
}
void initialize()
{
    for (int i = 0 ; i < 1000 ; i++)
        for (int j = 0 ; j < 1000; j++)
            M[i][j] = -1;
}
void printSol()
{
    cout<<"Steps to be done to match the two words:"<<endl;
    int i = m, j = n ;
    while(true)
    {
        if(i<=0 || j<=0) break;
        int curr = D[i][j];
        if(curr==0) i--,j--;
        else if (curr==1)
        {
            cout<<"Delete  "<<str1[j-1]<<" from string 1"<<endl;
            j--;
        }
        else if (curr==2)
        {
            cout<<"Replace "<<str1[j-1]<<" from string 1 with "<<str2[i-1]<<" from string 2"<<endl;
            i--,j--;
        }
        else if (curr==3)
        {
            cout<<"Insert  "<<str2[i-1]<<" into string 2"<<endl;
            i--;
        }
    }
}
int editDist3(string a, string b) ///Edit Distance - DP - Bottom-UP
{
    int n = a.length(), m = b.length(), L,U,LU;;
    for (int i = 0 ; i <= n ; i++) M2[0][i] = i;
    for (int i = 0 ; i <= m ; i++) M2[i][0] = i;
    for (int i = 1 ; i <= m ; i++)
    {
        for ( int j = 1 ; j <= n ; j++)
            if (a[j-1]==b[i-1])  //cuz I started with index from 1, but I should do iteration on all indexes
                M2[i][j]=M2[i-1][j-1],D[i][j]=0; //means go to the diagonal we don't have any update
            else
            {
                L  = M2[i][j-1];  //left is delete 1
                U  = M2[i-1][j];  //upper is insert 2
                LU = M2[i-1][j-1];//diagonal is replace 3
                if (L<=LU && L<U)D[i][j] = 1;
                else if (LU<=L &&LU<=U) D[i][j] = 2 ;
                else if (U<=LU & U<=L)D[i][j] = 3;
                int minn = 1 + min(LU,min(L,U));
                M2[i][j]=minn;
            }
    }
//    for (int i = 0 ; i <= m ; i++) //we start by rows which is the length of second one
//    {
//        for (int j = 0 ; j <=n ; j++)
//            cout<<M2[i][j]<<" ";
//        cout<<endl;
//    }
    printSol();
    cout<<"\n\n";
    return M2[m][n];
}
int main()
{
    initialize();
    cout<<"String 1 is \""<<str1<<"\"\nString 2 is \""<<str2<<"\"\n\n";
    cout <<"Edit Distance1 is "<< editDist1( str1, str2, n,m)<<"\n\n";;
    cout <<"Edit Distance2 is "<< editDist2( str1, str2, n,m)<<"\n\n";;
    cout <<"Edit Distance3 is "<< editDist3( str1, str2);
    return 0;
}
