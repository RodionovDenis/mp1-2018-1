#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

long factorial(int number) //��������� ��� ���������� �������
{
	long factorial = 1;
	for (int i = 1; i <= number; i++)
		factorial = factorial * i;
	return factorial;
}

class TTeilorFormuls
{
private:
	int NumberFunction; //����� ��������� ������� 1-sin, 2-cos, 3-exp.
	double x; //���������� ������� � ����� �.
	int n; //���������� ������.

public:
	TTeilorFormuls(int _NumberFunction = 0, double _x = 0, int _n = 0) //�����������
	{
		NumberFunction = _NumberFunction;
		x = _x;
		n = _n;
	}
	~TTeilorFormuls() //����������
	{}
	TTeilorFormuls(TTeilorFormuls & fun) //����������� �����������
	{
		NumberFunction = fun.NumberFunction;
		x = fun.x;
		n = fun.n;
	}
	TTeilorFormuls & operator=(const TTeilorFormuls &fun)
	{
		NumberFunction = fun.NumberFunction;
		x = fun.x;
		n = fun.n;
		return *this;
	}
	void SetFunction(int number) //������ �������
	{
		if (number != 1 && number != 2 && number != 3)
			throw number;
		NumberFunction = number;

	}
	int DiscoverFunction() //������ �������
	{
		return NumberFunction;
	}
	void SetMemberSeries(int number) //������ ����� �����
	{
		if (number < 0)
			throw number;
		n = number;
	}
	int DiscoverMemberSeries() //������ ����� �����
	{
		return n;
	}
	void SetX(double number) //������ ����� ����������
	{
		x = number;
	}
	double DiscoverX() //������ ����� ����������
	{
		return x;
	}
	friend void FormulaMember(TTeilorFormuls & fun); //������� ����, ��������� ���������������
	double ValueMember(int number) //�������� ��������� ����� ����
	{
		switch (NumberFunction)
		{
		case 1:
		{
			return pow(x, 2 * number - 1) / factorial(2 * number - 1);
		}
		case 2:
		{
			return pow(x, 2 * number - 2) / factorial(2 * number - 2);
		}
		case 3:
		{
			return pow(x, number - 1) / factorial(number - 1);
		}
		}

	}
	double ValueSeries() //�������� ���� � ��������� ����� �.
	{
		double value = 0.0;
		switch (NumberFunction)
		{
		case 1:
		{
			for (int i = 0; i < n; i++)
				value = value + pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);
			break;
		}
		case 2:
		{
			for (int i = 0; i < n; i++)
				value = value + pow(-1, i) * pow(x, 2 * i) / factorial(2 * i);
			break;
		}
		case 3:
		{
			for (int i = 0; i < n; i++)
				value = value + pow(x, i) / factorial(i);
			break;
		}
		}
		return value;
	}
	double Fault() //���������� �������� ���� � ��������� ����� �� ���������� �������� ������� ������� � ������ �����.
	{
		switch (NumberFunction)
		{
		case 1:
		{
			return abs(sin(x) - (*this).ValueSeries());
		}
		case 2:
		{
			return abs(cos(x) - (*this).ValueSeries());
		}
		case 3:
		{
			return abs(exp(x) - (*this).ValueSeries());
		}
		}
	}

};

void FormulaMember(TTeilorFormuls & fun) //������� ����
{
	switch (fun.NumberFunction)
	{
	case 1:
	{
		cout << "sin(x) = ";
		for (int i = 0; i <fun.n; i = i++)
		{
			if (i % 2 == 0)
				cout << " + ";
			else
				cout << " - ";
			cout << "x^" << 2 * i + 1 << "/" << 2 * i + 1 << "!";
		}
		cout << endl;
		break;
	}
	case 2:
	{
		cout << "cos(x) = ";
		for (int i = 0; i <fun.n; i++)
		{
			if (i % 2 == 0)
				cout << " + ";
			else
				cout << " - ";
			cout << "x^" << 2 * i << "/" << 2 * i << "!";
		}
		cout << endl;
		break;
	}
	case 3:
	{
		cout << "exp(x) = ";
		for (int i = 0; i < fun.n; i++)
		{
			cout << " + x^" << i << "/" << i << "!";
		}
		cout << endl;
		break;
		break;
	}
	default:
	{
		cout << "������������ ����." << endl;
	}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, c, d;
	double x0;
	TTeilorFormuls f1(1, 1, 7), f2(2, 3, 5), f3;
	f1 = f2; //�������� ������������
	cout << "�������� �������:\n" << endl;
	cout << "1.sin" << endl;
	cout << "2.cos" << endl;
	cout << "3.exp" << endl;
	try
	{
		cin >> a;
		f3.SetFunction(a);
		cout << "\n������� ����� ����������:";
		cin >> x0;
		f3.SetX(x0);
		cout << "\n������� ���������� ������ ����:";
		cin >> b;
		f3.SetMemberSeries(b);
	}
	catch (...)
	{
		cout << "������ ���������." << endl;
		return 1;
	}
	cout << "\n �������� ���������� ��������:" << endl;
	cout << "1. ������ �������" << endl;
	cout << "2. ������ ����� �����" << endl;
	cout << "3. ������ ����� ����������" << endl;
	cout << "4. ������� ������� ����" << endl;
	cout << "5. ������ �������� ����������� ����� ����" << endl;
	cout << "6. ������ �������� ���� � ��������� �����" << endl;
	cout << "7. ���������� ���������� �� ���������� ��������" << endl;
	cin >> c;
	switch (c)
	{
	case 1:
	{
		if (f3.DiscoverFunction() == 1)
			cout << "������� ������� - sin(x)" << endl;
		if (f3.DiscoverFunction() == 2)
			cout << "������� ������� - cos(x)" << endl;
		if (f3.DiscoverFunction() == 3)
			cout << "������� ������� - exp(x)" << endl;
		break;
	}
	case 2:
	{
		cout << "����� ����� - " << f3.DiscoverMemberSeries() << endl;
		break;
	}
	case 3:
	{
		cout << "����� ���������� - " << f3.DiscoverX() << endl;
		break;
	}
	case 4:
	{
		cout << "\n ������� ����:" << endl;
		FormulaMember(f3);
		break;
	}
	case 5:
	{
		cout << "\n ������� ���� ����, ������� ����� ����������:";
		cin >> d;
		cout << "�������� ���� ��� ������� " << d << " � ����� " << f3.DiscoverX() << " = " << f3.ValueMember(d) << endl;
		break;
	}
	case 6:
	{
		cout << "\n �������� ���� �������� ������� � ����� " << f3.DiscoverX() << " = " << f3.ValueSeries() << endl;
		break;
	}
	case 7:
	{
		cout << "���������� �� ���������� ��������: " << f3.Fault() << endl;
		break;
	}
	}
	system("pause");
}