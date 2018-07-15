#include "Sort.h"



Sort::Sort()
{
}


Sort::~Sort()
{
}
int Sort::partition(vector<int> &data, int l, int r)
{
	int index = rand() % (r - l) + r;
	swap(data[l], data[index]);
	int v = data[l];

	while ( l < r)
	{
		if (data[r] < v)
		{
			swap(data[r], data[l]);
			l++;
		}
		else
		{
			r--;
		}
	}
	swap(v, data[l]);

	return l;
}
void Sort::quickSort(vector<int> &data, int l, int r)
{
	if (l >= r)
	{
		return;
	}

	int p = partition(data, l, r);		//找到一个p，使得左边的都比p对应的值小，右边的都比P所在的值大
	quickSort(data, l, p-1);
	quickSort(data, p + 1, r);
}

void Sort::quickSort(vector<int> &data)
{
	int size = data.size();
	quickSort(data, 0, size - 1);
}