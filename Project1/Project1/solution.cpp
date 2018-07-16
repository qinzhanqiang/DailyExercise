#include "solution.h"

using namespace std;

solution::solution()
{
}


solution::~solution()
{
}

//ʵ���ַ���������
char *my_memcpy(char *des, const char* src, unsigned int count)
{
	char * result;
	assert(src != NULL);
	assert(des != NULL);

	result = des;

	//���Ŀ�ĵ�ַС��Դ��ַ���ߵ�ַ�����ص������ôӵ��ֽ�����ֽڿ���
	if (des <= src || des >= src + count)
	{
		while (count--)
		{
			*des = *src;
			des++;
			src++;
		}
	}
	//���Դ��ַ����Ŀ�ĵ�ַ���غϣ��Ӹߵ�ַ��͵�ַ����	
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

//�Լ�ʵ���ַ���תint
int solution::my_atoi(char* str)
{
	int flag = 1;
	int result = 0;

	if (str == NULL)
	{
		printf("Invaild input!");
		return -1;
	}
	//ȥ���ո�
	while (*str == ' ')
	{
		str++;
	}
	//ȷ������λ
	if (*str == '-')
	{
		flag = -1;
	}
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	//���ַ������ת��������
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}

	result = flag * result;

	return result;

}

//�Լ�ʵ��intת�ַ���
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

//�����������У��ҳ����������ֳ��ֵĴ���
int solution::binarySearchCount(vector<int> arr,int num)
{
	//ʹ�ö��ֲ��ҵ�˼�룬�ҵ����ȳ��ֵ�λ�ú������ֵ�λ�ã�Ȼ�����
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

//�ҳ��������ظ����ֵĴ���������
int solution::findMostFrequentInArray(vector<int> array)
{
	int result = 0;
	//ʹ��mapӳ���
	int size = array.size();

	assert(size != 0);
	map<int, int> m;
	for (int i = 0; i < size; i++)
	{
		if (++m[array[i]] >= m[result])		//����map�ĵ�һ�����ǹؼ��ʣ��ؼ�����map��ֻ�ܳ���һ��
			result = array[i];

	}

	return result;
}

//��O(n)��ʱ�����ҵ������г��ִ�������һ�����
//����˼·��1�������� ʱ��O(n^2);2��������ȡ�м�ֵ ʱ��O(nlogn);3������map
//3��ÿ��ɾ��������ͬ����
int solution::findMostApperse(vector<int> arr)
{
	int len = arr.size();
	int count = 0;
	int candidate = 0;

	for (int i=0;i<len;i++)
	{
		if (count == 0)				//���count==0���������ú�ѡ��
		{
			candidate = arr[i];		//����ѡ������Ϊ�����һ����ֵ
			count = 1;
		}
		else
		{
			if (candidate == arr[i])	//�����ǰ��ֵ�ͺ�ѡ����ֵ��ͬ����count++������count--
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

//�ҵ�������Ψһ���ظ���Ԫ�أ����������δ��1��N-1��N����
//˼·��1������������������2��ʹ�����ķ�ʽ
int solution::xor_findDup(vector<int> arr)
{
	int result = arr[0];
	int len = arr.size();

	for (int i=1;i < len;i++)
	{
		result ^= i;		//������ͬ�������֮��Ϊ0����ͬ�������֮��Ϊ1,0^x = x
		result ^= arr[i];
	}

	return result;

}

//�ҵ�������Ψһ���������ε�����ʹ�����ķ�ʽ��
int solution::findElementWithOddCount(vector<int> arr)
{
	int result = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		result ^= arr[i];
	}

	return result;
}

//һ�������к���n��Ԫ�أ�����ֻ�����������������Σ������Ķ�������ż���Σ��ҳ���������
void solution::findElement(vector<int> arr)
{
	int s = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		s ^= arr[i];		//�����������ֱ���a,b;��s = a^b; 
	}

	int s1 = s;
	int s2 = s;
	int k = 0;
	while (!(s1 & 0x01))	//�ҵ�s��kλ��һ��Ϊ1��֮ǰ�Ķ�Ϊ0����a��b��һ����kλһ��Ϊ1��һ��Ϊ0
	{
		s1 = s1 >> 1;
		k++;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		if ((arr[i] >> k) & 0x01)	//�������飬�ҵ���kλΪ1������򣬵õ���һ����
		{
			s ^= arr[i];
		}
	}

	printf("%d,%d\n", s, s^s2);		//a^(a^b) = b
}

//�ж��������Ƿ����ظ�Ԫ��
bool solution::isArrayRepeat(vector<int> arr)
{
	//int j = arr[0];
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == i + 1)			//���arr[i] == i+1
			continue;
		if (i > 0)
		{
			if(arr[i] == arr[i-1])		//�ж�����һ����ȵĻ�����true
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



//��ά�������
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



//��ʵ��һ����������һ���ַ����еĿո��滻�ɡ� % 20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe % 20Are % 20Happy��
void solution::replaceSpace(char *str, int lengths) 
{
	if (str == NULL) return;
	if (str <= 0) return;

	int length=0;

	int add_len = 0;
	//����ո�ĸ������ַ����ĳ���
	for (int i = 0; str[i] != '\0'; i++) 
	{
		if (str[i] == ' ')
		{
			add_len += 2;
		}
		length += 1;
	}

	//�޸�֮������ĳ���
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


//����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ

//�ڴ泬������
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
//ʹ�õݹ��˼��
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


//������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
void solution::push(int node) {
	stack1.push(node);
}

int solution::pop() {
	int pop2;
	if (stack2.empty())				//���2Ϊ�գ���1�е�Ԫ��ȫ��ѹ��2
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


//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� ����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء� 
//��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
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


//��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�

int solution::Fibonacci1(int n) {	//�������˷ѿռ�
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

//һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
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

//���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
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

//����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
int  solution::NumberOf1(int n) { //��һ��������1�������������������ܹ������ұߵ�һ��1���0�����ұ߻���0��0ȫ�����1
	int count =0;								// 1100 1011,101010 101001

	while (n)
	{
		n &= (n - 1);
		count++;
	}
	return count;
}

//����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
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


//����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
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
	vector<int>::iterator end = array.end()-1;		//ע��-1

	while (begin != end)		//ʹ������ָ��ķ�ʽ�ֱ�ָ�������ǰ������λ��
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


//����һ����������������е�����k����㡣
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

//����һ��������ת�����������������Ԫ�ء�
ListNode* solution::ReverseList(ListNode* pHead) {
	ListNode* pNode = pHead;
	ListNode* pNodeRev = NULL;
	ListNode* pNodePre = NULL;
	ListNode* pNodeNext = NULL;

	while (pNode !=NULL)
	{
		pNodeNext = pNode->next;
		if (pNodeNext == NULL)		//�����һ���ڵ㲻���ڣ��򷵻ط�ת������
		{
			pNodeRev = pNode;
		}

		pNode->next = pNodePre;		
		pNodePre = pNode;
		pNode = pNodeNext;
		
	}
	
	return pNodeRev;




	


}

//���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
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

ListNode* solution::Merge2(ListNode* pHead1, ListNode* pHead2) //ʹ�õݹ��˼��
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

//�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
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

//���������Ķ�����������任ΪԴ�������ľ���
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

//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������( min push popҪ��ʱ�临�Ӷȶ�ΪO(1) )
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

//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�
//��������1,2,3,4,5��ĳջ��ѹ��˳������4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
//��ע�⣺���������еĳ�������ȵģ�
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

//�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
vector<int> solution::PrintFromTopToBottom(TreeNode* root) {
	vector<int> result;
	queue<TreeNode*> q;
	
	
	if (root == NULL)
	{
		return result;
	}

	q.push(root);						//�����ڵ�ѹ�������
	TreeNode *node ;
	while (!q.empty())					//�ж϶����Ƿ�Ϊ��
	{
		node = q.front();				//ȡ�������е�ͷ���
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

//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No���������������������������ֶ�������ͬ��

bool Verify(vector<int> &sequence,int startIndex,int endIndex)
{
	
	int root = sequence[endIndex - 1];
	int i = 0;
	for (i = startIndex; i < endIndex; i++)				//�ҵ��ȸ��ڵ�С�ģ�Ϊ����������
	{
		if (sequence[i] > root)
		{
			break;
		}
	}
	for (int j=i; j < endIndex; j++)			//���������д��ڱ�rootС�ģ��򷵻�false
	{
		if (sequence[j] < root)
		{
			return false;
		}
	}
	
	if (i>0)									//����������
	{
		if (Verify(sequence, 0, i) == false)
			return false;
		
	}
	if (endIndex - i>0)							//����������
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



//�����������ظ����ݵ�����----λ����(10000+����)
char* solution::bitSort(char *filename, int len)
{
	const int BITSPERWORD = 32;
	const int SHIFT = 5;
	const int MASK = 0x1F;
	char * outfilename = "out.txt";
	int err = 0;

	int *tmp = new int[len/32 +1];		//����һ������lenλ������
	//unsigned int tmp[100000] = {0};

	FILE *file_in,*file_out;
	err = freopen_s(&file_in,filename, "r", stdin);		//�ض�������������ļ�
	err = freopen_s(&file_out,outfilename,"w",stdout);
	

	if (file_in != NULL)
	{
		int d;
		while (scanf_s("%d",&d) != EOF)
		{
			//set(d); 
			//һ��intռ8���ֽڣ�һ��32λ��tmp[d >> SHIFT]��ʾ����СΪd�����ݷ��� d/32 ���ֽ���
			//(d&MASK) ����ȡ����d�ĵ���λ 1 << (d&MASK) ������λ��Ӧ��ֵ ��λ����λ1
			tmp[d >> SHIFT] |= (1 << (d & MASK));

		}
		fclose(file_in);
	}

	if (file_out != NULL)
	{
		for (int i=0;i<len;i++)
		{
			if ((tmp[i >> SHIFT] & (1 << (i&MASK))) != 0)		//�����Ӧ��λ�Ƿ�Ϊ1��Ϊ1������ڸ����ݣ��ʹ�ӡ����
			{
				printf("%d\n", i);
			}
		}
	}
	fclose(file_out);

	return outfilename;

}

//����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��
//��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
RandomListNode* solution::Clone(RandomListNode* pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	RandomListNode* backup = pHead;
	//˼·��������Ԫ�غ��渴�Ƹ�����Ȼ�������
	
	//���ƽڵ�
	while (pHead != NULL)
	{
		
		RandomListNode* pClone = new RandomListNode(pHead->label);	//�����½ڵ�
		//���ƽڵ�����
		
		pClone->next = pHead->next;
		pClone->random = NULL;

		pHead->next = pClone;		//���ڵ���һ���ڵ�ָ��pClone

		pHead = pClone->next;
	}

	//���random�ڵ�
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

	//�������
	pHead = backup;
	RandomListNode *cloneNodeHead = NULL;	//ȷ����������ĸ��ڵ�
	RandomListNode *cloneNode = NULL;	//ȷ����������Ľڵ�
	

	if (pHead != NULL)			//�ҵ����������ͷ���
	{
		cloneNodeHead = cloneNode = pHead->next;
		pHead->next = cloneNode->next;
		pHead = pHead->next;			
	}

	while (pHead != NULL)			//�����ԭ��������
	{
		cloneNode->next = pHead->next;
		cloneNode = cloneNode->next;
		pHead->next = cloneNode->next;
		pHead = pHead->next;
		
	}

	
	return cloneNodeHead;


}


//����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬
//����������¾��� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
//�����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
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

	int v = matrix.size();			//�� ��ֱ����
	int h = matrix[0].size();		//�� ˮƽ����
	
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

//����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
//·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����

vector<vector<int>> res; //��·���ͽ������Ϊȫ�ֱ���
vector<int> path;
void find(TreeNode* root, int sum)
{
	if (root == NULL)return;		
	path.push_back(root->val);		//����ǰ���ڵ��ֵѹ��path
	if (!root->left && !root->right && sum == root->val)		//�����ǰ�ڵ�ΪҶ�ӽڵ㲢�ҵ�ǰ���ڵ��ֵ��ʣ���ֵ��ͬ
		res.push_back(path);		//����ǰpathѹ����������
	else				//�����ǰ�ڵ㲻��Ҷ�ӽڵ㣬�������ӽڵ�
	{
		if (root->left)
			find(root->left, sum - root->val);
		if (root->right)
			find(root->right, sum - root->val);
	}
	path.pop_back();	//�ڷ��ظ��ڵ�֮ǰɾ��ѹ��·����ֵ
}
vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
	find(root, expectNumber);
	return res;
}

//����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,
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
//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
//1��ʹ�ÿ���������
//2������ķ���
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


//����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
//����һ���ַ���,���Ȳ�����9(�������ַ��ظ�),�ַ�ֻ������Сд��ĸ��

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


//HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ����������鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,
//������ȫΪ������ʱ��,����ܺý��������,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
//����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)����᲻�ᱻ������ס��(�������ĳ���������1)
int solution::FindGreatestSumOfSubArray(vector<int> array) {
	int sum = array[0];
	int tmpsum = array[0];

	for (size_t i=1;i<array.size();i++)
	{
		if (tmpsum <= 0)		//��������ڵ�i������Ӻ�С��0��������֮ǰ������
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

//���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,���Ƕ��ں�����������û���ˡ�
//ACMerϣ�����ǰ����,������������ձ黯,���Ժܿ���������Ǹ�����������1���ֵĴ�����
int NumberOf1Between1AndN_Solution(int n)
{
	return 0;
}








//����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
//ʹ������������������������õ��ľ��������
//��û������

void convertNode(TreeNode *root) 
{
	if (root->left != NULL)
	{
		TreeNode* rootLeft = root->left;	//������ڵ�
		while (rootLeft->right != NULL)
		{
			rootLeft = rootLeft->right;		//�ҵ����������
		}
		rootLeft->right = root;				//����
		root->left = rootLeft;

		convertNode(root->left);
	}
	
	if (root->right != NULL)
	{
		TreeNode* rootRight = root->right;
		while (rootRight->left != NULL)
		{
			rootRight = rootRight->left;	//�ҵ���С������
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
	//�ҵ���С�Ľڵ���Ϊ�����ͷ���
	TreeNode* listHead = NULL;
	while (root->left != NULL)
	{
		root = root->left;
	}
	listHead = root;

	convertNode(pRootOfTree);
	
	return listHead;


}



//��ӡ��1--1000�ڵ����е�����
void solution::printSuShu()
{
	bool flag = true;
	//�ܱ�2�����Ŀ϶���������,ȥ��һ��������
	for (int i=1;i<=100;i+=2)
	{
		//�ж��ܷ� 3--2/i ֮�������������ȥ��һ���������
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

//��������еڶ����ֵ
//˼����ǣ�ѭ������һ�����飬������������������max��second�������i�����ݴ���max������max��second�����ֻ����second�������second
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

//�������·��
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



//һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε�����
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
	//����ֵ�����Ľ��
	for (int i = 0; i < len; i++)
	{
		resultOr ^= data[i];
	}
	//�������������һ��1���ڵ�λ��
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

//����һ����������������һ������S���������в������������ǵ����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
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
	unordered_map<int,int> m;		//ʹ��hashmap֮��ʱ�临�ӶȽ��͵�O(n)����ռ�ø���ռ�
	vector<int> result;

	for (auto i=0;i < array.size();i++)
	{
		int value = sum - array[i];		//�ҵ���ǰ��Ӧ��ֵ

		if (m.find(value) != m.end())	//����ҵ����򱣴�����
		{
			//����������
			result.push_back(value);
			result.push_back(sum - value);

			//�����������ı��
			//result.push_back(m[value]);
			//result.push_back(i + 1);
			
		}

		m[array[i]] = i + 1;			//����������򱣴浱ǰ�������ı��
	}
	return result;


}

//�����Ϊs�������������С������ڰ��մ�С�����˳�����м䰴�մ�С�����˳��
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

//ѭ�������ַ���s
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



//��ת����˳����"I am a student."���"student. a am I"
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
	//���ȷ�ת��������
	int len = str.size();
	ReverseWord(str, 0, len - 1);
	int start = 0, end = 0;
	int count = 0;
	while (count < len)
	{
		//�����ͷ�пո�������
		while (count < len && str[count] == ' ')
		{
			count++;
		}
		start = count;

		//�ҵ�ĩβ
		while (count < len && str[count] != ' ')
		{
			count++;
		}
		end = count;

		//��ת�ֲ�����
		ReverseWord(str, start, end - 1);
	}
	return str;
}


string solution::LeftRotateString2(string str, int n)
{
	//���ȷ�תȫ����
	ReverseWord(str, 0, str.size()-1);
	n = str.size() - n;
	//�ֱ�ת����
	ReverseWord(str, 0, n - 1);
	ReverseWord(str, n, str.size() - 1);


	return str;



}

//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж����
//1���μ���ָoffer��ʹ�ù��캯��
//2��ʹ�ö�·ԭ��
int solution::SumN(int n)
{
	int sum = n;
	
	n > 0 && (sum += SumN(n - 1));

	return sum;
}

//��������Զ���������������֮��
int solution::Add(int num1, int num2)
{
	int tmp;
	while (num1 !=0)
	{
		tmp = num2;	//�Ƚ�num2����һ��  ����5��101�� + 7��111��
		num2 = num1 ^ num2;		//����󲻽�λ��ֵ ��010��
		num1 = (num1 & tmp) << 1;	//���λ��ֵ��1010��
	}

	return num2;
	
}


//����һ���ַ���������ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0
int solution::StrToInt(string str)
{
	int flag = 0;
	int count = 0;
	int result = 0;

	if (str.empty())
	{
		return 0;
	}

	if (str[0] == '-')		//�жϵ�һλ�Ƿ��С�+��  ��-������
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


//����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]��
//����ʹ�ó�����
vector<int>  solution::multiply(const vector<int > &A)
{

	int len = A.size();
	vector<int> B(len,1);
	
	if (len != 0)
	{
		B[0] = 1;

		//����������������
		for (int i = 1; i < len; i++)
		{
			B[i] = B[i - 1] * A[i - 1];
		}

		//����������������
		int tmp = 1;
		for (int i = len - 1; i > 0; i--)
		{
			tmp *= A[i];
			B[i - 1] *= tmp;
		}
	}
	return B;
}

//һ�������а��������󻷵���ڵ�ַ
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
	

	//�ҵ�����ָ��Ľ��㣬�佻���Ȼ�ڻ���
	while (pFast != pSlow)
	{
		if (pFast->next == NULL)
		{
			return NULL;		//����пսڵ㣬˵���������ڻ�������NULL
		}
		if (pFast->next->next == NULL)
		{
			return NULL;		//����пսڵ㣬˵���������ڻ�������NULL
		}

		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}

	//��ָ�����ת����ָ�벻��
	pSlow = pSlow->next;
	LoopCount = 1;
	//�ҵ����Ľڵ���
	while (pFast != pSlow)
	{
		pSlow = pSlow->next;
		LoopCount++;
	}
	//������ָ�붼ָ��pHead
	pFast = pHead;
	pSlow = pHead;

	//����ָ�����ʼ�ڵ�����LoopCount,��ָ���pHead��ʼ��
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


//��һ�������������ɾ���б����ظ��Ľڵ㣬�ظ��Ĳ���������1-2-3-3-4-4-5�������1-2-5
ListNode* solution::deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		return pHead;
	}
	if (pHead->val == pHead->next->val)		//�����ǰ�ڵ����ظ��ڵ�
	{
		ListNode *pNode = pHead->next;
		while (pNode != NULL && pNode->val == pHead->val)
		{
			pNode = pNode->next;		//�����뵱ǰ�ڵ���ͬ�Ľڵ�
		}

		return deleteDuplication(pNode);				//��������ǰ�ڵ㣬�ӵ�ǰ�ڵ㿪ʼ�ݹ�


	}
	else
	{
		pHead->next = deleteDuplication(pHead->next);	//������ǰ�ڵ㣬���¸��ڵ㿪ʼ�ݹ�
		return pHead;
	}
}

//����һ����������һ���ڵ㣬���ҳ��������˳���µ���һ���ڵ㲢���أ������ְ���ָ�����ҽڵ�͸��ڵ��ָ��
TreeLinkNode* solution::GetNext(TreeLinkNode* pNode)
{
	if (pNode == NULL)				//����ڵ�Ϊ�սڵ㣬�򷵻ؿ�
	{
		return NULL;
	}

	if (pNode->right != NULL)		//����ڵ���ҽڵ����,���ҵ��ҽڵ���������ڵ�
	{
		pNode = pNode->right;
		while (pNode->left != NULL)
		{
			pNode = pNode->left;
		}
		return pNode;
			
	}
	
	while (pNode->next != NULL)		//���ڵ㲻Ϊ��
	{
		if (pNode->next->left == pNode)	//�ýڵ��Ǹ��ڵ���������ڵ�
		{
			return pNode->next;
		}
		else
		{
			pNode = pNode->next;		//����ýڵ��Ǹ��ڵ���������ڵ㣬������жϸ��ڵ�ĸ��ڵ�
		}
	}

	return NULL;
	
	
	

}








//��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� 
//�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
//û������
bool solution::match(char * str, char * pattern)
{
	int strlength = strlen(str);
	int patlength = strlen(pattern);
	char pre = '*';	//�����洢��һ���ַ�
	char next = '*';	//�����洢��һ���ַ�

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
			if (*pattern == '.')	//�����'.'���Ա��εıȽ�
			{
				pattern++;
				str++;
			}
			else if (*pattern == '*')
			{
				next = *(++pattern);	//������һ���ַ�
				pattern--;
				if (pre == *str)	//�������һ���ַ���ͬ
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
					pre = *pattern;		//������һ���ַ�
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


//�������ַ�������Ĺ����Ӵ���������䳤��
int solution::findMaxSubString(string str1, string str2,string &result)
{
	//����һ����ά���飬��Ӧ��[i][j]����ȣ��򽫸õ�����Ϊ1�����ͳ�ƶԽ�����������1�ĸ���
	int len1 = str1.length();
	int len2 = str2.length();
	vector<vector<int>> arr(len1, vector<int>(len2));//����һ����ά����
	

	for (int i=0;i<len1;i++)			////�������λ�õ�Ԫ����ȣ�����ֵΪ1,����Ϊ0
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
	for (int i = 0; i < len1; i++)			//�ж϶Խ������������1�ĸ���
	{		
		for (int j=0;j<len2;j++)
		{
			int m = i;						//�жϴ�[i][j]�㿪ʼ���Խ������������ж��ٸ�
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

//�ж�һ�Ŷ������Ƿ�Գ�
bool comRoot(TreeNode* left, TreeNode* right)
{
	if (left == NULL && right == NULL)		//�����Ϊ�գ��򷵻�true
	{
		return true;
	}
	else if (left != NULL && right != NULL )//�������Ϊ��
	{
		if (left->val != right->val)		//�ж������ڵ��Ƿ����
		{
			return false;
		}
		else								//�����ȣ��ж���ڵ�����ӽڵ���ҽڵ�����ӽڵ��Լ� ��ڵ�����ӽڵ���ҽڵ�����ӽڵ��Ƿ�ֱ����
		{
			return comRoot(left->left, right->right) && comRoot(left->right, right->left);
		}
	}
	else									//�����һ��Ϊ�գ�һ����Ϊ�գ�����false
	{
		return false;
	}
	
}
bool solution::isSymmetrical(TreeNode* pRoot)
{
	if (pRoot == NULL)    return true;
	
	return comRoot(pRoot->left, pRoot->right);	//�Ƚ���ڵ���ҽڵ�
}

//��֮�ִ�ӡ������
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
	que.push(pRoot);		//��ͷ���������
	while (!que.empty())
	{
		vector<int> vec;
		const int size = que.size();
		for (int i=0;i<size;i++)	//ÿһ�ν���ǰsize���е����ݶ��������
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
		if (direction == true)				//���direction == true�������е����������У�ÿһ�ε���һ��direction����
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


//����һ���������������ҳ����е�kС�Ľڵ�
//ʱ�临�ӶȽϸ�
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
TreeNode* solution::KthNode2(TreeNode* pRoot, int k)	//���û������������NULL����������Ϊ�գ���Ϊ���ֵ
{
	if (pRoot!=NULL)		//�������
	{
		TreeNode *node = KthNode2(pRoot->left, k);
		if (node != NULL)
		{
			return node;
		}
		index++;	//������
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

//�ж϶������Ƿ�Ϊƽ�������
//ƽ��������ĸ����ǿ����������������ĸ߶Ȳ����1

//1���ж��������������










//���ֲ��ҷ���ѭ���͵ݹ�
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

//�ݹ鷨
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













