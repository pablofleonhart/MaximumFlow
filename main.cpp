#include <chrono>
#include "fordfulkerson.h"
#include <iostream>
#include <sstream>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;

int main( int argc, char *argv[] )
{
	int who = RUSAGE_SELF; 
	struct rusage usage; 
	int ret;

    string line = "";

    while ( line.substr( 0, 5 ) != "p max" )
    {
        getline( cin, line );
	}

	stringstream pref( line );    
    string ac;
	pref >> ac >> ac >> n >> m;

	while ( line.substr( 0, 1 ) != "n" )
	{
		getline( cin, line );
	}

	stringstream source( line );
	source >> ac >> s;

	getline( cin, line );

	while ( line.substr( 0, 1 ) != "n" )
	{
		getline( cin, line );
	}

	stringstream sink( line );
	sink >> ac >> t;

	unsigned i = 0;
	unsigned u, v, cap;

	Graph g( n + 1 );

    while ( i < m )
    {
        getline( cin, line );

        if ( line.substr( 0, 2 ) == "a " )
        {
            stringstream arc( line );
            
            arc >> ac >> u >> v >> cap;
            g.addEdge( u, v, cap );
            i++;
        }
	}

	HollowHeap heap;

	auto start = std::chrono::high_resolution_clock::now();
	cout << g.getFlow( s, t, heap ) << " ";
	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	cout << std::chrono::duration_cast<std::chrono::milliseconds>( elapsed ).count() << " ";

	ret = getrusage( who, &usage );

	cout << usage.ru_maxrss << endl;

	return 0;
}