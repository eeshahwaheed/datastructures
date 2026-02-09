#include <iostream>
#include<conio.h>
using namespace std;

int main() 
{
 int arr[5]={11,24,38,54,5};
 
 int*ptr=arr;
 
 cout << "ARRAY" << endl;
 
 for(int i=0;i<5;i++)
  {
  cout<<*(ptr+i)<<endl;
  }
  
  return 0;
  
}

