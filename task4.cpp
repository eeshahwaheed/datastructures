#include <iostream>
#include <conio.h>
using namespace std;

void swap(int*a,int*b)
{
    int c=*a;   
    *a=*b;         
    *b=c;       
}

int main() 
{
    int x=5;
	int y=15;

    cout<<"Before swap:"<<endl;
    cout<<"x = "<<x<<","<<"y = "<<y<<endl;


    swap(&x,&y);

    cout<<"After swap:"<<endl;
    cout<<"x = "<<x<<","<<"y = "<<y<<endl;

    return 0;
}

