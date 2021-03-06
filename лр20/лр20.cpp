// лр20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;



template <typename type, unsigned int size> class mas
{
private:
	int k = size;
	type *arr;//створення динамічного масиву
public:
	mas() { arr=new type[size]; }//виділяє пам'ять для масиву
	type& operator[] (int index) { return arr[index]; }//перевантаження оператора[] для масиву
	int a_size() { return k; }//повертає розмірність масиву

	type min()//знаходження мінімального елементу масиву
	{
		type min=arr[0];
		for (int i = 0; i < a_size(); i++)
		{
			if (arr[i] < min)
			{
				min = arr[i];
			}
		}
		return min;
	}

	type max()//знаходження максимального елементу масиву
	{
		type max = arr[0];
		for (int i = 0; i < a_size(); i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		return max;
	}

	type avg()//середнє арифметичне всіх чисел масиву
	{
		type avgg = 0;
		for (int i = 0; i < a_size(); i++)
		{
			avgg += arr[i];
		}
		return avgg/a_size();
	}

	void SortAscending()//сортування від меншого числа до більшого
	{
		bool f = true;
		type help;
		while (f)
		{
			f = false;
			for (int i = 0; i < a_size()-1; i++)
			{
				if (arr[i] > arr[i + 1])
				{
					f = true;
					help = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = help;
				}
			}
		}
	}

	void sortDescending()//сортування від більшого числа до меншого
	{
		bool f = true;
		type help;
		while (f)
		{
			f = false;
			for (int i = 0; i < a_size() - 1; i++)
			{
				if (arr[i] < arr[i + 1])
				{
					f = true;
					help = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = help;
				}
			}
		}
	}

	void add_back(type addnumb)//додавання елементу у кінець масиву
	{
		k++;
		arr[k - 1] = addnumb;
	}

	void deleteI(int in)//видалення елементу по індексу
	{
		type help;
		for (int i = in; i < a_size(); i++)
		{
			help = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = help;
		}
		k--;
	}

	void deleteN(type in)//видалення елементів з даним значенням
	{
		type help;
		int helpk=0;
		for (int i = 0; i < a_size(); i++)
		{
			if (arr[i]==in)
			{
				for (int j = i; j < a_size(); j++)
				{
					help = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = help;
				}
				helpk++;
			}
		}
		k -= helpk;;
	}
};

int main()
{
	mas<int,5> p;
	int y;
	for (int i = 0; i < p.a_size(); i++)
	{
		cout << "[" << i << "]:";
		cin >> p[i];
	}
	cout<<"Min: ";
	cout << p.min();
	cout << endl;
	cout << "Max: ";
	cout << p.max();
	cout << endl;
	cout << "avg: ";
	cout << p.avg();
	cout << endl;
	cout << "Sort Ascending: "<<endl;
    p.SortAscending();
	cout << endl;
	for (int i = 0; i < p.a_size(); i++)
	{
		cout << "[" << i << "]:" << p[i] << endl;;
	}
	cout << "Sort Descending: " << endl;
	p.sortDescending();
	cout << endl;
	for (int i = 0; i < p.a_size(); i++)
	{
		cout << "[" << i << "]:" << p[i] << endl;;
	}
	cout << endl;
	cout << "Adding an array element : " << endl;
	cin >> y;//вводимо значення яке ми хочимо добавити в кінець масиву
	p.add_back(y);
	for (int i = 0; i < p.a_size(); i++)
	{
		cout << "[" << i << "]:" << p[i] << endl;;
	}
	cout << endl;
	cout << "Delete array element by index : " << endl;
	cin >> y;//вводимо індекс елементу який ми хочимо видалити
	p.deleteI(y);
	for (int i = 0; i < p.a_size(); i++)
	{
		cout << "[" << i << "]:" << p[i] << endl;;
	}
	cout << endl;
	cout << "Remove array element by value : " << endl;
	cin >> y;//вводимо елемент з яким ми хочимо видалити 
	p.deleteN(0);
	for (int i = 0; i < p.a_size(); i++)
	{
		cout << "[" << i << "]:" << p[i] << endl;;
	}
	system("pause");
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
