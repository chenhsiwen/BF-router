#include "distance-vector.h"

using namespace std;

int main()
{
    fstream  fin("..\\testfiles\\in8.txt",ios::in);
    ofstream  fout("..\\outputs\\out8.txt",ios::out);
    if (!fout||!fin)
        cout << "Error opening input file" << endl;
    else
    {
        int num_node;
        fin>>num_node;
        int ***D = int3(num_node);
        int** cost = int2(num_node);
        int** shortest = int2(num_node);
        input(fin,D,cost,shortest,num_node);
        int time=0;
        while(1)
        {
            int conti=0;
            conti=router(D,cost,shortest,num_node,time);
            BF(cost,shortest,num_node);
            output(fout,D,shortest,num_node,time);
            if(!conti) break;
            time++;
        }
    }
}

