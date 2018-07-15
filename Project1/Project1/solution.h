#pragma once
#include "vector"
#include "stack"
#include "queue"
#include "assert.h"
#include "set"
#include "iostream"
#include "unordered_map"
#include "map"

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {}
};
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class solution
{
private:
	stack<int> stack1;
	stack<int> stack2;

	stack<int> mainStack;
	stack<int> assistStack;
	
public:

	solution();
	~solution();
	char * my_strcpy(char * des, const char * src);
	int my_atoi(char * str);
	char * my_itoa(int num);
	int binarySearchCount(vector<int> arr,int num);
	int findMostFrequentInArray(vector<int> array);
	int findMostApperse(vector<int> arr);
	int xor_findDup(vector<int> arr);
	bool find(int target, std::vector<std::vector<int>> array);

	void replaceSpace(char * str, int length);

	void replaceSpace2(char * str, int length);

	std::vector<int> printListFromTailToHead(ListNode * head);

	void push(int node);

	int pop();

	int minNumberInRotateArray(vector<int> rotateArray);

	int Fibonacci1(int n);

	int Fibonacci(int n);

	int jumpFloor(int number);

	int jumpFloorII(int number);

	int rectCover(int number);

	int NumberOf1(int n);

	double Power(double base, int exponent);

	void reOrderArray(vector<int>& array);

	ListNode * FindKthToTail(ListNode * pListHead, unsigned int k);

	ListNode * ReverseList(ListNode * pHead);

	ListNode * Merge(ListNode * pHead1, ListNode * pHead2);

	ListNode * Merge2(ListNode * pHead1, ListNode * pHead2);

	bool HasSubtree(TreeNode * pRoot1, TreeNode * pRoot2);

	void Mirror(TreeNode * pRoot);

	void stack_push(int value);

	void stack_pop();

	int stack_top();

	int stack_min();

	bool IsPopOrder(vector<int> pushV, vector<int> popV);

	vector<int> PrintFromTopToBottom(TreeNode * root);

	bool VerifySquenceOfBST(vector<int> sequence);

	char* bitSort(char *filename, int len);

	RandomListNode * Clone(RandomListNode * pHead);

	vector<int> printMatrix(vector<vector<int>> matrix);

	vector<int> GetLeastNumbers_Solution(vector<int> input, int k);

	int MoreThanHalfNum_Solution(vector<int> numbers);

	vector<string> Permutation(string str);

	int FindGreatestSumOfSubArray(vector<int> array);

	vector<vector<int>> FindPath(TreeNode * root, int expectNumber);

	TreeNode * Convert(TreeNode * pRootOfTree);

	void printSuShu();

	int findSecondMax(vector<int> &data);

	void FindNumsAppearOnce(vector<int> data, int * num1, int * num2);

	vector<int> FindNumbersWithSum(vector<int> array, int sum);

	vector<int> FindNumbersWithSum2(vector<int> array, int sum);

	vector<vector<int>> FindContinuousSequence(int sum);

	string LeftRotateString(string str, int n);

	string LeftRotateString2(string str, int n);

	int SumN(int n);

	int Add(int num1, int num2);

	int StrToInt(string str);

	vector<int> multiply(const vector<int>& A);

	ListNode * EntryNodeOfLoop(ListNode * pHead);

	ListNode * deleteDuplication(ListNode * pHead);

	TreeLinkNode * GetNext(TreeLinkNode * pNode);

	bool match(char * str, char * pattern);

	int findMaxSubString(string str1, string str2, string & result);

	bool isSymmetrical(TreeNode * pRoot);

	vector<vector<int>> print(TreeNode * pRoot);

	TreeNode * KthNode(TreeNode * pRoot, int k);

	TreeNode * KthNode2(TreeNode * pRoot, int k);


	int LastRemaining(int n, int m);

	string ReverseSentence(string str);

	int binarySearch1(vector<int> &data, int k);

	int binarySearch2(vector<int> &data, int k);
	
	std::vector<int> printListFromTailToHead2(ListNode * head);


};

