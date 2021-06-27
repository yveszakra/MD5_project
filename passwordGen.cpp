#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
    srand(time(0));
    
    int len = 10;
    char valid[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char rand_array[250];
    const int l = 62;               // 62 is the length of string 'valid'
    
    cout<<"Enter length of random array required(upper limit = 250)\n";
    //cin>>len;
    
    for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }
    
    cout<<"The Random Array is :\n"<<rand_array;
        
}
