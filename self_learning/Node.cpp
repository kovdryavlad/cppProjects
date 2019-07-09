#include "Node.h"
#include "Dbg_new_macros.h"

Node::Node(int n)
{
	m_value = n;
	m_nextNode = nullptr;
}


Node::~Node()
{
}
