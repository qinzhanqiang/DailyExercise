#include "iostream"
#include "solution.h"
#include "Leetcode.h"
#include "main.h"
using namespace std;

int main()
{
	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);

	tmpFlag |= _CRTDBG_LEAK_CHECK_DF;

	_CrtSetDbgFlag(tmpFlag);


	solution s;

	//1
	cout << endl << "第1个测试实例" << endl;
	vector<vector<int>> a;
	a = { {1,2,3,4},{2,3,4,5},{3,4,5,6}};
	if (s.find(8, a))
	{
		cout << "yes"<<endl;
	}
	else
	{
		cout << "no"<<endl;
	}


	//2
	cout << endl << "第2个测试实例" << endl ;
	char str[] = " asdf asdf a";
	
	s.replaceSpace(str, 100);
	cout << str << endl;

	//3
	cout << endl << "第3个测试实例" << endl ;
	int count = 5;
	while (count)
	{
		s.push(count);
		count--;
	}

	count = 5;
	while (count)
	{
		cout << s.pop() << endl;
		count--;
	}
	
	//4
	cout << endl << "第4个测试实例" << endl ;
	vector<int> v = { };
	cout << s.minNumberInRotateArray(v)<<endl;


	//5
	cout << endl << "第5个测试实例" << endl;
	cout << s.Fibonacci1(5)<<endl;
	cout << s.Fibonacci(5) << endl;


	//6
	cout << endl << "第6个测试实例" << endl ;
	vector<int> arr;
	for (int i=0;i<6;i++)
	{
		arr.push_back(i);
	}
	s.reOrderArray(arr);

	for (int i = 0; i < 6; i++)
	{
		cout << arr[i];
	}
	cout << endl;

	//7
	cout << endl << "第7个测试实例" << endl;
	ListNode *node1 = new ListNode(1);
	node1->next = new struct ListNode(3);
	node1->next->next = new struct ListNode(5);
	node1->next->next->next = NULL;
	ListNode *node2 = new ListNode(2);
	node2->next = new struct ListNode(4);
	node2->next->next = new struct ListNode(6);
	node2->next->next->next = NULL;
	ListNode* result= s.Merge2(node1, node2);
	while (result!=NULL)
	{
		cout << result->val << "\t";
		result = result->next;
	}
	
	//8
	cout << endl << "第8个测试实例" << endl;
	s.stack_push(3); cout << s.stack_min()<<endl;
	s.stack_push(4); cout << s.stack_min() << endl;
	s.stack_push(2); cout << s.stack_min() << endl;
	s.stack_push(1); cout << s.stack_min() << endl;
	s.stack_pop(); cout << s.stack_min() << endl;
	s.stack_pop(); cout << s.stack_min() << endl;
	s.stack_push(0); cout << s.stack_min() << endl;

	

	//9
	/*
	cout << endl << "第9个测试实例" << endl;
	FILE* file;
	freopen_s(&file, "data2.txt", "w", stdout);
	for (long i = 100000; i > 0; i--)
	{
		printf("%d\n", i);
	}
	
	//for (long i = 1; i <= 100000; i++)
	//{
	//	printf("%d\n", i);
	//}
	fclose(file);
	s.bitSort("data2.txt", 100000);
	*/
	//10
	cout << endl << "第10个测试实例" << endl;

	vector<vector<int>> a1 = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	vector<int> result1 = s.printMatrix(a1);
	for (size_t i=0;i<result1.size();i++)
	{
		cout << result1[i] << endl;
	}

	vector<vector<int>> a2 = { { 1,2,3,4,5 } };
	vector<int> result2 = s.printMatrix(a2);
	for (size_t i = 0; i < result2.size(); i++)
	{
		cout << result2[i] << endl;
	}


	//11
	cout << endl << "第11个测试实例" << endl;
	cout << "输入数据为：4,5,1,6,2，7,3,8" << endl;
	vector<int> arr11 = { 4,5,1,6,2,7,3,8 };
	vector<int> result11 = s.GetLeastNumbers_Solution(arr11,8);
	for (size_t i=0;i<result11.size();i++)
	{
		cout << result11[i] << endl;
	}
	
	//12
	cout << endl << "第12个测试实例" << endl;
	string a12 = "aaa";
	vector<string> str12 = s.Permutation(a12);
	;;

	//13
	cout << endl << "第13个测试实例" << endl;
	s.printSuShu();


	//14
	cout << endl << "第14个测试实例" << endl;
	vector<int> data14 = { 1,2,4,7,9,3,7,89,0,6,4,45,2,5235,564,235,35,235,65 };
	cout << s.findSecondMax(data14);

	//15
	cout << endl << "第15个测试实例" << endl;
	vector<int> data15 = { 12,16,32,12,16,17,32,23 };
	int num1 = 0, num2 = 0;
	s.FindNumsAppearOnce(data15, &num1, &num2);
	cout << num1 << " " << num2 << endl;

	//16
	cout << endl << "第16个测试实例" << endl;
	vector<int> data16 = { 1,2,4,5,7,10,11,15 };
	//vector<int> result16 = s.FindNumbersWithSum(data16, 15);
	vector<int> result16 = s.FindNumbersWithSum2(data16, 15);
	cout << result16[0] << "," << result16[1] << endl;

	//17
	cout << endl << "第17个测试实例" << endl;
	vector<vector<int>> result17 = s.FindContinuousSequence(9);


	//18
	cout << endl << "第18个测试实例" << endl;
	string str18 = "I am a student.";
	string result18 = s.ReverseSentence(str18) ;
	
	//19
	cout << endl << "第19个测试实例" << endl;
	cout << s.SumN(5)<< endl ;

	//20
	cout << endl << "第20个测试实例" << endl;
	cout << s.StrToInt("123456") << endl;
	cout << s.StrToInt("+2147483647") << endl; 
	cout << s.StrToInt("1a33") << endl; 
	cout << s.StrToInt("-123456") << endl;

	//21
	cout << endl << "第21个测试实例" << endl;
	vector<int> arr21 = { 1,2,3,4};
	vector<int> result21 = s.multiply(arr21);
	for (size_t i=0;i<result21.size();i++)
	{
		cout << result21[i] << endl;
	}

	//22
	cout << endl << "第22个测试实例" << endl;
	char* str22 = "";
	char* pattern22 = ".";
	//cout << s.match(str22, pattern22)<<endl;

	//23
	cout << endl << "第23个测试实例" << endl;
	ListNode *pHead = new ListNode(1);
	ListNode *tmp = pHead;
	ListNode *root = pHead;
	for (int i=0;i<6;i++)
	{
		if (i==3)
		{
			root = tmp;
		}
		tmp->next = new ListNode(i+2);
		tmp = tmp->next;
	}
	tmp->next = root;
	
	tmp = s.EntryNodeOfLoop(pHead);
	cout << tmp->val << endl;

	//24
	cout << endl << "第24个测试实例" << endl;
	ListNode *pHead24 = new ListNode(1);
	ListNode *tmp24 = pHead24;
	
	tmp24->next = new ListNode(2);
	tmp24 = tmp24->next;
	tmp24->next = new ListNode(3);
	tmp24 = tmp24->next;
	tmp24->next = new ListNode(3);
	tmp24 = tmp24->next;
	tmp24->next = new ListNode(4);
	tmp24 = tmp24->next;
	tmp24->next = new ListNode(4);
	tmp24 = tmp24->next;
	tmp24->next = new ListNode(5);
	tmp24 = tmp24->next;
	tmp24->next = new ListNode(6);
	tmp24->next = NULL;
	ListNode *result24 = s.deleteDuplication(pHead24);
	while (result24 != NULL)
	{
		cout << result24->val << endl;
		result24 = result24->next;
	}

	//25
	cout << endl << "第25个测试实例" << endl;
	TreeNode *test25 = new TreeNode(8);
	test25->left = new struct TreeNode(6);
	test25->right = new struct TreeNode(6);
	test25->left->left = new struct TreeNode(5);
	test25->left->right = new struct TreeNode(7);
	test25->right->left = new struct TreeNode(7);
	test25->right->right = new struct TreeNode(5);
	cout<<s.isSymmetrical(test25)<<endl;

	//26
	cout << endl << "第26个测试实例" << endl;
	TreeNode *test26 = new TreeNode(8);
	test26->left = new struct TreeNode(7);
	test26->right = new struct TreeNode(6);
	test26->left->left = new struct TreeNode(5);
	test26->left->right = new struct TreeNode(4);
	test26->right->left = new struct TreeNode(3);
	test26->right->right = new struct TreeNode(2);
	vector<vector<int>> result26 = s.print(test26);
	for (auto i = 0;i<result26.size();i++)
	{
		for (auto j=0;j<result26[i].size();j++)
		{
			cout << result26[i][j]<<endl;
		}
	}

	
	//27
	cout << endl << "第27个测试实例" << endl;
	TreeNode *test27 = new TreeNode(5);
	test27->left = new struct TreeNode(3);
	test27->right = new struct TreeNode(7);
	test27->left->left = new struct TreeNode(2);
	test27->left->right = new struct TreeNode(4);
	test27->right->left = new struct TreeNode(6);
	test27->right->right = new struct TreeNode(8);
	TreeNode* result27 = s.KthNode(test27, 1);
	cout << result27->val << endl;
	
	cout << s.KthNode(test27, 2)->val << endl;
	cout << s.KthNode(test27, 3)->val << endl;
	cout << s.KthNode(test27, 4)->val << endl;
	cout << s.KthNode(test27, 5)->val << endl;
	cout << s.KthNode(test27, 6)->val << endl;
	cout << s.KthNode(test27, 7)->val << endl;
	//cout << s.KthNode(test27, 8)->val << endl;
	
	//28
	cout << endl << "第28个测试实例" << endl;
	cout << s.my_itoa(123456) << endl;
	cout << s.my_itoa(-123456) << endl;
	
	//29
	cout << endl << "第29个测试实例" << endl;
	ListNode *p = new ListNode(2);
	p->next = new ListNode(1);
	Leetcode l;
	ListNode* result29 = l.sortList(p);
	while (result29 != NULL)
	{
		cout << result29->val << endl;
		result29 = result29->next;
	}
	
	//30
	cout << endl << "第30个测试实例" << endl;
	vector<int> test30 = { 1,2,3,4,4,4,4,5,5,6,7,8,9,10,11,12};
	cout << s.binarySearchCount(test30, 4) << endl;


	//31
	cout << endl << "第31个测试实例" << endl;
	vector<int> test31 = { 1,2,3,4,4,4,4,5,5,6,7,8,9,10,11,12 };
	cout<<s.findMostFrequentInArray(test31)<<endl;

	//32
	cout << endl << "第32个测试实例" << endl;
	vector<int> test32 = { 1,2,3,4,4,5,6,7,8,9,10,11,12 };
	cout << s.xor_findDup(test32) << endl;


	system("pause");
	return 1;


	
}