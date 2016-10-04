#include<iostream>
#include<algorithm>
#include<fstream>
#include<iomanip>
#define INF 1e7
using namespace std;
void input(fstream& fout,int ***D,int** cost,int** shortest,const int num_node);
int*** int3(const int num_node);
int** int2(const int num_node);
bool router(int*** D,int **cost,int **shortest,int num_node,int t);
void BF(int **cost,int **shortest,int n);
void output(ofstream& fout,int ***D,int** shortest,const int num_node,const int t);
int shortestpath(int ***D,int i,int j,int num_node);

void input(fstream& fin,int ***D,int** cost,int** shortest,const int num_node)
{
    for(int i=0;i<num_node;i++)
    {
        for(int j=0;j<num_node;j++)
        {
            for(int k=0;k<num_node;k++)
            {
                D[i][j][k] = INF;
            }
            shortest[i][j] = INF;
            fin >> cost[i][j];
            if(i!=j && cost[i][j] == 0) cost[i][j] = INF;
        }
        shortest[i][i] = 0;
    }
}
int*** int3(const int num_node)
{
    int ***data;
    data = new int**[num_node];
    for(int i=0;i<num_node;i++)
    {
        data[i]= new int*[num_node];
    }
    for(int i=0;i<num_node;i++)
    {
        for(int j=0;j<num_node;j++)
        {
            data[i][j] = new int[num_node];
        }
    }
    return data;
}
int** int2(const int num_node)
{
    int **data;
    data = new int*[num_node];
    for(int i=0;i<num_node;i++)
    {
        data[i]= new int[num_node];
    }
    return data;
}
int shortestpath(int ***D,int i,int j,int num_node)
{
    int path=INF;
    for(int k=0;k<num_node;k++)
    {
        if( i==k || j==k ) continue;
        else
        {
            if(path< D[i][j][k])
            path =  D[i][j][k];
        }
    }
    return path;

}
bool router(int*** D,int **cost,int **shortest,int num_node,int t)
{
    bool bot=0;
    for(int i=0;i<num_node;i++)
    {
        for(int j=0;j<num_node;j++)
        {
            for(int k=0;k<num_node;k++)
            {
                if( i==j || i==k ) continue;
                else
                {
                    int temp=D[i][j][k];
                    D[i][j][k] = min(D[i][j][k],cost[i][j]+shortest[j][k]);
                    if(temp !=D[i][j][k])
                        bot = 1;
                }
            }
        }
    }
    return bot;
}
void BF(int **cost,int **shortest,int num_node)
{
    bool bot=0;
    for(int i=0;i<num_node;i++)
    {
        for(int j=0;j<num_node;j++)
        {
            for(int k=0;k<num_node;k++)
            {
                shortest[i][j] = min(shortest[i][j],cost[i][k]+shortest[k][j]);
            }
        }
    }
}
void output(ofstream& fout,int ***D,int** shortest,const int n,const int t)
{
    fout<<"T = "<<t<<endl;
    for(int i=0;i<n;i++){
        fout<<"From node "<<i<<endl;
        fout<<'(';
        for(int j=0;j<n;j++)
        {
            int x=shortest[i][j] ;
            if(x==INF)
                fout <<"inf";
            else
                fout << x;
            if(j<n-1 )
                fout << ", ";
        }
        fout<<")" <<endl;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(k == i || j == i )
                fout<<setw(6)<<"x";
                else
                {
                    if(D[i][k][j]==INF)
                        fout<<"      ";
                    else
                        fout<<setw(6)<<D[i][k][j];
                }
            }
            fout<<endl;
        }
    }
}
