#include <iostream>
#include <cstdlib>
#include <vector>
#include <clocale>
#include <string>
#include <windows.h>
using namespace std;
struct time
{
	int hour;
	int minute;
	time(int h = 0, int m = 0) : hour(h), minute(m) {}
};
struct room
{
	int number_room;
	int basis_value_standart;
	int basis_value_vip;
	room(int n = 0, int b_s = 0, int b_v = 0)
		: number_room(n), basis_value_standart(b_s), basis_value_vip(b_v) {}
};
struct place
{
	int p_raw;
	int p_place;
	bool type;
};
struct order //скруктура заказа от пользователя
{
	int d;
	time t;
	string name;
	int number_of_hall;
	vector <place> ord_places;
	bool isReservation = false; //бронированы ли места? false - нет, true - да.

};
struct ticket //билет
{
	int t_date;
	time t_time;
	string t_name;
	int t_number_room;
	place t_place;
};
class seance
{
private:
	string name_film; //название фильма    
	int day; //день, в который будет проходить сеанс
	time time_of_seance; //время сеанса
	int number_room_copy; //номер зала, в котором будет проходить сеанс
	vector<vector<bool>> isEmployment; // true - место свободно, false - место занято
public:
	static int st_row; //количество рядов в одном зале
	static int st_place; //количество мест в одном ряду
	seance(string _name_film = "", int _day = 0, time _time_of_seance = time(0, 0), int _number_room_copy = 0) //конструктор 
		: name_film(_name_film), day(_day), time_of_seance(_time_of_seance), number_room_copy(_number_room_copy)
	{
		vector<bool> m;
		for (int i = 0; i < st_place; i++)
			m.push_back(true);
		for (int i = 0; i < st_row; i++)
			isEmployment.push_back(m);
	}
	~seance() //деструктор
	{}
	seance(const seance & s) //конструктор копирования
	{
		name_film = s.name_film;
		day = s.day;
		time_of_seance = s.time_of_seance;
		number_room_copy = s.number_room_copy;
		isEmployment = s.isEmployment;
	}
	seance & operator=(const seance & s) //оператор присваивания
	{
		if (this != &s)
		{
			name_film = s.name_film;
			day = s.day;
			time_of_seance.hour = s.time_of_seance.hour;
			time_of_seance.minute = s.time_of_seance.minute;
			number_room_copy = s.number_room_copy;
			isEmployment = s.isEmployment;
		}
		return *this;
	}
	bool operator ==(const seance & s) //оператр сравнения
	{
		if (name_film == s.name_film && day == s.day && time_of_seance.hour == s.time_of_seance.hour && time_of_seance.minute == s.time_of_seance.minute)
			return true;
		else
			return false;
	}
	void ChangeData(string _name_film, int _day, time _time_of_seance, int _number_room_copy) //изменить данные
	{
		name_film = _name_film;
		day = _day;
		time_of_seance = _time_of_seance;
		number_room_copy = _number_room_copy;
	}
	bool Employment(int _row, int _place) // метод узнает занятость по месту, true - свободно , false - занято
	{
		if (isEmployment[_row - 1][_place - 1])
			return true;
		else
			return false;
	}
	void ChangeEmployment(vector <place> m) //метод бронирует места на текущий сеанс
	{
		for (size_t i = 0; i < m.size(); i++)
			for (size_t j = 0; j < m.size(); j++)
				isEmployment[m[i].p_raw - 1][m[j].p_place - 1] = false;
	}
	void CancelEmployment(vector <place> m) //метод отменяет бронирование на текущий сеанс
	{
		for (size_t i = 0; i < m.size(); i++)
			for (size_t j = 0; j < m.size(); j++)
				isEmployment[m[i].p_raw - 1][m[j].p_place - 1] = true;
	}
	string ReturnNameFilm() //вернуть название фильма сеанса
	{
		return name_film;
	}
	int ReturnDayOfTheSeance() //вернуть день, в который будет проходить сеанс
	{
		return day;
	}
	time ReturnTimeOfTheSeance() //вернуть время, в которое будет проходить сеанс
	{
		return time_of_seance;
	}
	int ReturnNumberOfHall() //вернуть номер зала, в котором будет проходить сеанс
	{
		return number_room_copy;
	}
};
class TCinema
{
private:
	vector< vector<seance> > & information;
	vector <room> & halls;
public:
	TCinema(vector < vector<seance> > & _inf = vector< vector<seance> >(), vector <room> & _halls = vector<room>())
		: information(_inf), halls(_halls) {}
	void AddSeance(seance s, int _day) //добавить сеанс в конкретный день
	{
		information[_day - 1].push_back(s);
	}
	void AddHall(room r) //добавить залл
	{
		halls.push_back(r);
	}
	vector < vector<seance> > & ReturnInformation() //вернуть вектор информации
	{
		return information;
	}
	vector <room> & ReturnHalls() //вернуть вектор залов
	{
		return halls;
	}
	seance & ReturnTheSeance(int d1, time t1, int zall) //вернуть конткретный сеанс по дню, времени, залу
	{
		for (size_t i = 0; i < information[d1 - 1].size(); i++)
		{
			if (information[d1 - 1][i].ReturnDayOfTheSeance() == d1
				&& information[d1 - 1][i].ReturnTimeOfTheSeance().hour == t1.hour
				&& information[d1 - 1][i].ReturnTimeOfTheSeance().minute == t1.minute
				&& information[d1 - 1][i].ReturnNumberOfHall() == zall)
				return information[d1 - 1][i];
			else continue;
		}
	}
	vector<seance> AllOfSeances() //возвращает вектор со всеми сеансами
	{
		vector<seance> all_of_seances;
		for (size_t i = 0; i < information.size(); i++)
			for (size_t j = 0; j < information[i].size(); j++)
				all_of_seances.push_back(information[i][j]);
		return all_of_seances;
	}
};
class TTicketOffice
{
private:
	TCinema  my_cinema; //кинотеатр
	vector <order> orders; //вектор заказов
public:
	TTicketOffice(TCinema  _my_cinema, vector <order> _orders)
		: my_cinema(_my_cinema), orders(_orders) {}
	int AcceptData(int _day, time _t, string _name, int _number_of_hall, vector<place> p) //принять данные, возвращает номер заказа
	{
		order the_order;
		the_order.d = _day;
		the_order.t = _t;
		the_order.name = _name;
		the_order.number_of_hall = _number_of_hall;
		the_order.ord_places = p;
		orders.push_back(the_order);
		return orders.size();
	}
	bool CheckPlaces(seance seans, vector<place> m) //проверка на наличие мест
	{
		for (size_t i = 0; i < my_cinema.ReturnInformation().size(); i++)
			for (size_t j = 0; j < my_cinema.ReturnInformation()[i].size(); j++)
			{
				if (my_cinema.ReturnInformation()[i][j] == seans)
				{
					for (size_t k = 0; k < m.size(); k++)
						if (my_cinema.ReturnInformation()[i][j].Employment(m[k].p_raw, m[k].p_place) == false)
							return false;
					return true;
				}
				else continue;
			}
	}
	bool MakeReservation(int a) //забронировать билет по номеру заказа
	{
		seance s(orders[a - 1].name, orders[a - 1].d, orders[a - 1].t, orders[a - 1].number_of_hall);
		for (size_t i = 0; i < my_cinema.ReturnInformation()[orders[a - 1].d - 1].size(); i++)
		{
			if (my_cinema.ReturnInformation()[orders[a - 1].d - 1][i] == s)
			{
				if ((*this).CheckPlaces(my_cinema.ReturnInformation()[orders[a - 1].d - 1][i], orders[a - 1].ord_places))
				{
					my_cinema.ReturnTheSeance(orders[a - 1].d, orders[a - 1].t, orders[a - 1].number_of_hall).ChangeEmployment(orders[a - 1].ord_places);
					orders[a - 1].isReservation = true;
					return true;
				}
			}
		}
		return false;
	}
	double TotalValue(int a) //общая стоимость билетов по номеру заказа
	{
		double amount = 0;
		if (orders[a - 1].t.hour < 12)
		{
			cout << orders[a - 1].ord_places.size() << endl;
			for (size_t i = 0; i < orders[a - 1].ord_places.size(); i++)
			{
				if (orders[a - 1].ord_places[i].type)
				{
					amount = amount + (0.75 * my_cinema.ReturnHalls()[orders[a - 1].number_of_hall - 1].basis_value_vip);
					cout << i << "." << amount << endl;
				}
				else
					amount = amount + (0.75 * my_cinema.ReturnHalls()[orders[a - 1].number_of_hall - 1].basis_value_standart);
			}
		}
		if (orders[a - 1].t.hour > 18)
		{
			for (size_t i = 0; i < orders[a - 1].ord_places.size(); i++)
			{
				if (orders[a - 1].ord_places[i].type)
					amount = amount + (1.5 * my_cinema.ReturnHalls()[orders[a - 1].number_of_hall - 1].basis_value_vip);
				else
					amount = amount + (1.5 * my_cinema.ReturnHalls()[orders[a - 1].number_of_hall - 1].basis_value_standart);
			}
		}
		if (orders[a - 1].t.hour<18 && orders[a - 1].t.hour>12)
		{
			for (size_t i = 0; i < orders[a - 1].ord_places.size(); i++)
			{
				if (orders[a - 1].ord_places[i].type)
					amount += my_cinema.ReturnHalls()[orders[a - 1].number_of_hall - 1].basis_value_vip;
				else
					amount += my_cinema.ReturnHalls()[orders[a - 1].number_of_hall - 1].basis_value_standart;
			}
		}
		return amount;
	}
	void DeleteOrder(int a) //удалить заказ по номеру билета
	{
		seance s(orders[a - 1].name, orders[a - 1].d, orders[a - 1].t, orders[a - 1].number_of_hall);
		for (size_t i = 0; i < my_cinema.ReturnInformation()[orders[a - 1].d - 1].size(); i++)
		{
			if (my_cinema.ReturnInformation()[orders[a - 1].d - 1][i] == s)
				my_cinema.ReturnInformation()[orders[a - 1].d - 1][i].CancelEmployment(orders[a - 1].ord_places);
		}
		orders.erase(orders.begin() + a - 1);
	}
	vector <ticket> MakeTickets(int a) // сформировать билеты по номеру заказа
	{
		ticket t_ticket;
		vector <ticket> tickets;
		if (orders[a - 1].isReservation)
		{
			for (size_t i = 0; i < orders[a - 1].ord_places.size(); i++)
			{
				t_ticket.t_date = orders[a - 1].d;
				t_ticket.t_name = orders[a - 1].name;
				t_ticket.t_number_room = orders[a - 1].number_of_hall;
				t_ticket.t_place = orders[a - 1].ord_places[i];
				t_ticket.t_time.hour = orders[a - 1].t.hour;
				t_ticket.t_time.minute = orders[a - 1].t.minute;
				tickets.push_back(t_ticket);
			}
		}
		return tickets;
	}
};
int seance::st_row = 4; //инициализация количества рядов
int seance::st_place = 5; //инициализация количество мест в одном ряду
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	int a, b, c, d, e, f, j;
	int w = 1;
	int y = 1;
	f = 1;
	time t1;
	string s1;
	seance kino;
	place q1, q2;
	vector <place> n1, n2;
	vector<vector<seance>> informations1(30);
	vector<room> rooms1;
	vector<order> orders1;
	TCinema fantastica(informations1, rooms1);
	TTicketOffice kassa(fantastica, orders1);
	while (f)
	{
		cout << endl;
		cout << "Выберите структуру:" << endl;
		cout << "1.Структура кинотеатра" << endl;
		cout << "2.Структура заказчика" << endl;
		cout << "3. Выйти из программы" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			w = 1;
			while (w)
			{
				cout << endl;
				cout << "1. Добавить залл" << endl;
				cout << "2. Добавить сеанс" << endl;
				cout << "3. Главное меню" << endl;
				cin >> b;
				switch (b)
				{
				case 1:
				{
					cout << "Номер зала:";
					cin >> c;
					cout << "Стандартная цена билета:";
					cin >> d;
					cout << "Цена VIP-билета:";
					cin >> e;
					room r1(c, d, e);
					fantastica.AddHall(r1);
					cout << "Успешно!" << endl;
					break;
				}
				case 2:
				{
					cout << "Название фильма:";
					cin.ignore();
					getline(cin, s1);
					cout << "День:";
					cin >> c;
					cout << "Время сеанса:" << endl;
					cout << "Часы:";
					cin >> t1.hour;
					cout << "Минуты:";
					cin >> t1.minute;
					cout << "Номер зала, в котором будет проходить сеанс:";
					cin >> d;
					kino.ChangeData(s1, c, t1, d);
					fantastica.AddSeance(kino, c);
					cout << "Успешно!" << endl;
					break;
				}
				case 3:
				{
					w = 0;
					break;
				}
				default:
				{
					cout << "Некорректный ввод." << endl;
					break;
				}
				break;
				}
			}
			break;
		}
		case 2:
		{
			y = 1;
			while (y)
			{
				cout << endl;
				cout << "1. АФИША НА МАЙ 2018" << endl;
				cout << "2. Проверить наличие свободных мест в требуемой зоне" << endl;
				cout << "3. Сделать заказ" << endl;
				cout << "4. Забронировать места" << endl;
				cout << "5. Общая стоимость моего заказа" << endl;
				cout << "6. Отменить заказ" << endl;
				cout << "7. Распечатать билеты" << endl;
				cout << "8. Главное меню" << endl;
				cin >> a;
				switch (a)
				{
				case 1:
				{
					for (size_t i = 0; i < fantastica.AllOfSeances().size(); i++)
					{
						cout << i + 1 << "." << fantastica.AllOfSeances()[i].ReturnNameFilm() << " , " << fantastica.AllOfSeances()[i].ReturnDayOfTheSeance() << " мая 2018." << endl;
						cout << "Время сеанса: " << fantastica.AllOfSeances()[i].ReturnTimeOfTheSeance().hour << ":" << fantastica.AllOfSeances()[i].ReturnTimeOfTheSeance().minute << endl;
						cout << "Номер зала: " << fantastica.AllOfSeances()[i].ReturnNumberOfHall() << endl;
						cout << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Введите данные сеанса." << endl;
					cout << "День:";
					cin >> b;
					cout << "Время:" << endl;
					cout << "Час:";
					cin >> t1.hour;
					cout << "Минуты:";
					cin >> t1.minute;
					cout << "Номер зала:";
					cin >> c;
					cout << "Введите места, которые желаете проверить" << endl;
				metka5:cout << "Ряд:";
					cin >> q2.p_raw;
					cout << "Место:";
					cin >> q2.p_place;
					n2.push_back(q2);
				metka4:cout << "Ещё одно место?" << endl;
					cout << "1.Да" << endl;
					cout << "2.Нет" << endl;
					cin >> j;
					switch (j)
					{
					case 1:
					{
						goto metka5;
						break;
					}
					case 2:
					{
						break;
					}
					default:
					{
						cout << "Неверный ввод." << endl;
						goto metka4;
						break;
					}
					}
					if (kassa.CheckPlaces(fantastica.ReturnTheSeance(b, t1, c), n2))
						cout << "Места свободны!" << endl;
					else
						cout << "Места заняты." << endl;
					n2.clear();
					break;
				}
				case 3:
				{
					cout << "День:";
					cin >> b;
					cout << "Время:" << endl;
					cout << "Час:";
					cin >> t1.hour;
					cout << "Минуты:";
					cin >> t1.minute;
					cout << "Название фильма:";
					cin.ignore();
					getline(cin, s1);
					cout << "Номер зала:";
					cin >> c;
				metka1:cout << "Ряд:";
					cin >> q1.p_raw;
					cout << "Место:";
					cin >> q1.p_place;
				metka3:cout << "VIP или стандарт?" << endl;
					cout << "1.VIP" << endl;
					cout << "2.Стандарт" << endl;
					cin >> e;
					switch (e)
					{
					case 1:
					{
						q1.type = true;
						break;
					}
					case 2:
					{
						q1.type = false;
						break;
					}
					default:
					{
						cout << "Некорректный ввод" << endl;
						goto metka3;
						break;
					}
					}
					n1.push_back(q1);
				metka2:cout << "Ещё одно место?" << endl;
					cout << "1.Да" << endl;
					cout << "2.Нет" << endl;
					cin >> j;
					switch (j)
					{
					case 1:
					{
						goto metka1;
						break;
					}
					case 2:
					{
						break;
					}
					default:
					{
						cout << "Неверный ввод." << endl;
						goto metka2;
					}
					}
					cout << "Заказ принят!" << endl;
					cout << "Ваш номер заказа: " << kassa.AcceptData(b, t1, s1, c, n1) << endl;
					n1.clear();
					break;
				}
				case 4:
				{
					cout << "Введите ваш номер заказа:";
					cin >> b;
					if (kassa.MakeReservation(b))
						cout << "Места успешно забронированы!" << endl;
					else
						cout << "Ошибка! Места уже были забронированы." << endl;
					break;
				}
				case 5:
				{
					cout << "Введите ваш номер заказа:";
					cin >> b;
					cout << "Общая смоимость билетов составила " << kassa.TotalValue(b) << " рублей." << endl;
					break;
				}
				case 6:
				{
					cout << "Введите ваш номер заказа:";
					cin >> b;
					kassa.DeleteOrder(b);
					cout << "Заказ отменён!" << endl;
					break;
				}
				case 7:
				{
					cout << "Введите ваш номер заказа:";
					cin >> b;
					vector <ticket> bil;
					bil = kassa.MakeTickets(b);
					cout << "ВАШИ БИЛЕТЫ:" << endl;
					if (bil.size() == 0)
					{
						cout << "Перед тем как распечатать билеты, их сначала нужно забронировать!" << endl;
					}
					for (size_t i = 0; i < bil.size(); i++)
					{
						cout << endl;
						cout << "Билет номер " << i + 1 << "." << endl;
						cout << "Дата: " << bil[i].t_date << " мая 2018." << endl;
						cout << "Время сеанса: " << bil[i].t_time.hour << ":" << bil[i].t_time.minute << endl;
						cout << "Название фильма: " << bil[i].t_name << endl;
						cout << "Номер зала: " << bil[i].t_number_room << endl;
						cout << "Ряд: " << bil[i].t_place.p_raw << " Место: " << bil[i].t_place.p_place << endl;
					}
					break;
				}
				case 8:
				{
					y = 0;
					break;
				}
				default:
				{
					cout << "Некорректный ввод." << endl;
					break;
				}
				}
			}
			break;
		}
		case 3:
		{
			f = 0;
			break;
		}
		default:
		{
			cout << "Некорректный ввод." << endl;
			break;
		}
		}
	}
	system("pause");
}