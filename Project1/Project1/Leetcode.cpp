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
	ListNode *result = p;			//这里需要格外注意
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

	//使用快慢指针找到链表的中点
	while ( q != NULL && q->next != NULL)
	{
		p = p->next;
		q = q->next->next;
	}

	ListNode* right = sortList(p->next);	//对中点右边的链表进行排序
	p->next = NULL;							//将左边的链表的最后一位置空
	ListNode* left = sortList(head);		//对中点左边的链表进行排序

	return merge(left, right);				//将左右两个链表合并

}


//Sort a linked list using insertion sort.
ListNode* Leetcode::insertionSortList(ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}


}