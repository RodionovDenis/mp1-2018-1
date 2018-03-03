#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <clocale>

using namespace std;

class TString
{
private:
	char *str;
	int len;
public:
	TString(char *s = 0) //конструктор
	{
		len = strlen(s);
		if (s)
			str = new char[len + 1];
		else
			str = new char;
		strcpy(str, s);
	}
	TString(const TString &s) //контсруктор копирования
	{
		len = s.len;
		str = new char[len + 1];
		strcpy(str, s.str);
	}
	~TString() //деструктор
	{
		delete[] str;
	}
	TString operator = (const TString &s) //оператор присваивания
	{
		if (this == &s)
			return *this;
		else if (len != s.len)
		{
			delete[] str;
			str = new char[s.len + 1];
		}
		else;
		strcpy(str, s.str);
		len = s.len;
		return *this;


	}
	void Print() //вывод строки на экран
	{
		for (int i = 0; i < len; i++)
			cout << *(str + i);
		cout << endl;
	}
	void setString(char * _s) //задать строку
	{
		if (_s)
			str = new char[strlen(_s) + 1];
		else
			str = new char;
		len = strlen(_s);
		strcpy(str, _s);
	}
	void length() //узнать длину строки
	{
		cout << "Длина строки:" << len << endl;
	}
	void symbol(int index) //получить символ строки по его индексу
	{
		cout << "Символ строки по индексу " << index << ":" << *(str + index - 1) << endl;
	}
	void changeSymbol(int index, char symbol) //изменить строку по заданному символу
	{
		*(str + index - 1) = symbol;
	}
	void substring(int start, int finish) //выделение подстроки из строки
	{
		if (start > len && finish > len)
			cout << "Некорректный ввод границ подстроки" << endl;
		else
		{
			cout << "Подстрока с указанным диапазоном:";
			for (start; start < finish + 1; start++)
			{
				cout << *(str + start - 1);
			}
			cout << endl;
		}
	}
	void palindrome() //является ли строка палиндромом?
	{


		char *flag1, *flag2;
		int number = 0;
		flag1 = str;
		flag2 = str + strlen(str) - 1;
		for (flag1, flag2; flag1 < flag2; flag1++, flag2--)
		{
			if (*flag1 == *flag2)
				number++;
		}
		if (number == len / 2)
			cout << "Строка - палиндром" << endl;
		else
			cout << "Строка - не палиндром" << endl;

	}
	void differentSymbol() //узнать, сколько разных различных букв в алфавите
	{
		int number = 1;
		int flag;
		for (int i = 1; i < len; i++)
		{
			flag = 0;
			if (*(str + i) == ' ')
				continue;
			else
			{
				for (int j = 0; j < i; j++)
				{
					if (*(str + i) != *(str + j))
						flag++;
					else;
				}
			}
			if (flag == i)
				number++;
		}
		cout << "Количество разных символов:" << number << endl;
	}
};

int main()
{
	char string[40];
	int a, b, c, d;
	char k;
	setlocale(LC_ALL, "Russian");
	TString s2("example");
	TString s1("test");
	s1 = s2; // проверка работы оператора присваивания
	cout << "Введите строку:";
	gets_s(string);
	s2.setString(string);
	cout << "Выберите дальнейшее действие:\n" << endl;
	cout << "1.Вывести строку на экран" << endl;
	cout << "2.Проверить строку на палиндром" << endl;
	cout << "3.Узнать количество разных символов в строке" << endl;
	cout << "4.Выделить подстроку из строки" << endl;
	cout << "5.Узнать длину строки" << endl;
	cout << "6.Получить символ строки по его индексу" << endl;
	cout << "7.Изменить строку по заданному символу" << endl;
	cin >> a;
	switch (a)
	{
	case 1: s2.Print(); break;
	case 2: s2.palindrome(); break;
	case 3:s2.differentSymbol(); break;
	case 4:
	{
		cout << "Введите границы подстроки:" << endl;
		cout << "start:";
		cin >> b;
		cout << "finish:";
		cin >> c;
		s2.substring(b, c);
		break;
	}
	case 5: s2.length(); break;
	case 6:
	{
		cout << "Введите индекс строки:";
		cin >> c;
		s2.symbol(c);
		break;
	}
	case 7:
	{
		cout << "Введите индекс:" << endl;
		cin >> d;
		cout << "Введите символ:" << endl;
		cin >> k;
		s2.changeSymbol(d, k);
		s2.Print();
		break;
	}
	}
	system("pause");
}