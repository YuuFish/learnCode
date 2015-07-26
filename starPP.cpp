#include<iostream>

using namespace std;

void test(int* p, int n);

int main()
{
	int a[5] = {1, 2, 3, 4, 5};
	int* p = a;
	cout << "*p++= " << *p++ << endl;
	p = a;
	/*
		*p++使得p在解引用之前增大，因为*和++两个运算符有相同的优先级并按自右向左的方式结合。 
		同级运算符，自右向左，*p++相当于*(p++);
	*/
	cout << "*(p++)= " << *(p++) << endl; // *p++ == *(p++);
	cout << "other test\n";
	test(a, 5);
	cin.get();
}

void test(int a[], int n)
{
	cout << "*arr++ = " << *a++ << endl; // 传参时，数组往后退一层，一维数组只是相当于指针，因此可变
	a += 3;
	cout << *a << endl;
}