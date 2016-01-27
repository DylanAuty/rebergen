/** main.cpp
 * Main function used by the Reber Grammar string generator
 * Dylan Auty, January 2016
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "reberNode.hpp"

using namespace std;

int main(int argc, char* argv[]){
	srand(time(NULL));	// Seed rand()
	if (argc != 2){
		cerr << "ERROR: Please enter only one argument." << endl;
		exit(1);
	}
	else {
		switch(argv[1]):
		case "-h":
			printHelp();
			return 0;
		case "-r":
			printReberString();
			return 0;
		case "-e":
			printEmbeddedReberString();
			return 0;
	}

	reberNode* currentNode = NULL;
	reberNode n1(2), n2(2), n3(2);
	vector<reberNode*> v1 = {&n1, &n2};
	vector<char> c1 = {'B', 'C'};
	n1.connectToNodes(v1, c1);
	n1.transition();
	return 0;
}

