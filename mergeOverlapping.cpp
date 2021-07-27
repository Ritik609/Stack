#include<bits/stdc++.h>
using namespace std;

struct Interval
{
	int start, end;
};
bool compareInterval(Interval i1, Interval i2)
{
	return (i1.start < i2.start);
}
void mergeIntervals(Interval arr[], int n)
{
	stack<Interval> s;

	sort(arr, arr+n, compareInterval);

	s.push(arr[0]);

	for (int i = 1 ; i < n; i++)
	{
		Interval top = s.top();
		if (top.end < arr[i].start)
			s.push(arr[i]);
		else if (top.end < arr[i].end)
		{
			top.end = arr[i].end;
			s.pop();
			s.push(top);
		}
	}
	cout << "\n The Merged Intervals are: ";
	while (!s.empty())
	{
		Interval t = s.top();
		cout << "[" << t.start << "," << t.end << "] ";
		s.pop();
	}
	return;
}

int main()
{
Interval arr[] = { {22,28}, {1,8}, {25,27}, {14,19},{27,30},{5,12} };
	int n = sizeof(arr)/sizeof(arr[0]);
	mergeIntervals(arr, n);
	return 0;
}
