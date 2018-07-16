#include "solution.h"

using namespace std;

solution::solution()
{
}


solution::~solution()
{
}

//实现字符拷贝函数
char *my_memcpy(char *des, const char* src, unsigned int count)
{
	char * result;
	assert(src != NULL);
	assert(des != NULL);

	result = des;

	//如果目的地址小于源地址或者地址不会重叠，采用从低字节向高字节拷贝
	if (des <= src || des >= src + count)
	{
		while (count--)
		{
			*des = *src;
			des++;
			src++;
		}
	}
	//如果源地址大于目的地址且重合，从高地址向低地址拷贝	
	else
	{
		des = des + count - 1;
		src = src + count - 1;
		while (count--)
		{
			*des = *src;
			des--;
			src--;
		}
	}

	return result;
}

char* solution::my_strcpy(char* des, const char *src)
{
	assert(src != NULL);
	assert(des != NULL);

	return my_memcpy(des, src, strlen(src) + 1);
}

//自己实现字符串转int
int solution::my_atoi(char* str)
{
	int flag = 1;
	int result = 0;

	if (str == NULL)
	{
		printf("Invaild input!");
		return -1;
	}
	//去掉空格
	while (*str == ' ')
	{
		str++;
	}
	//确定符号位
	if (*str == '-')
	{
		flag = -1;
	}
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	//将字符串逐个转换成数字
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}

	result = flag * result;

	return result;

}

//自己实现int转字符串
char* solution::my_itoa(int num)
{
	char *result = (char *)malloc(1024 * sizeof(char*));
	memset(result, 0, 1024);
	char str[1024] = {0};
	int flag = 0;
	int tmp;
	int i = 0, j = 0;

	if (num < 0)
	{
		flag = -1;
		num = -num;
	}
	tmp = num;
	while (tmp > 0)
	{
		str[i] = tmp % 10 + '0';
		tmp = tmp / 10;
		++i;
	}
	if (flag < 0)
	{
		str[i] = '-';
		++i;
	}
	str[i] = '\0';
	i--;


	while (i >= 0)
	{
		result[j] = str[i];
		j++;
		i--;
	}
	result[j] = '\0';

	return result;
}

//在排序数组中，找出给定的数字出现的次数
int solution::binarySearchCount(vector<int> arr,int num)
{
	//使用二分查找的思想，找到最先出现的位置和最后出现的位置，然后相减
	int len = arr.size();
	int left = 0, right = len - 1;
	int leftIndex = 0, rightIndex = 1;
	while (left < right)
	{
		int mid = (right - left) / 2 + left;
		if (arr[mid] < num)
		{
			left = mid + 1;
		}
		else if(arr[mid] > num)
		{
			right = mid - 1;
		}
		else
		{
			leftIndex = mid;
			rightIndex = mid;
			while (arr[leftIndex] == num)
			{
				leftIndex--;
			}
			while (arr[rightIndex] == num)
			{
				rightIndex++;
			}
			break;

		}

	}

	return rightIndex - leftIndex - 1;
}

//找出数组中重复出现的次数最多的数
int solution::findMostFrequentInArray(vector<int> array)
{
	int result = 0;
	//使用map映射表
	int size = array.size();

	assert(size != 0);
	map<int, int> m;
	for (int i = 0; i < size; i++)
	{
		if (++m[array[i]] >= m[result])		//利用map的第一个词是关键词，关键词在map中只能出现一次
			result = array[i];

	}

	return result;
}

//在O(n)的时间里找到数组中出现次数超过一半的数
//常规思路：1、暴力解 时间O(n^2);2、先排序，取中间值 时间O(nlogn);3、采用map
//3、每次删除两个不同的数
int solution::findMostApperse(vector<int> arr)
{
	int len = arr.size();
	int count = 0;
	int candidate = 0;

	for (int i=0;i<len;i++)
	{
		if (count == 0)				//如果count==0，重新设置候选者
		{
			candidate = arr[i];		//将候选者设置为数组第一个数值
			count = 1;
		}
		else
		{
			if (candidate == arr[i])	//如果当前数值和候选者数值相同，则count++，否则count--
			{
				count++;
			}
			else
			{
				count--;
			}
		}
	}
	return candidate;
}

//找到数组中唯一的重复的元素，数组中依次存放1至N-1的N个数
//思路：1、数组数据求和相减；2、使用异或的方式
int solution::xor_findDup(vector<int> arr)
{
	int result = arr[0];
	int len = arr.size();

	for (int i=1;i < len;i++)
	{
		result ^= i;		//两个相同的数异或之后为0，不同的数异或之后为1,0^x = x
		result ^= arr[i];
	}

	return result;

}

//找到数组中唯一出现奇数次的数（使用异或的方式）
int solution::findElementWithOddCount(vector<int> arr)
{
	int result = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		result ^= arr[i];
	}

	return result;
}

//一个数组中含有n个元素，其中只有两个出现了奇数次，其他的都出现了偶数次，找出这两个数
void solution::findElement(vector<int> arr)
{
	int s = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		s ^= arr[i];		//假设两个数分别是a,b;则s = a^b; 
	}

	int s1 = s;
	int s2 = s;
	int k = 0;
	while (!(s1 & 0x01))	//找到s第k位第一次为1，之前的都为0，则a、b中一定第k位一个为1，一个为0
	{
		s1 = s1 >> 1;
		k++;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		if ((arr[i] >> k) & 0x01)	//遍历数组，找到第k位为1的求异或，得到第一个数
		{
			s ^= arr[i];
		}
	}

	printf("%d,%d\n", s, s^s2);		//a^(a^b) = b
}

//判定数组中是否有重复元素
bool solution::isArrayRepeat(vector<int> arr)
{
	//int j = arr[0];
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == i + 1)			//如果arr[i] == i+1
			continue;
		if (i > 0)
		{
			if(arr[i] == arr[i-1])		//判断与上一个相等的话返回true
				return true;
		}
		if (arr[i] != i + 1)
		{
			swap(arr[i], arr[arr[i] - 1]);	
			i--;
		}
	}
	return false;
}



//二维数组查找
bool solution::find(int target ,vector<vector<int>> array)
{
	if (array.size() == 0) return false;
	if (array[0].size() == 0) return false;

	int row = array[0].size();
	int columns = array.size();
	int col = 0;

	while (!array.empty() && (row > 0) && (col < columns))
	{
		if (target == array[col][row-1])
		{
			return true;
		}
		else if (target < array[col][row-1])
		{
			row--;
		}
		else
		{
			col++;
		}

	}
	return false;
	
	


}



//请实现一个函数，将一个字符串中的空格替换成“ % 20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We % 20Are % 20Happy。
void solution::replaceSpace(char *str, int lengths) 
{
	if (str == NULL) return;
	if (str <= 0) return;

	int length=0;

	int add_len = 0;
	//计算空格的个数和字符串的长度
	for (int i = 0; str[i] != '\0'; i++) 
	{
		if (str[i] == ' ')
		{
			add_len += 2;
		}
		length += 1;
	}

	//修改之后数组的长度
	add_len += length;
	if (add_len > lengths) return;


	int index = add_len-1;

	for (int i=length-1;i>=0;i--)
	{
		if (str[i] == ' ')
		{
			str[index] = '0'; index -= 1;
			str[index] = '2'; index -= 1;
			str[index] = '%'; index -= 1;
		}
		else
		{
			str[index] = str[i]; index -= 1;
		}
	}
	str[add_len] = '\0';
	
}
void solution::replaceSpace2(char *str, int length) {
	queue<char> s;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			s.push('%');
			s.push('2');
			s.push('0');
		}
		else
		{
			s.push(str[i]);
		}
	}
	int s_size = s.size();
	if (s_size > length)
	{
		return;
	}

	for (int i = 0; i < s_size; i++)
	{
		str[i] = s.front();
		s.pop();
	}
	str[s_size] = '\0';
}


//输入一个链表，从尾到头打印链表每个节点的值

//内存超出限制
vector<int> solution::printListFromTailToHead2(ListNode* head) {
	stack<int> s;
	vector<int> result;

	if (head == NULL)
	{
		result.clear();
		return result;
	}

	while (head->next != NULL)
	{
		s.push(head->val);
	}
	int index = 0;
	while (!s.empty())
	{
		result[index] = s.top();
		s.pop();
		index++;
	}

	return result;
}
//使用递归的思想
void printl(ListNode* head, vector<int> &v)
{
	if (head != NULL)
	{
		if (head->next != NULL)
		{
			printl(head->next,v);
		}
		v.push_back(head->val);
	}
}

vector<int> solution::printListFromTailToHead(ListNode* head)
{
	vector<int> v;
	printl(head, v);
	return v;
}


//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
void solution::push(int node) {
	stack1.push(node);
}

int solution::pop() {
	int pop2;
	if (stack2.empty())				//如果2为空，将1中的元素全部压入2
	{
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		
	}
	
	pop2 = stack2.top();
	stack2.pop();
	return pop2;
}


//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
int solution::minNumberInRotateArray(vector<int> rotateArray) {
	int len = rotateArray.size();
	if (len == 0)
	{
		return 0;
	}

	int indexP = 0;
	int indexQ = len - 1;

	while (indexP != indexQ - 1)
	{
		if (rotateArray[(indexP+indexQ)/2] > rotateArray[indexQ])
		{
			indexP = (indexP + indexQ) / 2;
		}
		else
		{
			indexQ = (indexP + indexQ) / 2;
		}
	}
	return rotateArray[indexQ];
}


//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。

int solution::Fibonacci1(int n) {	//迭代，浪费空间
	int result=0;
	if (n == 0)

	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return Fibonacci1(n - 1) + Fibonacci1(n - 2);
	}
	
	return result;
}
int solution::Fibonacci(int n) {
	int result = 0;
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	int pre2 = 0, pre1 = 1;

	for (int i=2;i <= n;i++)
	{
		result = pre2 + pre1;
		pre2 = pre1;
		pre1 = result;
	}

	return result;
}

//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
int solution::jumpFloor(int number) {
	int result = 0;
	if (number==2)
	{
		return 2;
	}
	else if (number == 1)
	{
		return 1;
	}
	int pre2 = 1, pre1 = 2;

	for (int i=2;i <= number; i++)
	{
		result = pre2 + pre1;
		pre2 = pre1;
		pre1 = result;
	}

	return result;
}
int solution::jumpFloorII(int number) 
{
	int result = 0;
	if (number == 1)
	{
		return 1;
	}
	else if (number == 2)
	{
		return 2;
	}
	else
	{
		return 2 * jumpFloorII(number - 1);
	}
}

//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
int solution::rectCover(int number) {
	int result = 0;
	if (number == 2)
	{
		return 2;
	}
	else if (number == 1)
	{
		return 1;
	}
	int pre2 = 1, pre1 = 2;

	for (int i = 3; i <= number; i++)
	{
		result = pre2 + pre1;
		pre2 = pre1;
		pre1 = result;
	}

	return result;
}

//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
int  solution::NumberOf1(int n) { //把一个整数减1在与这个数做与操作，能够将最右边的一个1变成0，若右边还有0则将0全部变成1
	int count =0;								// 1100 1011,101010 101001

	while (n)
	{
		n &= (n - 1);
		count++;
	}
	return count;
}

//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
double solution::Power(double base, int exponent) {
	double result = base;

	if (base > -0.00000001 && base < 0.00000001)  //base = 0
	{
		return 0;
	}
	if (exponent == 0)
	{
		return 1;
	}
	if (exponent > 0)
	{
		for (int i=1;i < exponent; i++)
		{
			result *= base;
		}

		return result;
	}
	else
	{
		for (int i = 1; i < -exponent; i++)
		{
			result *= base;
		}
		return 1 / result;
	}

}


//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
void solution::reOrderArray(vector<int> &array) 
{
	int len = array.size();
	int count = 0;
	vector<int> arr1 ;
	vector<int> arr2 ;

	for (int i=0;i<len;i++)
	{
		if (array[i]%2 == 1)
		{
			arr1.push_back(array[i]);
			count++;
		}
		else
		{
			arr2.push_back(array[i]);
		}
	}
	array.clear();
	for (int i=0;i<count;i++)
	{
		array.push_back(arr1[i]);
	}
	for (int i=count;i<len;i++)
	{
		array.push_back(arr2[i - count]);
	}
}

void solution::reOrderArray2(vector<int> &array)
{
	vector<int>::iterator begin = array.begin();
	vector<int>::iterator end = array.end()-1;		//注意-1

	while (begin != end)		//使用两个指针的方式分别指向数组的前后两个位置
	{
		while (*begin % 2 == 1 && begin != end)
		{
			begin++;
		}
		while (*end % 2 == 0 && begin != end)
		{
			end--;
		}
		swap(*begin, *end);
	}
}


//输入一个链表，输出该链表中倒数第k个结点。
ListNode* solution::FindKthToTail(ListNode* pListHead, unsigned int k) 
{
	ListNode *pHead = pListHead;
	ListNode *pFound = pListHead;

	if (pListHead == NULL)
	{
		return NULL;
	}

	for (unsigned int i=0;i<k-1;i++)
	{
	}
	{
		if (pHead->next != NULL)
		{
			pHead = pHead->next;
		}
		else
		{
			return NULL;
		}
	}

	while (pHead->next != NULL)
	{
		pHead = pHead->next;
		pFound = pFound->next;
	}

	return pFound;
}

//输入一个链表，反转链表后，输出链表的所有元素。
ListNode* solution::ReverseList(ListNode* pHead) {
	ListNode* pNode = pHead;
	ListNode* pNodeRev = NULL;
	ListNode* pNodePre = NULL;
	ListNode* pNodeNext = NULL;

	while (pNode !=NULL)
	{
		pNodeNext = pNode->next;
		if (pNodeNext == NULL)		//如果下一个节点不存在，则返回反转的链表
		{
			pNodeRev = pNode;
		}

		pNode->next = pNodePre;		
		pNodePre = pNode;
		pNode = pNodeNext;
		
	}
	
	return pNodeRev;




	


}

//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
ListNode* solution::Merge(ListNode* pHead1, ListNode* pHead2)
{
	
	ListNode* newHead = new ListNode(0) ;
	ListNode* result = newHead;
	
	if (pHead1 == NULL)
	{
		return pHead2;
	}
	if (pHead2 == NULL)
	{
		return pHead1;
	}

	while (((pHead1 != NULL) && (pHead2 != NULL)))
	{
		if (pHead1->val <= pHead2->val)
		{
			newHead->val = pHead1->val;			
			newHead = newHead->next = new ListNode(0);						
			pHead1 = pHead1->next;
		}
		else
		{
			newHead->val = pHead2->val;			
			newHead = newHead->next = new ListNode(0);
			pHead2 = pHead2->next;
		}
		

	}


	while (pHead1 != NULL)
	{
		
		newHead->val = pHead1->val;

		pHead1 = pHead1->next;
		if (pHead1 != NULL)
		{
			newHead = newHead->next = new ListNode(0);
		}
	}
	
	
	
	while (pHead2 != NULL)
	{
		
		newHead->val = pHead2->val;

		pHead2 = pHead2->next;
		if (pHead2 != NULL)
		{
			newHead = newHead->next = new ListNode(0);
		}
	}
	
	return result;



}

ListNode* solution::Merge2(ListNode* pHead1, ListNode* pHead2) //使用递归的思想
{
	ListNode *result = new ListNode(0);
	if (pHead1 == NULL)
	{
		return pHead2;
	}
	if (pHead2 == NULL)
	{
		return pHead1;
	}
	if (pHead1->val <= pHead2->val)
	{
		result->val = pHead1->val;
		result->next = Merge2(pHead1->next, pHead2);
	}
	else
	{
		result->val = pHead2->val;
		result->next = Merge2(pHead1, pHead2->next);
	}
	return result;
}

//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
bool DoesTree1HasTree2(TreeNode *pRoot1, TreeNode *pRoot2)
{
	if (pRoot2 == NULL)
	{
		return true;
	}
	if (pRoot1 == NULL)
	{
		return false;
	}
	
	if (pRoot1->val != pRoot2->val)
	{
		return false;
	}

	return (DoesTree1HasTree2(pRoot1->left, pRoot2->left) && DoesTree1HasTree2(pRoot1->right, pRoot2->right));

}

bool solution::HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool result = false;
	if (pRoot1 == NULL || pRoot2 == NULL)
	{
		result = false;
	}
	else
	{
		if (pRoot1->val == pRoot2->val)
		{
			result = DoesTree1HasTree2(pRoot1,pRoot2);
		}
		if (!result)
		{
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		if (!result)
		{
			result = HasSubtree(pRoot1->right, pRoot2);
		}
	}

	return result;
	

}

//操作给定的二叉树，将其变换为源二叉树的镜像。
void solution::Mirror(TreeNode *pRoot) {
	
	if (pRoot == NULL)
	{
		return;
	}
	
	if (pRoot->left == NULL && pRoot->right == NULL)
	{
		return;
	}

	TreeNode *tmp;
	tmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = tmp;

	if (pRoot->left != NULL)
	{
		Mirror(pRoot->left);
	}
	if (pRoot->right != NULL)
	{
		Mirror(pRoot->right);
	}

}

//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。( min push pop要求时间复杂度都为O(1) )
void solution::stack_push(int value) 
{
	if (mainStack.empty())
	{
		mainStack.push(value);
		assistStack.push(value);
		return;
	}

	if (value < assistStack.top())
	{
		assistStack.push(value);
	}
	else
	{
		assistStack.push(assistStack.top());
	}
	mainStack.push(value);
}
void solution::stack_pop() 
{
	mainStack.pop();
	assistStack.pop();
}
int solution::stack_top() 
{
	return mainStack.top();
}
int solution::stack_min() 
{
	return assistStack.top();
}

//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
//例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
//（注意：这两个序列的长度是相等的）
bool solution::IsPopOrder(vector<int> pushV, vector<int> popV) {
	stack<int> mainS;
	if (pushV.size() < 1)
	{
		return false;
	}
	assert(pushV.size() != popV.size());

	int j = 0;
	for (size_t i=0;i< pushV.size();i++)
	{
		if (pushV[i] != popV[j])
		{
			mainS.push(pushV[i]);
		}
		else
		{
			j++;
		}
	}

	for (size_t i=j;i< popV.size();i++)
	{
		if (popV[i] != mainS.top())
		{
			return false;
		}
		mainS.pop();
	}
	
	
	return true;
}

//从上往下打印出二叉树的每个节点，同层节点从左至右打印。
vector<int> solution::PrintFromTopToBottom(TreeNode* root) {
	vector<int> result;
	queue<TreeNode*> q;
	
	
	if (root == NULL)
	{
		return result;
	}

	q.push(root);						//将根节点压入队列中
	TreeNode *node ;
	while (!q.empty())					//判断队列是否为空
	{
		node = q.front();				//取出队列中的头结点
		result.push_back(node->val);	

		if (node->left != NULL)
		{
			q.push(node->left);
		}
		if (node->right != NULL)
		{
			q.push(node->right);
		}

		q.pop();
	}

	return result;


}

//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

bool Verify(vector<int> &sequence,int startIndex,int endIndex)
{
	
	int root = sequence[endIndex - 1];
	int i = 0;
	for (i = startIndex; i < endIndex; i++)				//找到比根节点小的，为左子树部分
	{
		if (sequence[i] > root)
		{
			break;
		}
	}
	for (int j=i; j < endIndex; j++)			//若右子树中存在比root小的，则返回false
	{
		if (sequence[j] < root)
		{
			return false;
		}
	}
	
	if (i>0)									//对于左子树
	{
		if (Verify(sequence, 0, i) == false)
			return false;
		
	}
	if (endIndex - i>0)							//对于右子树
	{
		if (Verify(sequence, i, endIndex) == false)
			return false;
	}
	return true;

}
bool solution::VerifySquenceOfBST(vector<int> sequence) {
	if (sequence.empty())
	{
		return false;
	}

	int len = sequence.size();			
	

	return Verify(sequence, 0, len);



}



//大数据量不重复数据的排序----位排序(10000+数据)
char* solution::bitSort(char *filename, int len)
{
	const int BITSPERWORD = 32;
	const int SHIFT = 5;
	const int MASK = 0x1F;
	char * outfilename = "out.txt";
	int err = 0;

	int *tmp = new int[len/32 +1];		//定义一个含有len位的数组
	//unsigned int tmp[100000] = {0};

	FILE *file_in,*file_out;
	err = freopen_s(&file_in,filename, "r", stdin);		//重定向输入输出到文件
	err = freopen_s(&file_out,outfilename,"w",stdout);
	

	if (file_in != NULL)
	{
		int d;
		while (scanf_s("%d",&d) != EOF)
		{
			//set(d); 
			//一个int占8个字节，一共32位，tmp[d >> SHIFT]表示将大小为d的数据放在 d/32 个字节中
			//(d&MASK) 代表取数据d的低五位 1 << (d&MASK) 将低五位对应的值 的位置置位1
			tmp[d >> SHIFT] |= (1 << (d & MASK));

		}
		fclose(file_in);
	}

	if (file_out != NULL)
	{
		for (int i=0;i<len;i++)
		{
			if ((tmp[i >> SHIFT] & (1 << (i&MASK))) != 0)		//检查相应的位是否为1，为1代表存在该数据，就打印出来
			{
				printf("%d\n", i);
			}
		}
	}
	fclose(file_out);

	return outfilename;

}

//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
//（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
RandomListNode* solution::Clone(RandomListNode* pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	RandomListNode* backup = pHead;
	//思路：在链表元素后面复制该链表，然后将链表拆开
	
	//复制节点
	while (pHead != NULL)
	{
		
		RandomListNode* pClone = new RandomListNode(pHead->label);	//创建新节点
		//复制节点属性
		
		pClone->next = pHead->next;
		pClone->random = NULL;

		pHead->next = pClone;		//将节点下一个节点指向pClone

		pHead = pClone->next;
	}

	//添加random节点
	pHead = backup;
	while (pHead != NULL)
	{
		RandomListNode* pCloned = pHead->next;
		
		if (pHead->random != NULL)
		{
			pCloned->random = pHead->random->next;
		}

		
		pHead = pCloned->next;
	}

	//拆除链表
	pHead = backup;
	RandomListNode *cloneNodeHead = NULL;	//确定复制链表的根节点
	RandomListNode *cloneNode = NULL;	//确定复制链表的节点
	

	if (pHead != NULL)			//找到复制链表的头结点
	{
		cloneNodeHead = cloneNode = pHead->next;
		pHead->next = cloneNode->next;
		pHead = pHead->next;			
	}

	while (pHead != NULL)			//分离出原来的链表
	{
		cloneNode->next = pHead->next;
		cloneNode = cloneNode->next;
		pHead->next = cloneNode->next;
		pHead = pHead->next;
		
	}

	
	return cloneNodeHead;


}


//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，
//如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
//则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
void  printMatrixInCircle(vector<vector<int> > &matrix,int h,int v ,int start,vector<int> &result)
{
	int endx = h - start -1 ;
	int endy = v - start -1 ;

	for (int i=start;i <= endx;i++)
	{
		result.push_back(matrix[start][i]);
	}

	if (start < endy)
	{
		for (int j = start + 1; j <= endy; j++)
		{
			result.push_back(matrix[j][endx]);
		}
	}
	if (start < endy && start < endx)
	{
		for (int i = endx - 1; i >= start; i--)
		{
			result.push_back(matrix[endy][i]);
		}
	}
	
	if (start < endx && start < endy - 1)
	{
		for (int j = endy - 1; j > start; j--)
		{
			result.push_back(matrix[j][start]);
		}
	}
	

}
vector<int> solution::printMatrix(vector<vector<int> > matrix) {
	vector<int> result;
	result.clear();

	int v = matrix.size();			//行 竖直方向
	int h = matrix[0].size();		//列 水平方向
	
	int start = 0;
	if (h<=0 || v<=0 || matrix.empty())
	{
		return result;
	}

	while (h > start*2 && v > start*2)
	{
		printMatrixInCircle(matrix, h, v, start, result);
		start++;
	}

	
	return result;
}

//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

vector<vector<int>> res; //将路径和结果声明为全局变量
vector<int> path;
void find(TreeNode* root, int sum)
{
	if (root == NULL)return;		
	path.push_back(root->val);		//将当前根节点的值压入path
	if (!root->left && !root->right && sum == root->val)		//如果当前节点为叶子节点并且当前根节点的值和剩余的值相同
		res.push_back(path);		//将当前path压入结果数组中
	else				//如果当前节点不是叶子节点，遍历其子节点
	{
		if (root->left)
			find(root->left, sum - root->val);
		if (root->right)
			find(root->right, sum - root->val);
	}
	path.pop_back();	//在返回父节点之前删除压入路径的值
}
vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
	find(root, expectNumber);
	return res;
}

//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,
int Partition_GetLeastNumbers(vector<int> &input,int start,int end)
{
	
	int choosenum = input[start];
	int x = start + 1;
	for (int i=x;i<end;i++)
	{
		if (input[i] < choosenum)
		{
			swap(input[x], input[i]);
			x++;
		}
	}
	x--;
	swap(input[0], input[x]);

	return x;

}
vector<int> solution::GetLeastNumbers_Solution(vector<int> input, int k) {
	vector<int> result;
	if (input.empty() || k<=0 || (unsigned int)k>input.size())
	{
		return result;
	}

	int start = 0;
	int end = input.size()-1;

	int index = Partition_GetLeastNumbers(input, start, end);
	while (k-1 != index)
	{
		if (index > k-1)
		{
			end = index - 1;
			index = Partition_GetLeastNumbers(input, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition_GetLeastNumbers(input, start, end);
		}
	}

	for (int i=0;i<k;i++)
	{
		result.push_back(input[i]);
	}


	return result;


}
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
//1、使用快排先排序
//2、下面的方法
int solution::MoreThanHalfNum_Solution(vector<int> numbers) {
	int val = numbers[0];
	int num = 1;
	int size = numbers.size();

	for (int i=1;i<size;i++)
	{
		if (num == 0)
		{
			val = numbers[i];
			num = 1;
		}
		else if (numbers[i] == val )
		{
			num++;
		}
		else
		{
			num--;
		}
	}


	for (int i=0;i<size;i++)
	{
		if (val == numbers[i])
		{
			num++;
		}
	}
	if (num>=size/2)
	{
		return val;
	}
	else
	{
		return 0;
	}
}


//输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
//输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

void Permutation2(string &str,string::iterator begin, vector<string> &result)
{
	if (begin == str.end())
	{
		result.push_back(str);
	}
	else
	{
		for (string::iterator it = begin ; it != str.end(); it++)
		{
			if (it != begin && *it == *begin)
			{
				continue;
			}
			swap(*begin, *it);
			Permutation2(str, begin + 1, result);
			swap(*begin, *it);
			
			
			
		}
	}
	
	
}
vector<string> solution::Permutation(string str) {
	vector<string> result;
	if (str.empty())
	{
		return result;
	}
	string::iterator it = str.begin();
	Permutation2(str,it,result);

	sort(result.begin(), result.end());

	return result;
}


//HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,
//当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
//例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。你会不会被他忽悠住？(子向量的长度至少是1)
int solution::FindGreatestSumOfSubArray(vector<int> array) {
	int sum = array[0];
	int tmpsum = array[0];

	for (size_t i=1;i<array.size();i++)
	{
		if (tmpsum <= 0)		//如果数组在第i个数相加后小于0，则抛弃之前的数组
		{
			tmpsum = array[i];
		}
		else
		{
			tmpsum += array[i];
		}
		if (tmpsum > sum)
		{
			sum = tmpsum;
		}
		
	}

	return sum;
}

//求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
//ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。
int NumberOf1Between1AndN_Solution(int n)
{
	return 0;
}








//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
//使用中序遍历法遍历二叉树，得到的就是排序的
//还没做出来

void convertNode(TreeNode *root) 
{
	if (root->left != NULL)
	{
		TreeNode* rootLeft = root->left;	//保存左节点
		while (rootLeft->right != NULL)
		{
			rootLeft = rootLeft->right;		//找到最大右子树
		}
		rootLeft->right = root;				//连接
		root->left = rootLeft;

		convertNode(root->left);
	}
	
	if (root->right != NULL)
	{
		TreeNode* rootRight = root->right;
		while (rootRight->left != NULL)
		{
			rootRight = rootRight->left;	//找到最小左子树
		}
		rootRight->left = root;
		root->right = rootRight;
		convertNode(root->right);

	}
}
TreeNode* solution::Convert(TreeNode* pRootOfTree)
{
	TreeNode *root = pRootOfTree;
	if (pRootOfTree == NULL)
	{
		return NULL;
	}
	//找到最小的节点作为链表的头结点
	TreeNode* listHead = NULL;
	while (root->left != NULL)
	{
		root = root->left;
	}
	listHead = root;

	convertNode(pRootOfTree);
	
	return listHead;


}



//打印从1--1000内的所有的素数
void solution::printSuShu()
{
	bool flag = true;
	//能被2整除的肯定不是素数,去掉一半数据量
	for (int i=1;i<=100;i+=2)
	{
		//判断能否被 3--2/i 之间的数据整除，去掉一半的数据量
		for (int j=3;j<i/2;j++)
		{
			if ( i % j == 0)
			{
				flag = false;
			}
			
		}

		if (flag == true)
		{
			cout << i << endl;
		}
		flag = true;

	}
}

//求出数组中第二大的值
//思想就是：循环遍历一次数组，设置两个变量来保存max和second，如果第i个数据大于max，更新max和second，如果只大于second，则更新second
int solution::findSecondMax(vector<int> &data)
{
	int max = data[0];
	int second = data[0];

	int len = data.size();

	for (int i=0;i<len;i++)
	{
		//data[i] > max
		if (data[i] > max)
		{
			second = max;
			max = data[i];
		}
		else
		{
			if (data[i] > second)
			{
				second = data[i];
			}
		}
	}

	return second;
}

//求树的最长路径
int TreeDepth(TreeNode *pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	int nLeft = TreeDepth(pRoot->left);
	int nRight = TreeDepth(pRoot->right);

	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}



//一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字
unsigned int findIndexOfLast1(int num)
{
	unsigned int indexNum = 0;
	unsigned int indexBit = 1;
	int tmp = num;
	while ((tmp & indexBit) == 0)
	{
		tmp = num;
		indexBit  = indexBit << 1;
		indexNum++;
	}
	return indexNum;

}

bool isBit1(int num, unsigned int index)
{
	unsigned int tmp = 1 << index;
	if ((tmp & num) == tmp)
		return true;
	else
		return false;

}

void solution::FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
	int len = data.size();
	if (data.empty() || len < 2)
		return;
	int resultOr = 0;
	//所有值求异或的结果
	for (int i = 0; i < len; i++)
	{
		resultOr ^= data[i];
	}
	//求出异或结果的最后一个1所在的位置
	unsigned int lastIndexOf1 = findIndexOfLast1(resultOr);

	*num1 = *num2 = 0;
	for (int j = 0; j < len; j++)
	{
		if (isBit1(data[j], lastIndexOf1))
		{
			*num1 ^= data[j];
		}
		else
		{
			*num2 ^= data[j];
		}
	}


}

//输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
vector<int> solution::FindNumbersWithSum(vector<int> array, int sum)
{
	vector<int> tmp;
	tmp.clear();
	int len = array.size();
	int* p1 = &array[0];
	int* p2 = &array[len-1];
	
	if (len < 2)
	{
		return tmp;
	}

	while (p1 != p2)
	{
		if ((*p1 + *p2) > sum)
		{
			p2--;
		}
		else if ((*p1 + *p2 < sum))
		{
			p1++;
		}
		else
		{
			
			tmp.push_back(*p1);
			tmp.push_back(*p2);
			return tmp;
		}
	}
	
	return tmp;


}

vector<int> solution::FindNumbersWithSum2(vector<int> array, int sum)
{
	unordered_map<int,int> m;		//使用hashmap之后时间复杂度降低到O(n)，会占用更多空间
	vector<int> result;

	for (auto i=0;i < array.size();i++)
	{
		int value = sum - array[i];		//找到当前对应的值

		if (m.find(value) != m.end())	//如果找到了则保存下来
		{
			//保存两个数
			result.push_back(value);
			result.push_back(sum - value);

			//保存两个数的标号
			//result.push_back(m[value]);
			//result.push_back(i + 1);
			
		}

		m[array[i]] = i + 1;			//如果不存在则保存当前数和它的标号
	}
	return result;


}

//输出和为s的连续正数序列。序列内按照从小到大的顺序，序列间按照从小到大的顺序
vector<vector<int>> solution::FindContinuousSequence(int sum)
{
	vector<vector<int>> result;
	int small = 1;
	int big = 2;
	int tmp;

	if (sum < 3)
	{
		result.clear();
		return result;
	}

	while (small < big && big < sum)
	{
		tmp = (small + big) * (big - small + 1) / 2;
		if ( tmp < sum)
		{
			big++;
		}
		else if (tmp == sum)
		{
			vector<int> serial;
			for (int i = small; i <= big; i++)
			{
				serial.push_back(i);
			}
			result.push_back(serial);
			serial.clear();	
			big++;
		}
		else
		{
			small++;
		}
	}
	return result;
	
}

//循环左移字符串s
string solution::LeftRotateString(string str, int n)
{
	int len = str.length();
	if (len == 0) 
	{
		return "";
	}

	n = n% len;
	str += str;
	return str.substr(n,len);

}



//翻转单词顺序，如"I am a student."输出"student. a am I"
void ReverseWord(string &str,int start,int end)
{
	while (start < end)
	{
		swap(str[start], str[end]);
		end--;
		start++;
	}
}
string solution::ReverseSentence(string str)
{
	//首先翻转整个句子
	int len = str.size();
	ReverseWord(str, 0, len - 1);
	int start = 0, end = 0;
	int count = 0;
	while (count < len)
	{
		//如果开头有空格，则跳过
		while (count < len && str[count] == ' ')
		{
			count++;
		}
		start = count;

		//找到末尾
		while (count < len && str[count] != ' ')
		{
			count++;
		}
		end = count;

		//翻转局部单词
		ReverseWord(str, start, end - 1);
	}
	return str;
}


string solution::LeftRotateString2(string str, int n)
{
	//首先翻转全句子
	ReverseWord(str, 0, str.size()-1);
	n = str.size() - n;
	//分别翻转两段
	ReverseWord(str, 0, n - 1);
	ReverseWord(str, n, str.size() - 1);


	return str;



}

//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句
//1、参见剑指offer中使用构造函数
//2、使用短路原理
int solution::SumN(int n)
{
	int sum = n;
	
	n > 0 && (sum += SumN(n - 1));

	return sum;
}

//不用四则远算符号求两个整数之和
int solution::Add(int num1, int num2)
{
	int tmp;
	while (num1 !=0)
	{
		tmp = num2;	//先将num2保存一下  假设5（101） + 7（111）
		num2 = num1 ^ num2;		//异或求不进位的值 （010）
		num1 = (num1 & tmp) << 1;	//求进位的值（1010）
	}

	return num2;
	
}


//输入一个字符串，如果是合法的数值表达则返回该数字，否则返回0
int solution::StrToInt(string str)
{
	int flag = 0;
	int count = 0;
	int result = 0;

	if (str.empty())
	{
		return 0;
	}

	if (str[0] == '-')		//判断第一位是否有‘+’  ‘-’符号
	{
		flag = 0;
		count = 1;
	}
	else if (str[0] == '+')
	{
		flag = 1;
		count = 1;
	}
	else
	{
		flag = 1;
		count = 0;
	}

	int len = str.length();
	for (int i = count;i<len;i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = 10 * result + str[i]- '0';
		}
		else
		{
			return 0;
		}
	}

	if (flag == 0)
	{
		result = 0 - result;
	}
	return result;
}


//给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
//不能使用除法。
vector<int>  solution::multiply(const vector<int > &A)
{

	int len = A.size();
	vector<int> B(len,1);
	
	if (len != 0)
	{
		B[0] = 1;

		//计算下三角形连乘
		for (int i = 1; i < len; i++)
		{
			B[i] = B[i - 1] * A[i - 1];
		}

		//计算上三角形连乘
		int tmp = 1;
		for (int i = len - 1; i > 0; i--)
		{
			tmp *= A[i];
			B[i - 1] *= tmp;
		}
	}
	return B;
}

//一个链表中包含环，求环的入口地址
ListNode* solution::EntryNodeOfLoop(ListNode *pHead)
{
	int LoopCount = 0;
	if (pHead == NULL)
	{
		return NULL;
	}
	ListNode *pSlow = pHead;
	
	ListNode *pFast = pSlow->next;
	if (pFast == NULL)
	{
		return NULL;
	}
	

	//找到快慢指针的交点，其交点必然在环中
	while (pFast != pSlow)
	{
		if (pFast->next == NULL)
		{
			return NULL;		//如果有空节点，说明链表不存在环，返回NULL
		}
		if (pFast->next->next == NULL)
		{
			return NULL;		//如果有空节点，说明链表不存在环，返回NULL
		}

		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}

	//慢指针继续转，快指针不动
	pSlow = pSlow->next;
	LoopCount = 1;
	//找到环的节点数
	while (pFast != pSlow)
	{
		pSlow = pSlow->next;
		LoopCount++;
	}
	//将快慢指针都指向pHead
	pFast = pHead;
	pSlow = pHead;

	//将快指针的起始节点增加LoopCount,慢指针从pHead开始走
	while (LoopCount != 0)
	{
		pFast = pFast->next;
		LoopCount--;
	}

	while (pFast != pSlow)
	{
		pFast = pFast->next;
		pSlow = pSlow->next;
	}

	return pSlow;

}


//在一个排序的链表中删除列表中重复的节点，重复的不保留。如1-2-3-3-4-4-5处理过后1-2-5
ListNode* solution::deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		return pHead;
	}
	if (pHead->val == pHead->next->val)		//如果当前节点是重复节点
	{
		ListNode *pNode = pHead->next;
		while (pNode != NULL && pNode->val == pHead->val)
		{
			pNode = pNode->next;		//跳过与当前节点相同的节点
		}

		return deleteDuplication(pNode);				//不保留当前节点，从当前节点开始递归


	}
	else
	{
		pHead->next = deleteDuplication(pHead->next);	//保留当前节点，从下个节点开始递归
		return pHead;
	}
}

//给定一个二叉树和一个节点，请找出中序遍历顺序下的下一个节点并返回，该树种包含指向左右节点和父节点的指针
TreeLinkNode* solution::GetNext(TreeLinkNode* pNode)
{
	if (pNode == NULL)				//如果节点为空节点，则返回空
	{
		return NULL;
	}

	if (pNode->right != NULL)		//如果节点的右节点存在,则找到右节点的最左的左节点
	{
		pNode = pNode->right;
		while (pNode->left != NULL)
		{
			pNode = pNode->left;
		}
		return pNode;
			
	}
	
	while (pNode->next != NULL)		//父节点不为空
	{
		if (pNode->next->left == pNode)	//该节点是父节点的左子树节点
		{
			return pNode->next;
		}
		else
		{
			pNode = pNode->next;		//如果该节点是父节点的右子树节点，则遍历判断父节点的父节点
		}
	}

	return NULL;
	
	
	

}








//请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
//在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
//没做出来
bool solution::match(char * str, char * pattern)
{
	int strlength = strlen(str);
	int patlength = strlen(pattern);
	char pre = '*';	//用来存储上一个字符
	char next = '*';	//用来存储下一个字符

	if (strlength== 0 && patlength ==0)
	{
		return true;
	}
	else if (strlength != 0 && patlength == 0)
	{
		return false;
	}
	else if (strlength == 0)
	{
		;
	}
	else
	{
		while (*str != '\0')
		{
			if (*pattern == '.')	//如果是'.'忽略本次的比较
			{
				pattern++;
				str++;
			}
			else if (*pattern == '*')
			{
				next = *(++pattern);	//保存下一个字符
				pattern--;
				if (pre == *str)	//如果和上一个字符相同
				{
					str++;
				}
				else if (next == *str)
				{
					str++;
					pattern++;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (*str == *pattern)
				{
					pre = *pattern;		//储存上一个字符
					str++;
					pattern++;
					
				}
				else
				{
					if (*(++pattern) == '*')
					{
						if (*str == *(++pattern))
						{
							str++;
							pattern++;
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}


					
				}
			
			}
		}

		return true;
	}
	return false;
}


//求两个字符串的最长的公共子串，并输出其长度
int solution::findMaxSubString(string str1, string str2,string &result)
{
	//构建一个二维数组，对应的[i][j]点相等，则将该点设置为1，最后统计对角线最大的连续1的个数
	int len1 = str1.length();
	int len2 = str2.length();
	vector<vector<int>> arr(len1, vector<int>(len2));//定义一个二维数组
	

	for (int i=0;i<len1;i++)			////如果两个位置的元素相等，矩阵值为1,否则为0
	{
		for (int j =0;j<len2;j++)
		{
			if (str1[i] == str2[j])
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = 0;
			}
		}
	}

	int MaxLen = 0;
	for (int i = 0; i < len1; i++)			//判断对角线上最大连续1的个数
	{		
		for (int j=0;j<len2;j++)
		{
			int m = i;						//判断从[i][j]点开始，对角线上连续的有多少个
			int n = j;

			int tmplen = 0;
			while (arr[m++][n++] == 1)
				tmplen++;

			if (MaxLen<tmplen)
			{
				MaxLen = tmplen;
				result.clear();
				for (int i = 0; i < tmplen; i++)
				{
					result.push_back(arr[i + tmplen][j + tmplen]);
				}
				
			}
		}
	}

	return MaxLen;
}

//判断一颗二叉树是否对称
bool comRoot(TreeNode* left, TreeNode* right)
{
	if (left == NULL && right == NULL)		//如果都为空，则返回true
	{
		return true;
	}
	else if (left != NULL && right != NULL )//如果都不为空
	{
		if (left->val != right->val)		//判断两个节点是否相等
		{
			return false;
		}
		else								//如果相等，判断左节点的左子节点和右节点的右子节点以及 左节点的右子节点和右节点的左子节点是否分别相等
		{
			return comRoot(left->left, right->right) && comRoot(left->right, right->left);
		}
	}
	else									//如果有一个为空，一个不为空，返回false
	{
		return false;
	}
	
}
bool solution::isSymmetrical(TreeNode* pRoot)
{
	if (pRoot == NULL)    return true;
	
	return comRoot(pRoot->left, pRoot->right);	//比较左节点和右节点
}

//按之字打印二叉树
vector<vector<int>>  solution::print(TreeNode* pRoot)
{
	vector<vector<int>> result;
	bool direction = false;
	if (pRoot == NULL)
	{
		result.clear();
		return result;
	}
	queue<TreeNode*> que;
	que.push(pRoot);		//将头结点放入队列
	while (!que.empty())
	{
		vector<int> vec;
		const int size = que.size();
		for (int i=0;i<size;i++)	//每一次将当前size队列的数据都处理完毕
		{
			TreeNode *tmp = que.front();
			que.pop();
			vec.push_back(tmp->val);


			if (tmp->left != NULL)
			{
				que.push(tmp->left);
			}
			if (tmp->right != NULL)
			{
				que.push(tmp->right);
			}

		}
		if (direction == true)				//如果direction == true则将数组中的数逆序排列，每一次到下一层direction换向
		{
			direction = false;
			reverse(vec.begin(),vec.end());
		}
		else
		{
			direction = true;
		}
		
		result.push_back(vec);
	
	}
	return result;
}


//给定一个二叉搜索树，找出其中第k小的节点
//时间复杂度较高
void KthNodeInorder(TreeNode* pRoot, int k,vector<TreeNode*> &result)
{
	if (pRoot == NULL || k <= 0)
	{
		return;
	}

	KthNodeInorder(pRoot->left, k, result);
	result.push_back(pRoot);
	KthNodeInorder(pRoot->right, k, result);

}

TreeNode* solution::KthNode(TreeNode* pRoot, int k)
{
	

	vector<TreeNode*> result;

	KthNodeInorder(pRoot,k, result);

	if (k>result.size())
	{
		return NULL;
	}
	
	return result[k-1];


}
int index = 0;
TreeNode* solution::KthNode2(TreeNode* pRoot, int k)	//如果没有搜索到返回NULL，如果输出不为空，则为结果值
{
	if (pRoot!=NULL)		//中序遍历
	{
		TreeNode *node = KthNode2(pRoot->left, k);
		if (node != NULL)
		{
			return node;
		}
		index++;	//计数器
		if (index == k)
		{
			return pRoot;
		}
		node = KthNode2(pRoot->right, k);
		if (node != NULL)
		{
			return node;
		}
	}
	return NULL;

}

//判断二叉树是否为平衡二叉树
//平衡二叉树的概念是空树或者左右子树的高度差不大于1

//1、判断左右子树的深度










//二分查找法：循环和递归
int solution::binarySearch1(vector<int> &data,int k)
{	
	int len = data.size();
	int index = 0;

	while (index < len)
	{
		int middle = ((len - index) >> 2) + index;
		if (data[middle] > k)
		{
			len = middle - 1;
		}
		else if(data[middle] < k)
		{
			index = middle + 1;
		}
		else
		{
			return middle;
		}
	}
	return -1;
}

//递归法
int static __binarySearch(vector<int> &data, int k, int begin, int end)
{
	int middle = ((end - begin) >> 2) + begin;
	if (data[middle] > k)
	{
		end = middle - 1;
	}
	else if (data[middle] < k)
	{
		begin = middle + 1;
	}
	else
	{
		return middle;
	}

	return __binarySearch(data, k, begin, end);
}

int solution::binarySearch2(vector<int> &data, int k)
{
	int len = data.size();
	return __binarySearch(data, k, 0, len);
}













