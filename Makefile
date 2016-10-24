all:dns tcpstream

dns:poco-dns.cpp 
	g++ -o poco-dns poco-dns.cpp -l PocoNet

tcpstream:pocotcpstream.cpp
	g++ -o poco-tcpstream pocotcpstream.cpp -l PocoNet -l PocoFoundation

clean:
	rm -f poco-dns poco-tcpstream
