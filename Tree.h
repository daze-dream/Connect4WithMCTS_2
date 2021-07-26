#pragma once
#include "Node.h"
#include <memory>

using std::shared_ptr;


class Tree
{
public:
	Tree();
	Tree(shared_ptr<Node> incRoot) : root(incRoot) {};
	void setRoot(shared_ptr<Node> incRoot) { root = incRoot; }
	~Tree();

protected:
	weak_ptr<Node> root;
};

