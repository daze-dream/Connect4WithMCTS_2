#pragma once
#include "GameState.h"
#include <memory>
#include <vector>

using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;
using std::vector;

class Node
{
public:
	Node();
	~Node();
	Node(GameState incState) : currState(incState) {};
	Node(GameState incState, shared_ptr<Node> incParent) :currState(incState), parent(incParent) { };
	GameState getState() { return currState; }
	shared_ptr<Node> getParent() { return parent.lock(); };
	vector<shared_ptr<Node>> getChildren() { return children; }

	void setState(GameState gs) { currState = gs; };
	void setChildren(vector<shared_ptr<Node>> incChildren) { children = incChildren; };
	void setParent(shared_ptr<Node> incParent) { parent = incParent; };




private:
	weak_ptr<Node> parent;
	vector<shared_ptr<Node>> children = {};
	GameState currState;
};