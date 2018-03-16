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
		if (s)
		{
			str = new char[strlen(s) + 1];
			strcpy(str, s);
			len = strlen(s);
		}
		else
			str = new char;


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
	TString & operator = (const TString &s) //оператор присваивания
	{
		if (this == &s)
			return *this;
		if (len != s.len)
		{
			delete[] str;
			str = new char[s.len + 1];
		}
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
	void setString(char *_s) //задать строку
	{
		if (_s)
			str = new char[strlen(_s) + 1];
		else
			str = new char;
		len = strlen(_s);
		strcpy(str, _s);
	}
	int length() //узнать длину строки
	{
		return len;
	}
	char symbol(int index) //получить символ строки по его индексу
	{
		return *(str + index - 1);
	}
	void changeSymbol(int index, char symbol) //изменить строку по заданному символу
	{
		*(str + index - 1) = symbol;
	}
	bool palindrome() //является ли строка палиндромом?
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
		return number == len / 2;
	}
	int differentSymbol() //узнать, сколько различных букв в алфавите
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
		return number;
	}
};

int main()
{
	char string[40];
	int a, b, c, d;
	char k;
	setlocale(LC_ALL, "Russian");
	TString s2;
	TString s1("test");
	s2 = s1; // проверка работы оператора присваивания
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
	case 2:
	{
		if (s2.palindrome() == 0)
			cout << "Строка не палиндром" << endl;
		else
			cout << "Строка - палиндром" << endl;
		break;
	}
	case 3:
	{
		cout << "Количество разных символов в строке:" << s2.differentSymbol() << endl;
		break;
	}
	case 4:
	{
		cout << "Введите границы подстроки:" << endl;
		cout << "Начало(включительно):";
		cin >> b;
		cout << "Конец(включительно):";
		cin >> c;
		for (int i = b; i <c + 1; i++)
		{
			cout << s2.symbol(i);
		}
		cout << endl;


		break;
	}
	case 5:
	{
		cout << "Длина строки:" << s2.length() << endl;
		break;
	}
	case 6:
	{
		cout << "Введите индекс строки:";
		cin >> c;
		cout << "Символ строки по заданному индексу:" << s2.symbol(c) << endl;
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
	}
	}
	system("pause");
}