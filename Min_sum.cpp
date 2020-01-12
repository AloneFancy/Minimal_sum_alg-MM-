#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include<cstdio>
#include <algorithm>   

using namespace std;

bool read_file(ifstream &infile,int *&a,int&N)
{
    if(!infile) return false;
    infile>>N;
    a=new int[N];
    for (int i=0;i<N;i++)
                infile>>a[i];
    return true;
}

int main(int argc,char* argv[])
{
    ifstream infile;
    
    int N;
    int i=0;      
    int *a;   
    int start,end;
    do
        {
            infile.open(argv[++i]);            
            if(read_file(infile,a,N))
            {
                int k = 1;
                int t = a[0];
                int s = a[0];
                start=0;
                while (k != N) {
                    t = min(t + a[k], a[k]);
					if (a[k]==t)start=k;
                    s = min(s,t);
					if (s==t)end=k;
                    k++;
                }
                cout<<"The minimal-sum section's value is"<<s<<"\n"<<"Its range is from "<<start<<" to "<<end<<endl;            
            }
            infile.close();
        }while (infile);
               
 
    return 0;
}