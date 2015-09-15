// StreamMedian.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

/*
* Question Description:
* (Question 69 in <Coding Intervies>) How do you find the median from a stream of numbers?
* The median of a set of numbers is the middle one when they are arranged in order. If the
* count of numbers is even, the median is defined as the average value of the two numbers in the middle.
*/

/*
* 数据的总数目为偶数时把新数据插入到最小堆里，否则插入到最大堆里
*/
template<typename T> class DynamicArray
{
public:
	void Insert(T num)
	{
		if (((min.size() + max.size()) & 1) == 0)//偶数
		{
			if (max.size() > 0 && num < max[0])
			{
				//入堆
				max.push_back(num);
				push_heap(max.begin(),max.end(),less<T>());
				num = max[0];
				//出堆
				pop_heap(max.begin(),max.end(),less<T>());
				max.pop_back();
			}
			min.push_back(num);
			push_heap(min.begin(),min.end(),greater<T>());
		}
		else
		{
			if (min.size() > 0 && min[0] < num)
			{
				min.push_back(num);
				push_heap(min.begin(),min.end(),greater<T>());
				num = min[0];
				pop_heap(min.begin(),min.end(),greater<T>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(),max.end(),less<T>());
		}
	}
	T GetMedian()
	{
		int size = min.size() + max.size();
		if (size == 0)
			throw exception("No numbers are available");
		T median = 0;
		if ((size & 1) == 1)
			median = min[0];
		else
			median = (min[0] + max[0]) / 2;
		return median;
	}
private:
	vector<T> min;//最小堆，存储较大的一半数
	vector<T> max;//最大堆，存储较小的一半数
};

// ==================== Test Code ====================
void Test(char* testName, DynamicArray<double>& numbers, double expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (abs(numbers.GetMedian() - expected) < 0.0000001)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
	DynamicArray<double> numbers;

	printf("Test1 begins: ");
	try
	{
		numbers.GetMedian();
		printf("FAILED.\n");
	}
	catch (exception e)
	{
		printf("Passed.\n");
	}

	numbers.Insert(5);
	Test("Test2", numbers, 5);

	numbers.Insert(2);
	Test("Test3", numbers, 3.5);

	numbers.Insert(3);
	Test("Test4", numbers, 3);

	numbers.Insert(4);
	Test("Test6", numbers, 3.5);

	numbers.Insert(1);
	Test("Test5", numbers, 3);

	numbers.Insert(6);
	Test("Test7", numbers, 3.5);

	numbers.Insert(7);
	Test("Test8", numbers, 4);

	numbers.Insert(0);
	Test("Test9", numbers, 3.5);

	numbers.Insert(8);
	Test("Test10", numbers, 4);

	return 0;
}