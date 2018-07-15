#include "Leetcode.h"



Leetcode::Leetcode()
{
}


Leetcode::~Leetcode()
{
}

//Sort a linked list in O(n log n) time using constant space complexity.
ListNode* merge(ListNode* left, ListNode* right)
{
	ListNode *p = new ListNode(0);
	ListNode *result = p;			//������Ҫ����ע��
	while (left != NULL && right != NULL)
	{
		if (left->val < right->val)
		{
			p->next = left;
			left = left->next;
		}
		else
		{
			p->next = right;
			right = right->next;
		}
		p = p->next;
	}

	if (left != NULL)
	{
		p->next = left;
	}
	if (right != NULL)
	{
		p->next = right;
	}

	return result->next;
}
ListNode* Leetcode::sortList(ListNode *head) {
	if (head == NULL || head ->next == NULL)
	{
		return head;
	}

	ListNode *p = head;
	ListNode *q = head->next;

	//ʹ�ÿ���ָ���ҵ�������е�
	while ( q != NULL && q->next != NULL)
	{
		p = p->next;
		q = q->next->next;
	}

	ListNode* right = sortList(p->next);	//���е��ұߵ������������
	p->next = NULL;							//����ߵ���������һλ�ÿ�
	ListNode* left = sortList(head);		//���е���ߵ������������

	return merge(left, right);				//��������������ϲ�

}


//Sort a linked list using insertion sort.
ListNode* Leetcode::insertionSortList(ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}


}