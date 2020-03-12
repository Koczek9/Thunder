#include<iostream>
#include<securityagent/securityagent.h>
#include<cstring>

using namespace std;

#define MAX_LENGTH 2048

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        cout << "Enter the url to get token" << endl;
        return -1;
    }
    
    unsigned char buffer[MAX_LENGTH] = {0};
    
    size_t len = strlen(argv[1]);
    
    if(!memcpy(buffer,argv[1],len))
    {
        cout << "error in copying input into buffer" << endl;
        return -1;
    }
    
    int ret = GetToken(MAX_LENGTH,len,buffer);
    
    if(ret < 0)
    {
        cout << "error in getting token. Ret value " << ret << endl; 
        return -1;
    }
    else
    {
        cout << "retrieved token successfully" << endl;
        cout << buffer << endl;
    }
    
    return 0;
    
}
