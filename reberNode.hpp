/** reberNode.hpp
 * Contains class declaration for a node of a Reber grammar.
 * Dylan Auty, January 2016
 */

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class reberNode{
	int connectionNumber;
	vector<reberNode*> connections;		// Vector of pointers to the connected node, which can include itself.
	vector<char> connectionValues;		// Character values associated with each edge transition.

	public:
		reberNode(int);
		void connectToNodes(vector<reberNode*>, vector<char>);	// Connection requires a pair of vectors of the correct size
		reberNode* transition();	// Method to randomly pick an edge to jump along, print it's character, then jump

};

reberNode::reberNode(int connNumInput){
	// Set up variables, resize connectionptr vector appropriately and fill it with NULL
	connectionNumber = connNumInput;
	connections.resize(connectionNumber, NULL);	// Make some blank connections
}

void reberNode::connectToNodes(vector<reberNode*> nodePtrs, vector<char> connValInput){
	connectionValues.resize(connValInput.size());
	connectionValues = connValInput;
	// Define some iterators:
	vector<char>::iterator itChar = connectionValues.begin();
	vector<char>::iterator itConnValInput = connValInput.begin();
	vector<reberNode*>::iterator itNodePtrs = nodePtrs.begin();
	vector<reberNode*>::iterator itNode = connections.begin();

	for(int i = 0; i < connectionNumber; i++){
		*itNode = *itNodePtrs;
		*itChar = *itConnValInput;
		++itNode;
		++itNodePtrs;
		++itChar;
		++itConnValInput;
	}	// At this point the node should be all connected up
	
}

reberNode* reberNode::transition(){
	int randNum = rand() % connectionNumber;
	cout << connectionValues.at(randNum);
	return connections.at(randNum);
}
