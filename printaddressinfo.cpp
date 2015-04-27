#include"printaddressinfo.h"



bool PrintAddressInfo::validateArgCount(int aArgc)
{
	if( aArgc !=  2)
	{
		return false;
	}
	else
	{
		return true;
	}
}

string PrintAddressInfo::getMyURL() const
{
	return myURL;
}

void PrintAddressInfo::setMyURL(const string &value)
{
	myURL = value;
}

void PrintAddressInfo::printDomainDetails()
{
	addrinfo *itr;
	char *charIPPTr;
	char ipstr[INET6_ADDRSTRLEN];

	for(itr = myResult;itr!=NULL;itr = itr->ai_next)
	{
		void *ptr;
		if(itr->ai_family == AF_INET)
		{
			cout<<"This is IPV4 Address "<<endl;
			struct sockaddr_in *p4Address = (struct sockaddr_in *)itr->ai_addr;
			ptr = &(p4Address->sin_addr);
		}
		else
		{
			cout<<"This is IPV6 Address "<<endl;
			struct sockaddr_in6 *ipv6 = (sockaddr_in6*)itr->ai_addr;
			ptr = &(ipv6->sin6_addr);

		}
		inet_ntop(itr->ai_family,ptr,ipstr,sizeof(ipstr));
		cout<<"IP address :"<<ipstr<<endl;
	}
}

bool PrintAddressInfo::getDomanDetails()
{
	if(getaddrinfo(myURL.c_str(),NULL,&myHints,&myResult) != 0 )
	{
		cerr<<"Error while getaddrinfo"<<endl;
		return false;
	}
	else
	{
		cout<<"Successfully executed GetAddressInfo"<<endl;
		printDomainDetails();
		return true;
	}
}
