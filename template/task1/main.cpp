#include <iostream>
#include <locale.h>

using namespace std;

class TWeighingScales
{
private:
	double kg; // вес в киллограммах
public:
	TWeighingScales(double _kg = 0)// конструктор
	{
		kg = _kg;
	}
	TWeighingScales & operator=(const TWeighingScales & kg1) //оператор присваивания
	{
		kg = kg1.kg;
		return *this;
	}
	void display() //вывод на экран
	{
		cout << "Вес в киллограммах: " << kg << endl;
	}
	double killograms() //содержит вес в киллограммах
	{
		return kg;
	}
	double pharmacyPound() //преобразование в аптечный фунд 
	{
		return kg * 2.2679;
	}

	double troyOunce() // преобразование в тройскую унцию 
	{
		return kg * 35.2739;
	}
	double pood() // преобразование в пуд 
	{
		return kg * 0.061;
	}
	void displayPharmacyPound()
	{
		cout << "Вес в единице измерения аптечный фунд:" << pharmacyPound() << endl;
	}
	void displayTroyOunce()
	{
		cout << "Вес в единице измерения тройская унция:" << troyOunce() << endl;
	}
	void displayPood()
	{
		cout << "Вес в единице измерения пуд:" << pood() << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	double flag;
	int a, b;
metka2:cout << "Введите вес в киллограммах:";
	cin >> flag;
	TWeighingScales weight1, weight2(flag);
	weight1.operator=(weight2);
metka3:cout << "\n Выберите действие:\n" << endl;
	cout << "1. Узнать текущий вес в килограммах\n" << endl;
	cout << "2. Узнать вес в выбранной единице измерения\n" << endl;
	cout << "3. Изменить вес в килограммах\n" << endl;
	cin >> a;
	switch (a)
	{
	case 1: weight2.display(); break;
	case 2:
	{
	metka1:cout << "В какой единице измерения вы предпочитаете узнать вес?\n" << endl;
		cout << "1. Аптечный фунд" << endl;
		cout << "2. Тройская унция" << endl;
		cout << "3. Пуд" << endl;
		cin >> b;
		switch (b)
		{
		case 1: weight2.displayPharmacyPound(); break;
		case 2: weight2.displayTroyOunce(); break;
		case 3: weight2.displayPood(); break;
		default: cout << "Некорректный ввод. Повторите попытку.\n"; goto metka1;
		}
		break;
	}
	case 3: goto metka2;
	default: cout << "Некорректный ввод. Повторите попытку.\n"; goto metka3;
	}
}