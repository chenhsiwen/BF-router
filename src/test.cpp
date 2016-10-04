#include<iostream>
#include<algorithm>
#include<fstream>
#include<iomanip>
using namespace std;

int main()
{
    fstream  fin1("..\\outputs\\out1.txt",ios::in);
    fstream  fin2("..\\outputs_C\\out1.txt",ios::in);
    if (!fin2||!fin1)
        cout << "Error opening input file" << endl;
    else
    {
        int check=0;
        int a,b;
        while(fin1!=NULL&&fin2!=NULL)
        {
            fin1>>a;
            fin2>>b;
            if(a!=b)
                check=1;
        }
        cout<<check;
    }
}

