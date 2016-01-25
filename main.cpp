
#include <iostream>
#include "reberNode.hpp"
#include <ctime>

using namespace std;

int main(){
	
	reberNode* currentNode = NULL;
	reberNode n1(2), n2(2), n3(2);
	vector<reberNode*> v1 = {&n1, &n2};
	vector<char> c1 = {'B', 'C'};
	n1.connectToNodes(v1, c1);
	srand(time(NULL));
	n1.transition();
	return 0;
}

