#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

long factorial(int number) //факториал для вычисления формулы
{
	long factorial = 1;
	for (int i = 1; i <= number; i++)
		factorial = factorial * i;
	return factorial;
}

class TTeilorFormuls
{
private:
	int NumberFunction; //номер выбранной функции 1-sin, 2-cos, 3-exp.
	double x; //вычисление функции в точке х.
	int n; //количество членов.

public:
	TTeilorFormuls(int _NumberFunction = 0, double _x = 0, int _n = 0) //конструктор
	{
		NumberFunction = _NumberFunction;
		x = _x;
		n = _n;
	}
	~TTeilorFormuls() //деструктор
	{}
	TTeilorFormuls(TTeilorFormuls & fun) //конструктор копирования
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
	void SetFunction(int number) //задать функцию
	{
		if (number != 1 && number != 2 && number != 3)
			throw number;
		NumberFunction = number;

	}
	int DiscoverFunction() //узнать функцию
	{
		return NumberFunction;
	}
	void SetMemberSeries(int number) //задать число рядов
	{
		if (number < 0)
			throw number;
		n = number;
	}
	int DiscoverMemberSeries() //узнать число рядов
	{
		return n;
	}
	void SetX(double number) //задать точку вычисления
	{
		x = number;
	}
	double DiscoverX() //узнать точку вычисления
	{
		return x;
	}
	friend void FormulaMember(TTeilorFormuls & fun); //формула ряда, использую дружественность
	double ValueMember(int number) //значение заданного члена ряда
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
	double ValueSeries() //значение ряда в выбранной точке х.
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
	double Fault() //отклонение значения ряда в выбранной точке от эталонного значения текущей функции в данной точке.
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

void FormulaMember(TTeilorFormuls & fun) //формула ряда
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
		cout << "Некорректный ввод." << endl;
	}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, c, d;
	double x0;
	TTeilorFormuls f1(1, 1, 7), f2(2, 3, 5), f3;
	f1 = f2; //проверка присваивания
	cout << "Выберите функцию:\n" << endl;
	cout << "1.sin" << endl;
	cout << "2.cos" << endl;
	cout << "3.exp" << endl;
	try
	{
		cin >> a;
		f3.SetFunction(a);
		cout << "\nЗадайте точку вычисления:";
		cin >> x0;
		f3.SetX(x0);
		cout << "\nВведите количество членов ряда:";
		cin >> b;
		f3.SetMemberSeries(b);
	}
	catch (...)
	{
		cout << "Объект поврежден." << endl;
		return 1;
	}
	cout << "\n Выберите дальнейшее действие:" << endl;
	cout << "1. Узнать функцию" << endl;
	cout << "2. Узнать число рядов" << endl;
	cout << "3. Узнать точку вычисления" << endl;
	cout << "4. Вывести формулу ряда" << endl;
	cout << "5. Узнать значение конкретного члена ряда" << endl;
	cout << "6. Узнать значение ряда в выбранной точке" << endl;
	cout << "7. Рассчитать отклонение от эталонного значения" << endl;
	cin >> c;
	switch (c)
	{
	case 1:
	{
		if (f3.DiscoverFunction() == 1)
			cout << "Текущая функция - sin(x)" << endl;
		if (f3.DiscoverFunction() == 2)
			cout << "Текущая функция - cos(x)" << endl;
		if (f3.DiscoverFunction() == 3)
			cout << "Текущая функция - exp(x)" << endl;
		break;
	}
	case 2:
	{
		cout << "Число рядов - " << f3.DiscoverMemberSeries() << endl;
		break;
	}
	case 3:
	{
		cout << "Точка вычисления - " << f3.DiscoverX() << endl;
		break;
	}
	case 4:
	{
		cout << "\n Формула ряда:" << endl;
		FormulaMember(f3);
		break;
	}
	case 5:
	{
		cout << "\n Введите член ряда, который нужно рассчитать:";
		cin >> d;
		cout << "Значение ряда под номером " << d << " в точке " << f3.DiscoverX() << " = " << f3.ValueMember(d) << endl;
		break;
	}
	case 6:
	{
		cout << "\n Значение ряда заданной функции в точке " << f3.DiscoverX() << " = " << f3.ValueSeries() << endl;
		break;
	}
	case 7:
	{
		cout << "Отклонение от эталонного значения: " << f3.Fault() << endl;
		break;
	}
	}
	system("pause");
}