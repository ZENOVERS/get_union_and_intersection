#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void printVector(const vector<unsigned int>& v);

vector<unsigned int> get_union(const vector<unsigned int>& v1, const vector<unsigned int>& v2);

vector<unsigned int> get_intersection(const vector<unsigned int>& v1, const vector<unsigned int>& v2);

vector<unsigned int> remove_duplicate(const vector<unsigned int>& v);


int main()
{
	vector<unsigned int> a, dup_a, not_sort_a;
	vector<unsigned int> b, dup_b, not_sort_b;
	int data;


	cout << "Enter nonredundant, positive integers for A (-1 to end): ";
	cin >> data;

	while (data != -1)
	{
		if (!binary_search(a.begin(), a.end(), data))
		{
			a.push_back(data);
			not_sort_a.push_back(data);
		}
		else
		{
			dup_a.push_back(data);
		}

		sort(a.begin(), a.end());

		cin >> data;
	}

	for (const int& item : dup_a)
	{
		cout << "Duplicate number in A: " << item << endl;
	}


	cout << "Enter nonredundant, positive integers for B (-1 to end): ";
	cin >> data;

	while (data != -1)
	{
		if (!binary_search(b.begin(), b.end(), data))
		{
			b.push_back(data);
			not_sort_b.push_back(data);
		}
		else
		{
			dup_b.push_back(data);
		}

		sort(b.begin(), b.end());
		cin >> data;
	}

	for (const int& item : dup_b)
	{
		cout << "Duplicate number in B: " << item << endl;
	}


	cout << "A before sorting: ";
	printVector(not_sort_a);

	cout << "B before sorting: ";
	printVector(not_sort_b);

	cout << "A after sorting: ";
	printVector(a);

	cout << "B after sorting: ";
	printVector(b);


	cout << "A union B: ";
	printVector(get_union(a, b));

	cout << "A intersection B: ";
	printVector(get_intersection(a, b));

	return 0;
}

void printVector(const vector<unsigned int>& v)
{
	cout << "{";

	for (const int& item : v)
	{
		cout << " " << item;
	}

	cout << " }" << endl;
}

vector<unsigned int> get_union(const vector<unsigned int>& v1, const vector<unsigned int>& v2)
{
	vector<unsigned int> union_vec;

	for (const int& item : v1)
	{
		union_vec.push_back(item);
	}

	for (const int& item : v2)
	{
		union_vec.push_back(item);
	}

	union_vec = remove_duplicate(union_vec);
	sort(union_vec.begin(), union_vec.end());

	return union_vec;
}

vector<unsigned int> get_intersection(const vector<unsigned int>& v1, const vector<unsigned int>& v2)
{
	vector<unsigned int> inter_vec;

	for (const int& item_v1 : v1)
	{
		if (binary_search(v2.begin(), v2.end(), item_v1))
		{
			inter_vec.push_back(item_v1);
		}
	}

	for (const int& item_v2 : v2)
	{
		if (binary_search(v1.begin(), v1.end(), item_v2))
		{
			inter_vec.push_back(item_v2);
		}
	}

	inter_vec = remove_duplicate(inter_vec);
	sort(inter_vec.begin(), inter_vec.end());

	return inter_vec;
}

vector<unsigned int> remove_duplicate(const vector<unsigned int>& v)
{
	vector<unsigned int> unique_vec;

	for (const int& item : v)
	{
		if (!binary_search(unique_vec.begin(), unique_vec.end(), item))
		{
			unique_vec.push_back(item);
		}
	}

	return unique_vec;
}
