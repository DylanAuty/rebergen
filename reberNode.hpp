/** reberNode.hpp
 * Contains class declaration for a node of a Reber grammar.
 * Dylan Auty, January 2016
 */

#include <iostream>
#include <vector>

using namespace std;

class reberNode{
	int connectionNumber;
	vector<reberNode*> connections;

	public:
		reberNode(int);

};

reberNode::reberNode(int connNumInput){
	// Set up variables, resize connectionptr vector appropriately and fill it with NULL
	connectionNumber = connNumInput;
	connections.resize(connectionNumber);
	fill(connections.begin(), connections.end(), NULL);
}
