#ifndef PRINTADDRESSINFO_H
#define PRINTADDRESSINFO_H

#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

using namespace std;


/*

#if defined PrintAddressInfo
 #define PrintAddressInfo Q_DECL_EXPORT
#else
 #define PrintAddressInfo Q_DECL_IMPORT
#endif
*/


class PrintAddressInfo
{
private:
    string myURL;
    struct addrinfo myHints;
    struct addrinfo *myResult;

    void printDomainDetails();


public:
    bool validateArgCount(int aArgc);
    string getMyURL() const;
    void setMyURL(const string &value);


    PrintAddressInfo():myURL("")
    {
        memset(&myHints,0,sizeof(myHints));
    }


    void setHintsRegular()
    {
        myHints.ai_family = AF_UNSPEC;
        myHints.ai_protocol = SOCK_STREAM;
    }

    bool getDomanDetails();

};

#endif // PRINTADDRESSINFO_H

