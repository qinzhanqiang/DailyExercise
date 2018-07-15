#pragma once
#include "iostream"
#include "vector"
using namespace std;

class Sort
{
private:
	void quickSort(vector<int> &data, int l, int r);
	int partition(vector<int>& data, int l, int r);
public:
	Sort();
	~Sort();

	

	void quickSort(vector<int> &data);
	
};

