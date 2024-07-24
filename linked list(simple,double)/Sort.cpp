#include "sort.hpp"
#include <vector>

std::vector<int> sort::insertion(std::vector<int> v)
{
	int n = v.size();
	for (int i = 1; i < n; i++)
	{
		int key = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] > key)
		{
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = key;
	}
	return v;
}

std::vector<int> sort::bubble(std::vector<int> v)
{
	int n = v.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
	return v;
}
std::vector<int> sort::merge(std::vector<int> v)
{
	int n = v.size();
	if (n > 1)
	{
		int mid = n / 2;
		std::vector<int> left(v.begin(), v.begin() + mid);
		std::vector<int> right(v.begin() + mid, v.end());
		left = merge(left);
		right = merge(right);
		v = merge_sort(left, right);
	}
	return v;
}


std::vector<int> sort::merge_sort(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> result;
	while (left.size() > 0 || right.size() > 0)
	{
		if (left.size() > 0 && right.size() > 0)
		{
			if (left.front() <= right.front())
			{
				result.push_back(left.front());
				left.erase(left.begin());
			}
			else
			{
				result.push_back(right.front());
				right.erase(right.begin());
			}
		}
		else if (left.size() > 0)
		{
			for (int i = 0; i < left.size(); i++)
				result.push_back(left[i]);
			break;
		}
		else if (right.size() > 0)
		{
			for (int i = 0; i < right.size(); i++)
				result.push_back(right[i]);
			break;
		}
	}
	return result;
}