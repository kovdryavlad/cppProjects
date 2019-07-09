#include "CustomLst.h"
#include "Dbg_new_macros.h"

void CustomLst::add(int n)
{
	if (m_size == 0)
		m_tail = m_head = DBG_NEW Node(n);
	
	else
		m_tail = m_tail->m_nextNode = DBG_NEW Node(n);
	
	m_size++;
}

int* CustomLst::ToArray() 
{
	int* result = DBG_NEW int[m_size];
	Node* current = m_head;
	
	for (size_t i = 0; i < m_size; i++)
	{
		result[i] = current->m_value;
		current = current->m_nextNode;
	}

	return result;
}

CustomLst::CustomLst()
{

}


CustomLst::~CustomLst()
{
	Node* head = m_head;

	while (head)
	{
		Node* oldHead = head;
		head = oldHead->m_nextNode;
		
		delete oldHead;
	}
}
