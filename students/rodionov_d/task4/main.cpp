#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;
struct dataofsong
{
	int number;
	int month;
	int year;
};
class Song
{
private:
	string name_of_song;
	string poet;
	string compouser;
	string executor;
	string name_of_album;
	dataofsong date;
public:
	Song(string _name_of_song, string _poet, string _compouser, string _executor, string _name_of_album, dataofsong _date)//конструктор инициализатор
	{
		name_of_song = _name_of_song;
		poet = _poet;
		compouser = _compouser;
		executor = _executor;
		name_of_album = _name_of_album;
		date = _date;
	}
	Song()//конструктор по умолчанию
	{
		name_of_song = "";
		poet = "";
		compouser = "";
		executor = "";
		name_of_album = "";
		date.number = 0;
		date.month = 0;
		date.year = 0;
	}
	void Change(string _name_of_song, string _poet, string _compouser, string _executor, string _name_of_album, dataofsong _date)
	{
		name_of_song = _name_of_song;
		poet = _poet;
		compouser = _compouser;
		executor = _executor;
		name_of_album = _name_of_album;
		date = _date;
	}
	Song(const Song & s) //конструктор копирования
	{
		name_of_song = s.name_of_song;
		poet = s.poet;
		compouser = s.compouser;
		executor = s.executor;
		name_of_album = s.name_of_album;
		date = s.date;
	}
	Song & operator=(const Song & s)//оператор присваивания
	{
		name_of_song = s.name_of_song;
		poet = s.poet;
		compouser = s.compouser;
		executor = s.executor;
		name_of_album = s.name_of_album;
		date = s.date;
		return *this;
	}
	bool operator==(const Song & s)
	{
		if (name_of_song == s.name_of_song && poet == s.poet && compouser == s.compouser && executor == s.executor)
			return true;
		else
			return false;
	}
	bool operator<(Song & s)
	{
		if (name_of_song < s.name_of_song)
			return true;
		else
			return false;

	}
	string GetName()
	{
		return name_of_song;
	}
	string GetExecutor()
	{
		return executor;
	}
	string GetPoet()
	{
		return poet;
	}
	string GetCompouser()
	{
		return compouser;
	}
	string GetAlbum()
	{
		return name_of_album;
	}
	dataofsong GetData()
	{
		return date;
	}
};
class Music
{
private:
	vector <Song> v;
public:
	Music(vector<Song> _v) :v(_v)
	{}
	~Music()//деструктор
	{}
	void AddSong(Song & s) //добавить новую песню
	{
		v.push_back(s);
		sort(v.begin(), v.end());
	}
	void ChangeSong(string n, string e, string _name_of_song, string _poet, string _compouser, string _executor, string _name_of_album, dataofsong _date)//изменить выбранную песню
	{
		for (int i = 0; i < v.size(); i++)
		{
			if ((*this).Search(n, e) == v[i])
			{
				v[i].Change(_name_of_song, _poet, _compouser, _executor, _name_of_album, _date);
				break;
			}
			else
				continue;
		}
		sort(v.begin(), v.end());
	}
	vector <Song> & GetVector() //получить вектор из класса
	{
		return v;
	}
	Song Search(string & n, string & e)//найти песню по названию и исполнителю
	{
		Song songsearch;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].GetName() == n && v[i].GetExecutor() == e)
			{
				songsearch = v[i];
				break;
			}
			else
				continue;
		}
		return songsearch;
	}
	vector <Song> SongsPoet(string & p) //выдать все песни заданного поэта
	{
		vector <Song> songspoet;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].GetPoet() == p)
				songspoet.push_back(v[i]);
			else
				continue;
		}
		return songspoet;
	}
	vector <Song> SongsCompouser(string & c) //выдать все песни заданного композитора
	{
		vector <Song> songscompouser;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].GetCompouser() == c)
				songscompouser.push_back(v[i]);
			else
				continue;
		}
		return songscompouser;
	}
	vector <Song> SongsExecutor(string & e) //выдать все песни заданного исполнителя
	{
		vector <Song> songsexecutor;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].GetExecutor() == e)
				songsexecutor.push_back(v[i]);
			else
				continue;
		}
		return songsexecutor;
	}
	size_t NumberSong() // узнать количество песен
	{
		return v.size();
	}
	void DeleteSong(Song & s) //удалить выбранную песню 
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == s)
			{
				v.erase(v.begin() + i);
				break;
			}
			else continue;
		}
	}
	void OutFile()
	{
		ofstream fout("music.txt");
		fout << "Выведенные песни: /название/ - /исполнитель/ - /поэт/ - /композитор/ - /альбом/ - /дата/ \n" << endl;
		for (int i = 0; i < v.size(); i++)
			fout << i + 1 << "." << v[i].GetName() << " - " << v[i].GetExecutor() << " - " << v[i].GetPoet() << " - " << v[i].GetCompouser() << " - " << v[i].GetAlbum() << " - " << v[i].GetData().number << "." << v[i].GetData().month << "." << v[i].GetData().year << endl;
		fout.close();
	}
	bool InFile(string & s)//необходимо передать файл.txt, в котором на каждой строчке написаны песни, с именем, исполнителем, композитором, .... через символ "-"
	{
		ifstream fin(s);
		if (!fin.is_open())
			return false;
		else
		{
			string s1, s2, s3, s4, s5, s6, str = "";
			dataofsong date;
			date.number = 0;
			date.month = 0;
			date.year = 0;
			while (!fin.eof())
			{
				getline(fin, str);
				string st = "";
				int k = 0;
				for (int i = 0; i < str.size(); i++)
				{
					if (str[i] != '-')
					{
						st += str[i];
					}
					else
					{
						if (k == 0)
						{
							s1 = st;
							st = "";
							k++;
							continue;
						}
						else if (k == 1)
						{
							s2 = st;
							st = "";
							k++;
							continue;
						}
						else if (k == 2)
						{
							s3 = st;
							st = "";
							k++;
							continue;
						}
						else if (k == 3)
						{
							s4 = st;
							st = "";
							k++;
							continue;
						}
						else if (k == 4)
						{
							s5 = st;
							st = "";
							k++;
							continue;
						}
					}
					if (k == 5 && i == str.length() - 1)
					{
						s6 = st;
						st = "";
						int n = 0;
						for (int i = 0; i < s6.length(); i++)
						{
							if (s6[i] != '.')
							{
								st += s6[i];
							}
							else
							{
								if (n == 0)
								{
									char * st_copy;
									st_copy = new char[st.length()];
									for (int i = 0; i < st.length(); i++)
										*(st_copy + i) = st[i];
									date.number = atoi(st_copy);
									delete[] st_copy;
									st = "";
									n++;
									continue;
								}
								if (n == 1)
								{
									char * st_copy;
									st_copy = new char[st.length()];
									for (int i = 0; i < st.length(); i++)
										*(st_copy + i) = st[i];
									date.month = atoi(st_copy);
									delete[] st_copy;
									st = "";
									n++;
									continue;
								}
							}
							if (n == 2 && i == s6.length() - 1)
							{
								char * st_copy;
								st_copy = new char[st.length()];
								for (int i = 0; i < st.length(); i++)
									*(st_copy + i) = st[i];
								date.year = atoi(st_copy);
								delete[] st_copy;
								st = "";
							}
						}
					}
				}
				Song pesnya(s1, s2, s3, s4, s5, date);
				(*this).AddSong(pesnya);
			}
			fin.close();
			return true;
		}
	}
};
int main()
{
	string n, p, c, e, alb;
	string n1, p1, c1, e1, alb1;
	dataofsong d, d1;
	setlocale(LC_ALL, "Russian");
	int a, b, l, m, check = 1;
	vector<Song> my_music, v_copy, v_copy1, p_copy;
	Music my_favourite(my_music);
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	while (check)
	{
		cout << endl;
		cout << "Выберите действие:" << endl;
		cout << "1. Добавить песню" << endl;
		cout << "2. Вывести все песни на экран" << endl;
		cout << "3. Изменить выбранную песню" << endl;
		cout << "4. Найти песню по названию и исполнителю" << endl;
		cout << "5. Выдать все песни заданного поэта" << endl;
		cout << "6. Выдать все песни заданного композитора" << endl;
		cout << "7. Выдать все песни заданного исполнителя" << endl;
		cout << "8. Узнать количество песен" << endl;
		cout << "9. Удалить выбранную песню" << endl;
		cout << "10. Записать песенник в файл" << endl;
		cout << "11. Считать песенник из файла" << endl;
		cout << "12. Выйти из программы" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			cout << "Введите название песни:";
			cin.ignore();
			getline(cin, n);
			cout << "Введите поэта песни:";
			getline(cin, p);
			cout << "Введите композитора песни:";
			getline(cin, c);
			cout << "Введите исполнителя песни:";
			getline(cin, e);
			cout << "Песня состоит в каком-нибудь альбоме?" << endl;
			cout << "1. Да" << endl;
			cout << "2. Нет" << endl;
			cin >> b;
			switch (b)
			{
			case 1:
			{
				cout << "Введите альбом песни:";
				cin.ignore();
				getline(cin, alb);
				break;
			}
			case 2:
			{
				alb = "";
				break;
			}
			default:
			{
				cout << "Некорректный ввод." << endl;
				break;
			}
			}
			cout << "Введите число, месяц, год создания песни:" << endl;
			cout << "Число:";
			cin >> d.number;
			cout << "Месяц:";
			cin >> d.month;
			cout << "Год:";
			cin >> d.year;
			Song add_song(n, p, c, e, alb, d);
			my_favourite.AddSong(add_song);
			break;
		}
		case 2:
		{
			v_copy = my_favourite.GetVector();
			cout << endl;
			cout << "Список введенных песен: /исполнитель/ - /название/ - /дата выхода/" << endl;
			for (int i = 0; i < v_copy.size(); i++)
				cout << i + 1 << "." << v_copy[i].GetExecutor() << " - " << v_copy[i].GetName() << " - " << v_copy[i].GetData().number << "." << v_copy[i].GetData().month << "." << v_copy[i].GetData().year << endl;
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "Введите название той песни, которую хотите изменить:";
			cin.ignore();
			getline(cin, n);
			cout << "Введите исполнителя той песни, которую хотите изменить:";
			getline(cin, e);
			if (my_favourite.Search(n, e).GetName() == "" || my_favourite.Search(n, e).GetExecutor() == "")
				cout << "Такой песни не существует." << endl;
			else
			{
				cout << "Введите новое название песни:";
				getline(cin, n1);
				cout << "Введите нового поэта песни:";
				getline(cin, p1);
				cout << "Введите нового композитора песни:";
				getline(cin, c1);
				cout << "Введите нового исполнителя песни:";
				getline(cin, e1);
				cout << "Песня состоит в каком-нибудь альбоме?" << endl;
				cout << "1. Да" << endl;
				cout << "2. Нет" << endl;
				cin >> b;
				switch (b)
				{
				case 1:
				{
					cout << "Введите альбом песни:";
					cin.ignore();
					getline(cin, alb1);
					break;
				}
				case 2:
				{
					alb = "";
					break;
				}
				default:
				{
					cout << "Некорректный ввод." << endl;
					break;
				}
				}
				cout << "Введите число, месяц, год создания песни:" << endl;
				cout << "Число:";
				cin >> d1.number;
				cout << "Месяц:";
				cin >> d1.month;
				cout << "Год:";
				cin >> d1.year;
				my_favourite.ChangeSong(n, e, n1, p1, c1, e1, alb1, d1);
			}
			break;
		}
		case 4:
		{
			cout << "Введите название:";
			cin.ignore();
			getline(cin, n);
			cout << "Введите исполнителя:";
			getline(cin, e);
			Song s1 = my_favourite.Search(n, e);
			cout << "Найденная песня: /название/ - /исполнитель/ - /поэт/ - /композитор/ - /альбом/ - /дата/" << endl;
			cout << s1.GetName() << " - " << s1.GetExecutor() << " - " << s1.GetPoet() << " - " << s1.GetCompouser() << " - " << s1.GetAlbum() << " - " << s1.GetData().number << "." << s1.GetData().month << "." << s1.GetData().year << endl;
			break;
		}
		case 5:
		{
			cout << "Введите поэта:";
			cin.ignore();
			getline(cin, p1);
			p_copy = my_favourite.SongsPoet(p1);
			cout << "Найденные песни: /название/ - /исполнитель/ - /поэт/ - /композитор/ - /альбом/ - /дата/" << endl;
			for (int i = 0; i < p_copy.size(); i++)
				cout << i + 1 << "." << p_copy[i].GetName() << " - " << p_copy[i].GetExecutor() << " - " << p_copy[i].GetPoet() << " - " << p_copy[i].GetCompouser() << " - " << p_copy[i].GetAlbum() << " - " << p_copy[i].GetData().number << "." << p_copy[i].GetData().month << "." << p_copy[i].GetData().year << endl;
			break;
		}
		case 6:
		{
			cout << "Введите композитора:";
			cin.ignore();
			getline(cin, p1);
			p_copy = my_favourite.SongsCompouser(p1);
			cout << "Найденные песни: /название/ - /исполнитель/ - /поэт/ - /композитор/ - /альбом/ - /дата/" << endl;
			for (int i = 0; i < p_copy.size(); i++)
				cout << i + 1 << "." << p_copy[i].GetName() << " - " << p_copy[i].GetExecutor() << " - " << p_copy[i].GetPoet() << " - " << p_copy[i].GetCompouser() << " - " << p_copy[i].GetAlbum() << " - " << p_copy[i].GetData().number << "." << p_copy[i].GetData().month << "." << p_copy[i].GetData().year << endl;
			break;
		}
		case 7:
		{
			cout << "Введите исполнителя:";
			cin.ignore();
			getline(cin, p1);
			p_copy = my_favourite.SongsExecutor(p1);
			cout << "Найденные песни: /название/ - /исполнитель/ - /поэт/ - /композитор/ - /альбом/ - /дата/" << endl;
			for (int i = 0; i < p_copy.size(); i++)
				cout << i + 1 << "." << p_copy[i].GetName() << " - " << p_copy[i].GetExecutor() << " - " << p_copy[i].GetPoet() << " - " << p_copy[i].GetCompouser() << " - " << p_copy[i].GetAlbum() << " - " << p_copy[i].GetData().number << "." << p_copy[i].GetData().month << "." << p_copy[i].GetData().year << endl;
			break;
		}
		case 8:
		{
			cout << "Количество песен в песеннике : " << my_favourite.GetVector().size() << endl;
			break;
		}
		case 9:
		{
			cout << "Введите номер песни в песеннике, которую хотите удалить:";
			cin >> m;
			l = 0;
			v_copy = my_favourite.GetVector();
			for (int i = 1; i <= v_copy.size(); i++)
			{
				if (i == m)
				{
					l = m;
					break;
				}
				else continue;
			}
			if (l == 0)
				cout << "Такой песни не существует. \n" << endl;
			else
			{
				my_favourite.DeleteSong(v_copy[l - 1]);
				cout << "Успешно!" << endl;
			}
			break;
		}
		case 10:
		{
			my_favourite.OutFile();
			cout << "Успешно!\n" << endl;
			break;
		}
		case 11:
		{
			string s;
			bool q;
			cout << "Строки в указанном файле должны идти по следующему порядку:" << endl;
			cout << "/название/-/поэт/-/композитор/-/исполнитель/-/альбом/-/число.месяц.год/" << endl;
			cout << "Введите название текстового файла(укажите .txt):";
			cin.ignore();
			getline(cin, s);
			q = my_favourite.InFile(s);
			if (q)
				cout << "Успешно!" << endl;
			else
				cout << "Файл указан неверно." << endl;
			break;
		}
		case 12:
		{
			check = 0;
			break;
		}
		default:
		{
			cout << "Неверный ввод." << endl;
			break;
		}
		}
	}
	system("pause");
}