
/*
 * The purpose of this file to test the Library being created as SockLib Project.
 */
#include"printaddressinfo.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    PrintAddressInfo thePrintAddressInfo;
    if(thePrintAddressInfo.validateArgCount(argc))
    {
        cout<<"Argument supplied :"<<argv[1]<<endl;
        thePrintAddressInfo.setMyURL(string(argv[1]));
        thePrintAddressInfo.setHintsRegular();
        thePrintAddressInfo.getDomanDetails();
    }
    else
    {
        cerr<<"You have provided wrong number of arguments...Exiting program."<<endl;
        exit(-1);
    }

    return 0;
}
