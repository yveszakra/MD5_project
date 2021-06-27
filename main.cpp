#include <iostream>
#include <string>
#include<stdlib.h>
#include<time.h>
#include <fstream>
#include <cstring>
#include<unistd.h>

#include "md5.cpp"

using namespace std; 
using std::cout; using std::endl;


std::string passworGen(int len)
{
    //srand(time(0));
    
    char valid[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()_+=-";
    char rand_array[250];
    const int l = 76;               // 76 is the length of string 'valid'
    
    for (int i = 0; i < len; ++i )
    {
        //rand_array[i] = valid[rand() % l]; 
		rand_array[i] = valid[rand() % (sizeof(valid) - 1)];   
    }
    
    //cout<<"The Random Array is :\n"<<rand_array << endl;
    
    return rand_array;
        
}

 
int main(int argc, char *argv[])
{
	//randPass = crypt
	//passworGen();
	std::string password1 = "Mygrape";
	std::string password2 = passworGen(100);
	std::string salt = passworGen(50);
	std::string function = md5(salt + password2) ;
    cout << "md5 of 'grape': " << md5("grape") << endl;
    cout << "md5 of password 1: " << md5(password1) << endl;
    cout << "md5 of password 2: " << md5(password2) << endl;
    cout << "md5 of salt: " << function << endl;
    cout << endl << endl;
    cout << "=============================================================" << endl << endl;
    int max = 21;
	std::string array[max][4];
    
    cout  << " ID  |                      Salt                              |                  Hash                |" ;
     
    for (int i = 1; i < max; ++i){
    	//ostringstream convert;
    	//convert << i;
    	std::string userID = to_string(i);
//    	cout << "enter UserID: ";
//    	cin >> userID;
    	cout << endl << endl;
    	for(int j = 1; j <= 3; ++j){
    		if (j == 3){
    			std::string pass = passworGen(100);
    			std::string hash = md5(pass);
    			array[i][j] = hash;
    			//array[i][j] = userID;
    			//cout << "[" << i << "][" << j << "] = " << array[i][j] << endl;
			}
			else if (j == 2){
				std::string salty = passworGen(50);
    			array[i][j] = salty;
			}
    		else if (j == 1){
    			array[i][j] = userID;
//    			std::string pass = passworGen(100);
//    			std::string hash = md5(pass);
//    			array[i][j] = hash;
			}
//			cout << "[" << i << "][" << j << "] = " << array[i][j] << endl;
			cout  << "  "<< array[i][j] << "  |  " ;
			
			//usleep(300000);

    	 
		}
		cout << endl << endl;
	}
    
    //std::string output = md5(password2);
    //decode(output, password2, 100);
    
    //cout << "decoded value is: " << MD5::decode(output, password2, 100) << endl;
    return 0;
}
