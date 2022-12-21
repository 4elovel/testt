#include <iostream>
#include <vector>
#include "windows.h"


using namespace std;

const int COUNT = 12;

class Test
{
public:
	Test()
	{
		vec.reserve(12);
	}

	Test(bool)
	{
		for (size_t i = 0; i < COUNT; i++)
		{
			vec.push_back((rand() % 90) + 10);
		}
	}

	void print() {
		for (int i = 1; i < COUNT+1; i++)
		{
			Sleep(20000 / COUNT);
			cout << vec[i-1] << " ";
			if (i % 4 == 0) {
				cout << endl;
			}
		}
	}

	void change() {
		int buf;
		for (size_t i = 0; i < COUNT; i++)
		{
			cout << "Set " << i << "number->\n";
			cin >> buf;
			vec[i] = buf;
		}
		cout << endl;
	}

	int Compare(Test b) {
		int num=0;
		for (size_t i = 0; i < COUNT; i++)
		{
			
			for (size_t j = 0; j < COUNT; j++)
			{
				if (vec[i]==b.vec[j])
				{
					num++;
					break;
				}
			}

		}
		return num;
	}
	vector <int> vec;
};


int main()
{
	srand(time(nullptr));
	cout << "You need to remember next numbers->\n";

	Test test(true);
	test.print();
	
	Sleep(1000);
	system("CLS");

	cout << "Write numbers that you remembers->\n";

	Test vec2;
	int buf;
	for (size_t i = 0; i < COUNT; i++)
	{
		cin >> buf;
		vec2.vec.push_back(buf);
	}
	cout << "You have remembered " << vec2.Compare(test) << " numbers correct!!\n";
}
