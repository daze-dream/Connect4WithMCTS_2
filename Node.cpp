#include "Node.h"


Node::Node()
{
}

Node::~Node()
{
	children.clear();
	parent.reset();
	
}

shared_ptr<Node> Node::selectRandomChild()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	uniform_int_distribution<> dist(0, this->children.size() - 1);
	int selection = dist(gen);
	return children.at(selection);
}

shared_ptr<Node> Node::selectMaxChild()
{
	int selection = 0, compare = 0;
	for (int i = 0; i < children.size(); i++)
	{
		int currVisit = children.at(i).get()->getState().getVisitCount();
		if ( currVisit > compare)
		{
			selection = i;
			compare = currVisit;
		}
	}
	return children.at(selection);
}

