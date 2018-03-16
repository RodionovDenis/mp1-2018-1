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
	TString(char *s = 0) //�����������
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
	TString(const TString &s) //����������� �����������
	{
		len = s.len;
		str = new char[len + 1];
		strcpy(str, s.str);
	}
	~TString() //����������
	{
		delete[] str;
	}
	TString & operator = (const TString &s) //�������� ������������
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
	void Print() //����� ������ �� �����
	{
		for (int i = 0; i < len; i++)
			cout << *(str + i);
		cout << endl;
	}
	void setString(char *_s) //������ ������
	{
		if (_s)
			str = new char[strlen(_s) + 1];
		else
			str = new char;
		len = strlen(_s);
		strcpy(str, _s);
	}
	int length() //������ ����� ������
	{
		return len;
	}
	char symbol(int index) //�������� ������ ������ �� ��� �������
	{
		return *(str + index - 1);
	}
	void changeSymbol(int index, char symbol) //�������� ������ �� ��������� �������
	{
		*(str + index - 1) = symbol;
	}
	bool palindrome() //�������� �� ������ �����������?
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
	int differentSymbol() //������, ������� ��������� ���� � ��������
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
	s2 = s1; // �������� ������ ��������� ������������
	cout << "������� ������:";
	gets_s(string);
	s2.setString(string);
	cout << "�������� ���������� ��������:\n" << endl;
	cout << "1.������� ������ �� �����" << endl;
	cout << "2.��������� ������ �� ���������" << endl;
	cout << "3.������ ���������� ������ �������� � ������" << endl;
	cout << "4.�������� ��������� �� ������" << endl;
	cout << "5.������ ����� ������" << endl;
	cout << "6.�������� ������ ������ �� ��� �������" << endl;
	cout << "7.�������� ������ �� ��������� �������" << endl;
	cin >> a;
	switch (a)
	{
	case 1: s2.Print(); break;
	case 2:
	{
		if (s2.palindrome() == 0)
			cout << "������ �� ���������" << endl;
		else
			cout << "������ - ���������" << endl;
		break;
	}
	case 3:
	{
		cout << "���������� ������ �������� � ������:" << s2.differentSymbol() << endl;
		break;
	}
	case 4:
	{
		cout << "������� ������� ���������:" << endl;
		cout << "������(������������):";
		cin >> b;
		cout << "�����(������������):";
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
		cout << "����� ������:" << s2.length() << endl;
		break;
	}
	case 6:
	{
		cout << "������� ������ ������:";
		cin >> c;
		cout << "������ ������ �� ��������� �������:" << s2.symbol(c) << endl;
		break;
	}
	case 7:
	{
		cout << "������� ������:" << endl;
		cin >> d;
		cout << "������� ������:" << endl;
		cin >> k;
		s2.changeSymbol(d, k);
		s2.Print();
	}
	}
	system("pause");
}