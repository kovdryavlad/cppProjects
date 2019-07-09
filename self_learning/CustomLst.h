#pragma once
#include "Node.h"

class CustomLst
{
public:
	void add(int n);
	int* ToArray();
	int m_size;

	CustomLst();
	~CustomLst();

private: 
	Node* m_head;
	Node* m_tail;
};

