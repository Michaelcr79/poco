// Modified by: Michael C. Robinson
// poco-dns.cpp: Use the poco C++ library to look up a DNS hostname.
// There is an untraced problem with IP addresses coming back in triplicate.


#include <iostream>
#include "Poco/Net/DNS.h"
using Poco::Net::DNS;
using Poco::Net::IPAddress;
using Poco::Net::HostEntry;



int main(int argc, char** argv)
{
    char * address = NULL;

    // Make sure that the number of arguments is correct.
    // This would be a good place to verify that the address
    // string follows the rules for a valid hostname before
    // trying to use the string.
    if ( argc == 2 )
    {
         address = argv[1];
    }
    else
    {
         std::cout << "No URL provided!  Usage: poco-dns <URL>" << std::endl;
         return 1;
    }

    // Look up address...
    const HostEntry& entry = DNS::hostByName(address);

    // Output the canonical name of address...
    std::cout << "Canonical Name: " << entry.name() << std::endl;

    // Take entry and compile the aliases...
    const HostEntry::AliasList& aliases = entry.aliases();

    // Take entry and compile the addresses...
    const HostEntry::AddressList& addrs = entry.addresses();

    // Loop through the aliases and output them...
    for ( HostEntry::AliasList::const_iterator it = aliases.begin() ;
          it != aliases.end() ; ++it )
       std::cout << "Alias: " << *it << std::endl;

    // Loop through the addresses and output them...
    for ( HostEntry::AddressList::const_iterator it = addrs.begin();
          it != addrs.end(); ++it )
       std::cout << "Address: " << it->toString() << std::endl;

    return 0;
}
