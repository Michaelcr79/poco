#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/StreamCopier.h"
#include <iostream>

int main(int argc, char** argv)
{
    Poco::Net::SocketAddress sa("www.appinf.com", 443);
    Poco::Net::StreamSocket socket(sa);
    Poco::Net::SocketStream str(socket);

    str << "GET / HTTPS/2.0\r\n"
        << "Host: www.appinf.com\r\n"
        << "\r\n";
    str.flush();

    Poco::StreamCopier::copyStream(str, std::cout);
 
    return 0;
}
