CC = g++
SHARED = -shared -o
clean:
	rm -rf *.o *.so TestSockLib

all:

	$(CC) -c -Wall -fpic printaddressinfo.cpp
	$(CC) $(SHARED) libGetAddressInfo.so *.o
	$(CC) -L/home/ekukuna/QT/SockLib -o TestSockLib main.cpp -lGetAddressInfo
buildLibrary:
	$(CC) $(SHARED) libGetAddressInfo.so *.o

buildTestBinary:
	$(CC) -L/home/ekukuna/QT/SockLib -o TestSockLib main.cpp -lGetAddressInfo
	
	
	