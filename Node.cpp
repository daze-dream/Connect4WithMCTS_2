#include "Node.h"

Node::Node()
{
}

Node::~Node()
{
	children.clear();
	parent.reset();
	
}

