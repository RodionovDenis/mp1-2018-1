#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;
void setcur(int x, int y) //вспомогательная функция для прекращения мерцаний.
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
struct ship_1
{
	int x1_ship1;
	int y1_ship1;
	ship_1(int a = 0, int b = 0) : x1_ship1(a), y1_ship1(b) {}
	void change(int a, int b)
	{
		x1_ship1 = a;
		y1_ship1 = b;
	}
	void transformation1(vector<vector<int>> & v)
	{
		int x_copy = x1_ship1 - 1;
		int y_copy = y1_ship1 - 1;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				if (x_copy + j <= 0 || x_copy + j >= 11 || y_copy + i <= 0 || y_copy + i >= 11)
					continue;
				else
					v[y_copy + i - 1][x_copy + j - 1] = 1;
			}
	}
};
struct ship_2
{
	int testen_two = 2;
	int x1_ship2;
	int y1_ship2;
	int x2_ship2;
	int y2_ship2;
	bool position2; // =true, если корабль вертикален, =false, если корабль горизонтален.
	ship_2(int a = 0, int b = 0, bool _position2 = false) : x1_ship2(a), y1_ship2(b), position2(_position2)
	{
		if (_position2)
		{
			x2_ship2 = a;
			y2_ship2 = b + 1;
		}
		else
		{
			x2_ship2 = a + 1;
			y2_ship2 = b;
		}
	}
	void change(int a, int b)
	{
		x1_ship2 = a;
		y1_ship2 = b;
		if (position2)
		{
			x2_ship2 = a;
			y2_ship2 = b + 1;
		}
		else
		{
			x2_ship2 = a + 1;
			y2_ship2 = b;
		}
	}
	void transformation2(vector<vector<int>> & v)
	{
		int x_copy = x1_ship2 - 1;
		int y_copy = y1_ship2 - 1;
		if (position2)
		{
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 3; j++)
				{
					if (x_copy + j <= 0 || x_copy + j >= 11 || y_copy + i <= 0 || y_copy + i >= 11)
						continue;
					else
					{
						if (v[y_copy + i - 1][x_copy + j - 1] == 2)
							continue;
						v[y_copy + i - 1][x_copy + j - 1] = 1;
					}
				}
		}
		else
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 4; j++)
				{
					if (x_copy + j <= 0 || x_copy + j >= 11 || y_copy + i <= 0 || y_copy + i >= 11)
						continue;
					else
					{
						if (v[y_copy + i - 1][x_copy + j - 1] == 2)
							continue;
						v[y_copy + i - 1][x_copy + j - 1] = 1;
					}
				}
		}
	}
};
struct ship_3
{
	int testen_three = 3;
	int x1_ship3;
	int y1_ship3;
	int x2_ship3;
	int y2_ship3;
	int x3_ship3;
	int y3_ship3;
	bool position3; // =true, если корабль вертикален, =false, если корабль горизонтален.
	ship_3(int a = 0, int b = 0, bool _position3 = false) : x1_ship3(a), y1_ship3(b), position3(_position3)
	{
		if (_position3)
		{
			x2_ship3 = a;
			y2_ship3 = b + 1;
			x3_ship3 = a;
			y3_ship3 = b + 2;
		}
		else
		{
			x2_ship3 = a + 1;
			y2_ship3 = b;
			x3_ship3 = a + 2;
			y3_ship3 = b;
		}
	}
	void change(int a, int b)
	{
		x1_ship3 = a;
		y1_ship3 = b;
		if (position3)
		{
			x2_ship3 = a;
			y2_ship3 = b + 1;
			x3_ship3 = a;
			y3_ship3 = b + 2;
		}
		else
		{
			x2_ship3 = a + 1;
			y2_ship3 = b;
			x3_ship3 = a + 2;
			y3_ship3 = b;
		}
	}
	void transformation3(vector<vector<int>> & v)
	{
		int x_copy = x1_ship3 - 1;
		int y_copy = y1_ship3 - 1;
		if (position3)
		{
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 3; j++)
				{
					if (x_copy + j <= 0 || x_copy + j >= 11 || y_copy + i <= 0 || y_copy + i >= 11)
						continue;
					else
					{
						if (v[y_copy + i - 1][x_copy + j - 1] == 2)
							continue;
						v[y_copy + i - 1][x_copy + j - 1] = 1;
					}
				}
		}
		else
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 5; j++)
				{
					if (x_copy + j <= 0 || x_copy + j >= 11 || y_copy + i <= 0 || y_copy + i >= 11)
						continue;
					else
					{
						if (v[y_copy + i - 1][x_copy + j - 1] == 2)
							continue;
						v[y_copy + i - 1][x_copy + j - 1] = 1;
					}
				}
		}
	}
};
struct ship_4
{
	int testen_four = 4;
	int x1_ship4;
	int y1_ship4;
	int x2_ship4;
	int y2_ship4;
	int x3_ship4;
	int y3_ship4;
	int x4_ship4;
	int y4_ship4;
	bool position4; // =true, если корабль вертикален, =false, если корабль горизонтален.
	ship_4(int a = 0, int b = 0, bool _position4 = false) : x1_ship4(a), y1_ship4(b), position4(_position4)
	{
		if (_position4)
		{
			x2_ship4 = a;
			y2_ship4 = b + 1;
			x3_ship4 = a;
			y3_ship4 = b + 2;
			x4_ship4 = a;
			y4_ship4 = b + 3;
		}
		else
		{
			x2_ship4 = a + 1;
			y2_ship4 = b;
			x3_ship4 = a + 2;
			y3_ship4 = b;
			x4_ship4 = a + 3;
			y4_ship4 = b;
		}
	}
	void change(int a, int b)
	{
		x1_ship4 = a;
		y1_ship4 = b;
		if (position4)
		{
			x2_ship4 = a;
			y2_ship4 = b + 1;
			x3_ship4 = a;
			y3_ship4 = b + 2;
			x4_ship4 = a;
			y4_ship4 = a + 3;
		}
		else
		{
			x2_ship4 = a + 1;
			y2_ship4 = b;
			x3_ship4 = a + 2;
			y3_ship4 = b;
			x4_ship4 = a + 3;
			y4_ship4 = b;
		}
	}
	void transformation4(vector<vector<int>> & v)
	{
		int x_copy = x1_ship4 - 1;
		int y_copy = y1_ship4 - 1;
		if (position4)
		{
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 3; j++)
				{
					if (x_copy + j <= 0 || x_copy + j >= 11 || y_copy + i <= 0 || y_copy + i >= 11)
						continue;
					else
					{
						if (v[y_copy + i - 1][x_copy + j - 1] == 2)
							continue;
						v[y_copy + i - 1][x_copy + j - 1] = 1;
					}
				}
		}
		else
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 6; j++)
				{
					if (x_copy + j <= 0 || x_copy + j >= 11 || y_copy + i <= 0 || y_copy + i >= 11)
						continue;
					else
					{
						if (v[y_copy + i - 1][x_copy + j - 1] == 2)
							continue;
						v[y_copy + i - 1][x_copy + j - 1] = 1;
					}
				}
		}
	}
};
bool correctly(int x, int y) //вспомогательная функция для проверки координат
{
	if (x == 0 || y == 0 || x == 11 || y == 11)
		return false;
	else
		return true;
}
class PlayerSeaBattle
{
protected:
	vector <ship_1> one_deck;
	vector <ship_2> two_deck;
	vector <ship_3> three_deck;
	ship_4 four_deck;
	vector<vector<bool>> board; //доска кораблей
	vector<vector<bool>> board_enemy; //доска противника(та, которая запоминает ходы)
	PlayerSeaBattle() //конструктор по умолчанию
	{
		one_deck = vector<ship_1>();
		two_deck = vector<ship_2>();
		three_deck = vector<ship_3>();
		vector<vector<bool>> v(10);//
		board = v, board_enemy = v;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
			{
				board[i].push_back(true);
				board_enemy[i].push_back(true);
			}
	}
public:
	//статические переменные
	static vector<ship_1> one_deck_use;
	static vector<ship_2> two_deck_use;
	static vector<ship_3> three_deck_use;
	static ship_4 four_deck_use;
	static vector<ship_1> one_deck_pc;
	static vector<ship_2> two_deck_pc;
	static vector<ship_3> three_deck_pc;
	static ship_4 four_deck_pc;
	static int number_1_pc;
	static int number_2_pc;
	static int number_3_pc;
	static int number_4_pc;
	static int number_1_use;
	static int number_2_use;
	static int number_3_use;
	static int number_4_use;
	vector<vector<bool>> ReturnBoard()
	{
		return board;
	}
	vector<vector<bool>> ReturnBoardEmeny()
	{
		return board_enemy;
	}
	void GetBoard(vector<vector<bool>> v)
	{
		board_enemy = v;
	}
	bool CheckShip1(ship_1 sh)
	{
		int flag1 = 0;
		int x0_1 = sh.x1_ship1 - 1;
		int y0_1 = sh.y1_ship1 - 1;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				if (x0_1 + j <= 0 || x0_1 + j >= 11 || y0_1 + i <= 0 || y0_1 + i >= 11)
				{
					flag1++;
					continue;
				}
				else
				{
					if (board[y0_1 + i - 1][x0_1 + j - 1] == true)
						flag1++;
				}
			}
		if (flag1 == 9)
			return true;
		else
			return false;
	}
	bool CheckShip2(ship_2 sh)
	{
		int flag2 = 0;
		int x0_2 = sh.x1_ship2 - 1;
		int y0_2 = sh.y1_ship2 - 1;
		if (sh.position2)
		{
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 3; j++)
				{
					if (x0_2 + j <= 0 || x0_2 + j >= 11 || y0_2 + i <= 0 || y0_2 + i >= 11)
					{
						flag2++;
						continue;
					}
					else
					{
						if (board[y0_2 + i - 1][x0_2 + j - 1] == true)
							flag2++;
					}
				}
			if (flag2 == 12)
				return true;
			else
				return false;
		}
		else
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 4; j++)
				{
					if (x0_2 + j <= 0 || x0_2 + j >= 11 || y0_2 + i <= 0 || y0_2 + i >= 11)
					{
						flag2++;
						continue;
					}
					else
					{
						if (board[y0_2 + i - 1][x0_2 + j - 1] == true)
							flag2++;
					}
				}
			if (flag2 == 12)
				return true;
			else
				return false;
		}
	}
	bool CheckShip3(ship_3 sh)
	{
		int flag3 = 0;
		int x0_3 = sh.x1_ship3 - 1;
		int y0_3 = sh.y1_ship3 - 1;
		if (sh.position3)
		{
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 3; j++)
				{
					if (x0_3 + j <= 0 || x0_3 + j >= 11 || y0_3 + i <= 0 || y0_3 + i >= 11)
					{
						flag3++;
						continue;
					}
					else
					{
						if (board[y0_3 + i - 1][x0_3 + j - 1] == true)
							flag3++;
					}
				}
			if (flag3 == 15)
				return true;
			else
				return false;
		}
		else
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 5; j++)
				{
					if (x0_3 + j <= 0 || x0_3 + j >= 11 || y0_3 + i <= 0 || y0_3 + i >= 11)
					{
						flag3++;
						continue;
					}
					else
					{
						if (board[y0_3 + i - 1][x0_3 + j - 1] == true)
							flag3++;
					}
				}
			if (flag3 == 15)
				return true;
			else
				return false;
		}
	}
	bool CheckShip4(ship_4 sh)
	{
		int flag4 = 0;
		int x0_4 = sh.x1_ship4 - 1;
		int y0_4 = sh.y1_ship4 - 1;
		if (sh.position4)
		{
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 3; j++)
				{
					if (x0_4 + j <= 0 || x0_4 + j >= 11 || y0_4 + i <= 0 || y0_4 + i >= 11)
					{
						flag4++;
						continue;
					}
					else
					{
						if (board[y0_4 + i - 1][x0_4 + j - 1] == true)
							flag4++;
					}
				}
			if (flag4 == 18)
				return true;
			else
				return false;
		}
		else
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 6; j++)
				{
					if (x0_4 + j <= 0 || x0_4 + j >= 11 || y0_4 + i <= 0 || y0_4 + i >= 11)
					{
						flag4++;
						continue;
					}
					else
					{
						if (board[y0_4 + i - 1][x0_4 + j - 1] == true)
							flag4++;
					}
				}
			if (flag4 == 18)
				return true;
			else
				return false;
		}
	}
};
class PlayerUser : public PlayerSeaBattle
{
public:
	static int number_ship; //переменная, считающая корабли
	static bool number_position;//переменная, отвечающая за положение корабля(вертикально, горизонтально)
	PlayerUser() : PlayerSeaBattle() {} //конструктор
	ship_1 & ReturnShipFromPc_1(int x, int y)//вернуть однопалубный корабль у компьютера
	{
		for (int i = 0; i < 4; i++)
			if (one_deck_pc[i].x1_ship1 == x && one_deck_pc[i].y1_ship1 == y)
				return one_deck_pc[i];
		return one_deck_pc[0];
	}
	ship_2 & ReturnShipFromPc_2(int x, int y)//вернуть двухпалубный корабль у компьютера
	{
		for (int j = 0; j < 3; j++)
			if ((two_deck_pc[j].x1_ship2 == x && two_deck_pc[j].y1_ship2 == y) || (two_deck_pc[j].x2_ship2 == x && two_deck_pc[j].y2_ship2 == y))
				return two_deck_pc[j];
		return two_deck[0];
	}
	ship_3 & ReturnShipFromPc_3(int x, int y)//вернуть трехпалубный корабль у компьютера
	{
		for (int j = 0; j < 2; j++)
			if ((three_deck_pc[j].x1_ship3 == x && three_deck_pc[j].y1_ship3 == y) || (three_deck_pc[j].x2_ship3 == x && three_deck_pc[j].y2_ship3 == y) || (three_deck_pc[j].x3_ship3 == x && three_deck_pc[j].y3_ship3 == y))
				return three_deck_pc[j];
		return three_deck_pc[0];
	}
	int InfShipFromPc(int x, int y) // узнать, в какой корабль у компьютера попала пуля.
	{
		for (int i = 0; i < 4; i++)
			if (one_deck_pc[i].x1_ship1 == x &&one_deck_pc[i].y1_ship1 == y)
				return 1;
		for (int j = 0; j < 3; j++)
			if ((two_deck_pc[j].x1_ship2 == x && two_deck_pc[j].y1_ship2 == y) || (two_deck_pc[j].x2_ship2 == x &&two_deck_pc[j].y2_ship2 == y))
				return 2;
		for (int j = 0; j < 2; j++)
			if ((three_deck_pc[j].x1_ship3 == x && three_deck_pc[j].y1_ship3 == y) || (three_deck_pc[j].x2_ship3 == x && three_deck_pc[j].y2_ship3 == y) || (three_deck_pc[j].x3_ship3 == x && three_deck_pc[j].y3_ship3 == y))
				return 3;
		return 4;
	}
	int GetAttackOnPc(int x, int y, vector<vector<int>> & v_enemy) // атака по компьютеру
	{
		if (board_enemy[y - 1][x - 1] == true)
			return 0;
		else
		{
			if (InfShipFromPc(x, y) == 1)
			{
				ReturnShipFromPc_1(x, y).transformation1(v_enemy);
				v_enemy[y - 1][x - 1] = 2;
				return 2;
			}
			else if (InfShipFromPc(x, y) == 2)
			{
				ReturnShipFromPc_2(x, y).testen_two--;
				if (ReturnShipFromPc_2(x, y).testen_two == 0)
				{
					ReturnShipFromPc_2(x, y).transformation2(v_enemy);
					v_enemy[y - 1][x - 1] = 2;
					return 2;
				}
				else
				{
					v_enemy[y - 1][x - 1] = 2;
					return 1;
				}
			}
			else if (InfShipFromPc(x, y) == 3)
			{
				ReturnShipFromPc_3(x, y).testen_three--;
				if (ReturnShipFromPc_3(x, y).testen_three == 0)
				{
					ReturnShipFromPc_3(x, y).transformation3(v_enemy);
					v_enemy[y - 1][x - 1] = 2;
					return 2;
				}
				else
				{
					v_enemy[y - 1][x - 1] = 2;
					return 1;
				}
			}
			else if (InfShipFromPc(x, y) == 4)
			{
				four_deck_pc.testen_four--;
				if (four_deck_pc.testen_four == 0)
				{
					four_deck_pc.transformation4(v_enemy);
					v_enemy[y - 1][x - 1] = 2;
					return 2;
				}
				else
				{
					v_enemy[y - 1][x - 1] = 2;
					return 1;
				}
			}
		}
		return -1;
	}
	void InitializeShip(int & x, int & y) //инициализировать корабли пользователя.
	{
		if (number_ship < 4)
		{
			cout << "  ";
			for (int i = 0; i < 10; i++)
				cout << i + 1 << " ";
			cout << endl;
			for (int j = 0; j < 10; j++)
			{
				cout << j + 1;
				for (int k = 0; k < 20; k++)
				{
					if (j == 9)
					{
						if (k % 2 == 0 && k / 2 + 1 == x && j + 1 == y)
							cout << "+";
						else if (k % 2 == 0 && board[j][k / 2] == false)
							cout << "*";
						else
							putchar(' ');
					}
					else
					{
						if (k % 2 == 1 && k / 2 + 1 == x && j + 1 == y)
							cout << "+";
						else if (k % 2 == 1 && board[j][k / 2] == false)
							cout << "*";
						else
							putchar(' ');
					}
				}
				cout << endl;
			}
		}
		else if (number_ship >= 4 && number_ship < 7)
		{
			if (!number_position)
			{
				cout << "  ";
				for (int i = 0; i < 10; i++)
					cout << i + 1 << " ";
				cout << endl;
				for (int j = 0; j < 10; j++)
				{
					cout << j + 1;
					for (int k = 0; k < 20; k++)
					{
						if (j == 9)
						{
							if (k % 2 == 0 && k / 2 + 1 == x && j + 1 == y)
								cout << "+";
							else if (k % 2 == 0 && k / 2 + 1 == x + 1 && j + 1 == y)
								cout << "+";
							else if (k % 2 == 0 && board[j][k / 2] == false)
								cout << "*";
							else
								putchar(' ');
						}
						else
						{
							if (k % 2 == 1 && k / 2 + 1 == x && j + 1 == y)
								cout << "+";
							else if (k % 2 == 1 && k / 2 + 1 == x + 1 && j + 1 == y)
								cout << "+";
							else if (k % 2 == 1 && board[j][k / 2] == false)
								cout << "*";
							else
								putchar(' ');
						}
					}
					cout << endl;
				}
			}
			else
			{
				cout << "  ";
				for (int i = 0; i < 10; i++)
					cout << i + 1 << " ";
				cout << endl;
				for (int j = 0; j < 10; j++)
				{
					cout << j + 1;
					for (int k = 0; k < 20; k++)
					{
						if (j == 9)
						{
							if (k % 2 == 0 && k / 2 + 1 == x && j + 1 == y)
								cout << "+";
							else if (k % 2 == 0 && k / 2 + 1 == x && j + 1 == y + 1)
								cout << "+";
							else if (k % 2 == 0 && board[j][k / 2] == false)
								cout << "*";
							else
								putchar(' ');
						}
						else
						{
							if (k % 2 == 1 && k / 2 + 1 == x && j + 1 == y)
								cout << "+";
							else if (k % 2 == 1 && k / 2 + 1 == x && j + 1 == y + 1)
								cout << "+";
							else if (k % 2 == 1 && board[j][k / 2] == false)
								cout << "*";
							else
								putchar(' ');
						}
					}
					cout << endl;
				}
			}
		}
		else if (number_ship >= 7 && number_ship < 9)
		{
			if (!number_position)
			{
				cout << "  ";
				for (int i = 0; i < 10; i++)
					cout << i + 1 << " ";
				cout << endl;
				for (int j = 0; j < 10; j++)
				{
					cout << j + 1;
					for (int k = 0; k < 20; k++)
					{
						if (j == 9)
						{
							if (k % 2 == 0 && k / 2 + 1 == x && j + 1 == y)
								cout << "+";
							else if (k % 2 == 0 && k / 2 + 1 == x + 1 && j + 1 == y)
								cout << "+";
							else if (k % 2 == 0 && k / 2 + 1 == x + 2 && j + 1 == y)
								cout << "+";
							else if (k % 2 == 0 && board[j][k / 2] == false)
								cout << "*";
							else
								putchar(' ');
						}
						else
						{
							if (k % 2 == 1 && k / 2 + 1 == x && j + 1 == y)
								cout << "+";
							else if (k % 2 == 1 && k / 2 + 1 == x + 1 && j + 1 == y)
								cout << "+";
							else if (k % 2 == 1 && k / 2 + 1 == x + 2 && j + 1 == y)
								cout << "+";
							else if (k % 2 == 1 && board[j][k / 2] == false)
								cout << "*";
							else
								putchar(' ');
						}
					}
					cout << endl;
				}
			}
			else
			{
				cout << "  ";
				for (int i = 0; i < 10; i++)
					cout << i + 1 << " ";
				cout << endl;
				for (int j = 0; j < 10; j++)
				{
					cout << j + 1;
					for (int k = 0; k < 20; k++)
					{
						if (j == 9)
						{
							if (k % 2 == 0 && k / 2 + 1 == x && j + 1 == y)
								cout << "+";
							else if (k % 2 == 0 && k / 2 + 1 == x && j + 1 == y + 1)
								cout << "+";
							else if (k % 2 == 0 && k / 2 + 1 == x && j + 1 == y + 2)
								cout << "+";
							else if (k % 2 == 0 && board[j][k / 2] == false)
								cout << "*";
							else
								putchar(' ');
						}
						else
						{
							if (k % 2 == 1 && k / 2 + 1 == x && j + 1 == y)
								cout << "+";
							else if (k % 2 == 1 && k / 2 + 1 == x && j + 1 == y + 1)
								cout << "+";
							else if (k % 2 == 1 && k / 2 + 1 == x && j + 1 == y + 2)
								cout << "+";
							else if (k % 2 == 1 && board[j][k / 2] == false)
								cout << "*";
							else
								putchar(' ');
						}
					}
					cout << endl;
				}
			}
		}
		else if (number_ship == 9)
		{
			if (!number_position)
			{
				cout << "  ";
				for (int i = 0; i < 10; i++)
					cout << i + 1 << " ";
				cout << endl;
				for (int j = 0; j < 10; j++)
				{
					cout << j + 1;
					for (int k = 0; k < 20; k++)
					{
						if (j == 9)
						{
							if (k % 2 == 0 && k / 2 + 1 == x && j + 1 == y)
								cout << "+";
							else if (k % 2 == 0 && k / 2 + 1 == x + 1 && j + 1 == y)
								cout << "+";
							else if (k % 2 == 0 && k / 2 + 1 == x + 2 && j + 1 == y)
								cout << "+";
							else if (k % 2 == 0 && k / 2 + 1 == x + 3 && j + 1 == y)
								cout << "+";
							else if (k % 2 == 0 && board[j][k / 2] == false)
								cout << "*";
							else
								putchar(' ');
						}
						else
						{
							if (k % 2 == 1 && k / 2 + 1 == x && j + 1 == y)
								cout << "+";
							else if (k % 2 == 1 && k / 2 + 1 == x + 1 && j + 1 == y)
								cout << "+";
							else if (k % 2 == 1 && k / 2 + 1 == x + 2 && j + 1 == y)
								cout << "+";
							else if (k % 2 == 1 && k / 2 + 1 == x + 3 && j + 1 == y)
								cout << "+";
							else if (k % 2 == 1 && board[j][k / 2] == false)
								cout << "*";
							else
								putchar(' ');
						}
					}
					cout << endl;
				}
			}
			else
			{
				cout << "  ";
				for (int i = 0; i < 10; i++)
					cout << i + 1 << " ";
				cout << endl;
				for (int j = 0; j < 10; j++)
				{
					cout << j + 1;
					for (int k = 0; k < 20; k++)
					{
						if (j == 9)
						{
							if (k % 2 == 0 && k / 2 + 1 == x && j + 1 == y)
								cout << "+";
							else if (k % 2 == 0 && k / 2 + 1 == x && j + 1 == y + 1)
								cout << "+";
							else if (k % 2 == 0 && k / 2 + 1 == x && j + 1 == y + 2)
								cout << "+";
							else if (k % 2 == 0 && k / 2 + 1 == x && j + 1 == y + 3)
								cout << "+";
							else if (k % 2 == 0 && board[j][k / 2] == false)
								cout << "*";
							else
								putchar(' ');
						}
						else
						{
							if (k % 2 == 1 && k / 2 + 1 == x && j + 1 == y)
								cout << "+";
							else if (k % 2 == 1 && k / 2 + 1 == x && j + 1 == y + 1)
								cout << "+";
							else if (k % 2 == 1 && k / 2 + 1 == x && j + 1 == y + 2)
								cout << "+";
							else if (k % 2 == 1 && k / 2 + 1 == x && j + 1 == y + 3)
								cout << "+";
							else if (k % 2 == 1 && board[j][k / 2] == false)
								cout << "*";
							else
								putchar(' ');
						}
					}
					cout << endl;
				}
			}
		}
		switch (_getch())
		{
		case 'a':
		{
			if (x > 1)
				x--;
			break;
		}
		case 'w':
		{
			if (y > 1)
				y--;
			break;
		}
		case 'd':
		{
			if (number_ship < 4)
			{
				if (x < 10)
					x++;
				break;
			}
			else if (number_ship >= 4 && number_ship < 7)
			{
				if (!number_position)
				{
					if (x < 9)
						x++;
					break;
				}
				else
				{
					if (x < 10)
						x++;
					break;
				}
			}
			else if (number_ship >= 7 && number_ship < 9)
			{
				if (!number_position)
				{
					if (x < 8)
						x++;
					break;
				}
				else
				{
					if (x < 10)
						x++;
					break;
				}
			}
			else if (number_ship == 9)
			{
				if (!number_position)
				{
					if (x < 7)
						x++;
					break;
				}
				else
				{
					if (x < 10)
						x++;
					break;
				}
			}
		}
		case 's':
		{
			if (number_ship < 4)
			{
				if (y < 10)
					y++;
				break;
			}
			else if (number_ship >= 4 && number_ship < 7)
			{
				if (!number_position)
				{
					if (y < 10)
						y++;
					break;
				}
				else
				{
					if (y < 9)
						y++;
					break;
				}
			}
			else if (number_ship >= 7 && number_ship < 9)
			{
				if (!number_position)
				{
					if (y < 10)
						y++;
					break;
				}
				else
				{
					if (y < 8)
						y++;
					break;
				}
			}
			else if (number_ship == 9)
			{
				if (!number_position)
				{
					if (y < 10)
						y++;
					break;
				}
				else
				{
					if (y < 7)
						y++;
					break;
				}
			}
		}
		case 13:
		{
			if (number_ship < 4)
			{
				ship_1 s1(x, y);
				if ((*this).CheckShip1(s1))
				{
					board[y - 1][x - 1] = false;
					one_deck.push_back(s1);
					one_deck_use.push_back(s1);
					number_ship++;
				}
				break;
			}
			else if (number_ship >= 4 && number_ship < 7)
			{
				if (!number_position)
				{
					ship_2 s2(x, y, false);
					if ((*this).CheckShip2(s2))
					{
						board[y - 1][x - 1] = false;
						board[y - 1][x] = false;
						two_deck.push_back(s2);
						two_deck_use.push_back(s2);
						number_ship++;
					}
					break;
				}
				else
				{
					ship_2 s2(x, y, true);
					if ((*this).CheckShip2(s2))
					{
						board[y - 1][x - 1] = false;
						board[y][x - 1] = false;
						two_deck.push_back(s2);
						two_deck_use.push_back(s2);
						number_ship++;
					}
					break;
				}
			}
			else if (number_ship >= 7 && number_ship < 9)
			{
				if (!number_position)
				{
					ship_3 s3(x, y, false);
					if ((*this).CheckShip3(s3))
					{
						board[y - 1][x - 1] = false;
						board[y - 1][x] = false;
						board[y - 1][x + 1] = false;
						three_deck.push_back(s3);
						three_deck_use.push_back(s3);
						number_ship++;
					}
					break;
				}
				else
				{
					ship_3 s3(x, y, true);
					if ((*this).CheckShip3(s3))
					{
						board[y - 1][x - 1] = false;
						board[y][x - 1] = false;
						board[y + 1][x - 1] = false;
						three_deck.push_back(s3);
						three_deck_use.push_back(s3);
						number_ship++;
					}
					break;
				}
			}
			else if (number_ship == 9)
			{
				if (!number_position)
				{
					ship_4 s4(x, y, false);
					if ((*this).CheckShip4(s4))
					{
						board[y - 1][x - 1] = false;
						board[y - 1][x] = false;
						board[y - 1][x + 1] = false;
						board[y - 1][x + 2] = false;
						four_deck = s4;
						four_deck_use = s4;
						number_ship++;
					}
					break;
				}
				else
				{
					ship_4 s4(x, y, true);
					if ((*this).CheckShip4(s4))
					{
						board[y - 1][x - 1] = false;
						board[y][x - 1] = false;
						board[y + 1][x - 1] = false;
						board[y + 2][x - 1] = false;
						four_deck = s4;
						four_deck_use = s4;
						number_ship++;
					}
					break;
				}
			}
		}
		case ' ':
		{
			if (number_ship >= 4 && number_ship < 7)
			{
				if (x != 10 && y != 10)
				{
					if (!number_position)
						number_position = true;
					else
						number_position = false;
				}
				break;
			}
			else if (number_ship >= 7 && number_ship < 9)
			{
				if (x < 9 && y < 9)
				{
					if (!number_position)
						number_position = true;
					else
						number_position = false;
				}
				break;
			}
			else if (number_ship == 9)
			{
				if (x < 8 && y < 8)
				{
					if (!number_position)
						number_position = true;
					else
						number_position = false;
				}
				break;
			}
		}
		}
	}
	void DrawBoard(int & x, int & y, vector<vector<int>> & pc_attack, vector<vector<int>> & v_attack) //нарисовать доску пользователя и вспомагательную карту врага
	{
		cout << "  ";
		for (int i = 0; i < 22; i++)
		{
			if (i < 10)
				cout << i + 1 << " ";
			else if (i == 10 || i == 11)
				cout << "   ";
			else
				cout << " " << i - 11;
		}
		cout << endl;
		for (int j = 0; j < 10; j++)
		{
			cout << j + 1;
			for (int k = 0; k < 48; k++)
			{
				if (j == 9)
				{
					if (k == 47)
						break;
					if (k < 19)
					{
						if (k % 2 == 0 && pc_attack[j][k / 2] == 2)
							cout << "@";
						else if (k % 2 == 0 && board[j][k / 2] == false)
							cout << "*";
						else if (k % 2 == 0 && pc_attack[j][k / 2] == 1)
							cout << "-";
						else
							putchar(' ');
					}
					else if (k >= 19 && k < 27)
					{
						if (k == 26)
							cout << j + 1;
						else
							putchar(' ');
					}
					else
					{
						if (k % 2 == 1 && k / 2 - 12 == x && j + 1 == y)
							cout << "+";
						else if (k % 2 == 1 && v_attack[j][k / 2 - 13] == 1)
							cout << "-";
						else if (k % 2 == 1 && v_attack[j][k / 2 - 13] == 2)
							cout << "@";
						else
							putchar(' ');
					}
				}
				else
				{
					if (k <= 19)
					{
						if (k % 2 == 1 && pc_attack[j][k / 2] == 2)
							cout << "@";
						else if (k % 2 == 1 && board[j][k / 2] == false)
							cout << "*";
						else if (k % 2 == 1 && pc_attack[j][k / 2] == 1)
							cout << "-";
						else
							putchar(' ');
					}
					else if (k > 19 && k < 28)
					{
						if (k == 27)
							cout << j + 1;
						else
							putchar(' ');
					}
					else
					{
						if (k % 2 == 1 && k / 2 - 13 == x && j + 1 == y)
							cout << "+";
						else if (k % 2 == 1 && v_attack[j][k / 2 - 14] == 1)
							cout << "-";
						else if (k % 2 == 1 && v_attack[j][k / 2 - 14] == 2)
							cout << "@";
						else
							putchar(' ');
					}
				}
			}
			cout << endl;
		}
	}
	int AttackUser(int & x, int & y, vector<vector<int>> & pc_attack, vector<vector<int>> & v_attack) //атака по компьютеру
	{
		int number, m;
		switch (_getch())
		{
		case 'a':
		{
			if (x > 1)
				x--;
			return -1;
			break;
		}
		case 'w':
		{
			if (y > 1)
				y--;
			return -1;
			break;
		}
		case 'd':
		{
			if (x < 10)
				x++;
			return -1;
			break;
		}
		case 's':
		{
			if (y < 10)
				y++;
			return -1;
			break;
		}
		case 13:
		{
			if (v_attack[y - 1][x - 1] == 1 || v_attack[y - 1][x - 1] == 2)
				return -1;
			else
			{
				number = GetAttackOnPc(x, y, v_attack);
				if (number == 0)
				{
					v_attack[y - 1][x - 1] = 1;
					return 0;
					break;
				}
				else if (number == 1)
				{
					return 1;
					break;
				}
				else
				{
					m = InfShipFromPc(x, y);
					if (m == 1)
						number_1_pc--;
					else if (m == 2)
						number_2_pc--;
					else if (m == 3)
						number_3_pc--;
					else
						number_4_pc--;
					return 2;
					break;
				}
			}
		}
		default:
		{
			return -1;
			break;
		}
		}
	}
	bool GameOverUse()
	{
		if (number_1_use == 0 && number_2_use == 0 && number_3_use == 0 && number_4_use == 0)
			return false;
		else
			return true;
	}
};
class PlayerComputer : public PlayerSeaBattle
{
public:
	static int temp;
	static int control;
	static int deck;
	static int qwerty;
	bool InitializeShipComputer() //инициализировать корабли у компьютера
	{
		one_deck.clear();
		two_deck.clear();
		three_deck.clear();
		one_deck_pc.clear();
		two_deck_pc.clear();
		three_deck_pc.clear();
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				board[i][j] = true;
		srand(int(time(0)));
		int random_x = 0;
		int random_y = 0;
		int random_pos;
		for (int i = 0; i < 4; i++) // для однопалубных
		{
			random_x = rand() % 10 + 1;
			random_y = rand() % 10 + 1;
			if (i == 0)
			{
				ship_1 s(random_x, random_y);
				one_deck.push_back(s);
				one_deck_pc.push_back(s);
				board[random_y - 1][random_x - 1] = false;
			}
			else
			{
				ship_1 s(random_x, random_y);
				if (!CheckShip1(s))
				{
					while (!CheckShip1(s))
					{
						random_x = rand() % 10 + 1;
						random_y = rand() % 10 + 1;
						s.change(random_x, random_y);
					}
				}
				one_deck.push_back(s);
				one_deck_pc.push_back(s);
				board[random_y - 1][random_x - 1] = false;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			random_pos = rand() % 2;
			if (random_pos == 0)
			{
				random_x = rand() % 9 + 1;
				random_y = rand() % 10 + 1;
				ship_2 s(random_x, random_y, false);
				if (!CheckShip2(s))
				{
					while (!CheckShip2(s))
					{
						random_x = rand() % 9 + 1;
						random_y = rand() % 10 + 1;
						s.change(random_x, random_y);
					}
				}
				two_deck.push_back(s);
				two_deck_pc.push_back(s);
				board[random_y - 1][random_x - 1] = false;
				board[random_y - 1][random_x] = false;
			}
			else
			{
				random_x = rand() % 10 + 1;
				random_y = rand() % 9 + 1;
				ship_2 s(random_x, random_y, true);
				if (!CheckShip2(s))
				{
					while (!CheckShip2(s))
					{
						random_x = rand() % 10 + 1;
						random_y = rand() % 9 + 1;
						s.change(random_x, random_y);
					}
				}
				two_deck.push_back(s);
				two_deck_pc.push_back(s);
				board[random_y - 1][random_x - 1] = false;
				board[random_y][random_x - 1] = false;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			random_pos = rand() % 2;
			if (random_pos == 0)
			{
				random_x = rand() % 8 + 1;
				random_y = rand() % 10 + 1;
				ship_3 s(random_x, random_y, false);
				if (!CheckShip3(s))
				{
					while (!CheckShip3(s))
					{
						random_x = rand() % 8 + 1;
						random_y = rand() % 10 + 1;
						s.change(random_x, random_y);
						temp++;
						if (temp == 10)
							return false;
					}
				}
				three_deck.push_back(s);
				three_deck_pc.push_back(s);
				board[random_y - 1][random_x - 1] = false;
				board[random_y - 1][random_x] = false;
				board[random_y - 1][random_x + 1] = false;
			}
			else
			{
				random_x = rand() % 10 + 1;
				random_y = rand() % 8 + 1;
				ship_3 s(random_x, random_y, true);
				if (!CheckShip3(s))
				{
					while (!CheckShip3(s))
					{
						random_x = rand() % 10 + 1;
						random_y = rand() % 8 + 1;
						s.change(random_x, random_y);
						temp++;
						if (temp == 10)
							return false;
					}
				}
				three_deck.push_back(s);
				three_deck_pc.push_back(s);
				board[random_y - 1][random_x - 1] = false;
				board[random_y][random_x - 1] = false;
				board[random_y + 1][random_x - 1] = false;
			}
		}
		random_pos = rand() % 2;
		if (random_pos == 0)
		{
			random_x = rand() % 7 + 1;
			random_y = rand() % 10 + 1;
			ship_4 s(random_x, random_y, false);
			if (!CheckShip4(s))
			{
				while (!CheckShip4(s))
				{
					random_x = rand() % 7 + 1;
					random_y = rand() % 10 + 1;
					s.change(random_x, random_y);
					temp++;
					if (temp == 10)
						return false;
				}
			}
			four_deck = s;
			four_deck_pc = s;
			board[random_y - 1][random_x - 1] = false;
			board[random_y - 1][random_x] = false;
			board[random_y - 1][random_x + 1] = false;
			board[random_y - 1][random_x + 2] = false;
		}
		else
		{
			random_x = rand() % 10 + 1;
			random_y = rand() % 7 + 1;
			ship_4 s(random_x, random_y, true);
			if (!CheckShip4(s))
			{
				while (!CheckShip4(s))
				{
					random_x = rand() % 10 + 1;
					random_y = rand() % 7 + 1;
					s.change(random_x, random_y);
					temp++;
					if (temp == 10)
						return false;
				}
			}
			four_deck = s;
			four_deck_pc = s;
			board[random_y - 1][random_x - 1] = false;
			board[random_y][random_x - 1] = false;
			board[random_y + 1][random_x - 1] = false;
			board[random_y + 2][random_x - 1] = false;
		}
		return true;
	}
	vector<int> ReturnCoordinate(int x, int y) //вернуть координату
	{
		vector<int> v;
		for (int i = 0; i < 4; i++)
			if (one_deck_use[i].x1_ship1 == x && one_deck_use[i].y1_ship1 == y)
			{
				v.push_back(x);
				v.push_back(y);
				return v;
			}
		for (int j = 0; j < 3; j++)
			if ((two_deck_use[j].x1_ship2 == x && two_deck_use[j].y1_ship2 == y) || (two_deck_use[j].x2_ship2 == x && two_deck_use[j].y2_ship2 == y))
			{
				v.push_back(x);
				v.push_back(y);
				return v;
			}
		for (int j = 0; j < 2; j++)
			if ((three_deck_use[j].x1_ship3 == x && three_deck_use[j].y1_ship3 == y) || (three_deck_use[j].x2_ship3 == x && three_deck_use[j].y2_ship3 == y) || (three_deck_use[j].x3_ship3 == x && three_deck_use[j].y3_ship3 == y))
			{
				v.push_back(x);
				v.push_back(y);
				return v;
			}
		if (four_deck_use.x1_ship4 == x && four_deck_use.y1_ship4 == y)
		{
			v.push_back(x);
			v.push_back(y);
			return v;
		}
		if (four_deck_use.x2_ship4 == x && four_deck_use.y2_ship4 == y)
		{
			v.push_back(x);
			v.push_back(y);
			return v;
		}
		if (four_deck_use.x3_ship4 == x && four_deck_use.y3_ship4 == y)
		{
			v.push_back(x);
			v.push_back(y);
			return v;
		}
		if (four_deck_use.x4_ship4 == x && four_deck_use.y4_ship4 == y)
		{
			v.push_back(x);
			v.push_back(y);
			return v;
		}
		return v;
	}
	ship_1 & ReturnShipFromUs_1(int x, int y) //вернуть однопалубный корабль у пользователя
	{
		for (int i = 0; i < 4; i++)
			if (one_deck_use[i].x1_ship1 == x && one_deck_use[i].y1_ship1 == y)
				return one_deck_use[i];
		return one_deck_use[0];
	}
	ship_2 & ReturnShipFromUs_2(int x, int y)//вернуть двухпалубный корабль у пользователя
	{
		for (int j = 0; j < 3; j++)
			if ((two_deck_use[j].x1_ship2 == x && two_deck_use[j].y1_ship2 == y) || (two_deck_use[j].x2_ship2 == x && two_deck_use[j].y2_ship2 == y))
				return two_deck_use[j];
		return two_deck_use[0];
	}
	ship_3 & ReturnShipFromUs_3(int x, int y)//вернуть трехпалубный корабль у пользователя
	{
		for (int j = 0; j < 2; j++)
			if ((three_deck_use[j].x1_ship3 == x && three_deck_use[j].y1_ship3 == y) || (three_deck_use[j].x2_ship3 == x && three_deck_use[j].y2_ship3 == y) || (three_deck_use[j].x3_ship3 == x && three_deck_use[j].y3_ship3 == y))
				return three_deck_use[j];
		return three_deck_use[0];
	}
	int InfShipFromUs(int x, int y) // узнать, в какой корабль  у пользователя попала пуля.
	{
		for (int i = 0; i < 4; i++)
			if (one_deck_use[i].x1_ship1 == x && one_deck_use[i].y1_ship1 == y)
				return 1;
		for (int j = 0; j < 3; j++)
			if ((two_deck_use[j].x1_ship2 == x && two_deck_use[j].y1_ship2 == y) || (two_deck_use[j].x2_ship2 == x && two_deck_use[j].y2_ship2 == y))
				return 2;
		for (int j = 0; j < 2; j++)
			if ((three_deck_use[j].x1_ship3 == x && three_deck_use[j].y1_ship3 == y) || (three_deck_use[j].x2_ship3 == x && three_deck_use[j].y2_ship3 == y) || (three_deck_use[j].x3_ship3 == x && three_deck_use[j].y3_ship3 == y))
				return 3;
		return 4;
	}
	int GetAttackOnUs(int x, int y, vector<vector<int>> & v_enemy) //атака по пользователю
	{
		if (board_enemy[y - 1][x - 1] == true)
		{
			v_enemy[y - 1][x - 1] = 1;
			return 0;
		}
		else
		{
			if (InfShipFromUs(x, y) == 1)
			{
				ReturnShipFromUs_1(x, y).transformation1(v_enemy);
				v_enemy[y - 1][x - 1] = 2;
				return 2;
			}
			else if (InfShipFromUs(x, y) == 2)
			{
				ReturnShipFromUs_2(x, y).testen_two--;
				if (ReturnShipFromUs_2(x, y).testen_two == 0)
				{
					ReturnShipFromUs_2(x, y).transformation2(v_enemy);
					v_enemy[y - 1][x - 1] = 2;
					return 2;
				}
				else
				{
					v_enemy[y - 1][x - 1] = 2;
					return 1;
				}
			}
			else if (InfShipFromUs(x, y) == 3)
			{
				ReturnShipFromUs_3(x, y).testen_three--;
				if (ReturnShipFromUs_3(x, y).testen_three == 0)
				{
					ReturnShipFromUs_3(x, y).transformation3(v_enemy);
					v_enemy[y - 1][x - 1] = 2;
					return 2;
				}
				else
				{
					v_enemy[y - 1][x - 1] = 2;
					return 1;
				}
			}
			else if (InfShipFromUs(x, y) == 4)
			{
				four_deck_use.testen_four--;
				if (four_deck_use.testen_four == 0)
				{
					four_deck_use.transformation4(v_enemy);
					v_enemy[y - 1][x - 1] = 2;
					return 2;
				}
				else
				{
					v_enemy[y - 1][x - 1] = 2;
					return 1;
				}
			}
		}
		return -1;
	}
	bool Shoot(int x, int y, vector<vector<int>> & v_enemy) // проверка координаты
	{
		if (v_enemy[y - 1][x - 1] == 0)
			return true;
		else
			return false;
	}
	int AttackComputer(vector<int> & x_vec, vector<int> & y_vec, vector<vector<int>> & v_enemy) //атака по пользователю
	{
		srand(int(time(0)));
		int x, y, r, r_copy, w, k;
		if (x_vec.size() < 1)
		{
			x = rand() % 10 + 1;
			y = rand() % 10 + 1;
			w = GetAttackOnUs(x, y, v_enemy);
			if (w == 0)
				return 0;
			else if (w == 1)
			{
				x_vec.push_back(x);
				y_vec.push_back(y);
				control = 1;
				return 1;
			}
			else
			{
				number_1_use--;
				return 2;
			}
		}
		else
		{
			if (control == 0)
			{
				x = rand() % 10 + 1;
				y = rand() % 10 + 1;
				if (!Shoot(x, y, v_enemy))
				{
					while (!Shoot(x, y, v_enemy))
					{
						x = rand() % 10 + 1;
						y = rand() % 10 + 1;
					}
				}
				w = GetAttackOnUs(x, y, v_enemy);
				if (w == 0)
					return 0;
				else if (w == 1)
				{
					x_vec.push_back(x);
					y_vec.push_back(y);
					control = 1;
					return 1;
				}
				else
				{
					number_1_use--;
					return 2;
				}
			}
			else if (control == 1)
			{
				r = rand() % 4 + 1;
				while (r == 1 || r == 2 || r == 3 || r == 4)
				{
					if (r == 1)
					{
						x = x_vec.back() - 1;
						y = y_vec.back();
						if (correctly(x, y) && Shoot(x, y, v_enemy))
						{
							w = GetAttackOnUs(x, y, v_enemy);
							if (w == 0)
								return 0;
							else if (w == 1)
							{
								x_vec.push_back(x);
								y_vec.push_back(y);
								control = 2;
								return 1;
							}
							else
							{
								number_2_use--;
								control = 0;
								return 2;
							}
						}
						else
						{
							r_copy = r;
							r = rand() % 4 + 1;
							if (r_copy == r)
							{
								while (r_copy == r)
								{
									r = rand() % 4 + 1;
								}
							}
						}
					}
					else if (r == 2)
					{
						x = x_vec.back() + 1;
						y = y_vec.back();
						if (correctly(x, y) && Shoot(x, y, v_enemy))
						{
							w = GetAttackOnUs(x, y, v_enemy);
							if (w == 0)
								return 0;
							else if (w == 1)
							{
								x_vec.push_back(x);
								y_vec.push_back(y);
								control = 2;
								return 1;
							}
							else
							{
								number_2_use--;
								control = 0;
								return 2;
							}
						}
						else
						{
							r_copy = r;
							r = rand() % 4 + 1;
							if (r_copy == r)
							{
								while (r_copy == r)
								{
									r = rand() % 4 + 1;
								}
							}
						}
					}
					else if (r == 3)
					{
						x = x_vec.back();
						y = y_vec.back() - 1;
						if (correctly(x, y) && Shoot(x, y, v_enemy))
						{
							w = GetAttackOnUs(x, y, v_enemy);
							if (w == 0)
								return 0;
							else if (w == 1)
							{
								x_vec.push_back(x);
								y_vec.push_back(y);
								control = 2;
								return 1;
							}
							else
							{
								number_2_use--;
								control = 0;
								return 2;
							}
						}
						else
						{
							r_copy = r;
							r = rand() % 4 + 1;
							if (r_copy == r)
							{
								while (r_copy == r)
								{
									r = rand() % 4 + 1;
								}
							}
						}
					}
					else
					{
						x = x_vec.back();
						y = y_vec.back() + 1;
						if (correctly(x, y) && Shoot(x, y, v_enemy))
						{
							w = GetAttackOnUs(x, y, v_enemy);
							if (w == 0)
								return 0;
							else if (w == 1)
							{
								x_vec.push_back(x);
								y_vec.push_back(y);
								control = 2;
								return 1;
							}
							else
							{
								number_2_use--;
								control = 0;
								return 2;
							}
						}
						else
						{
							r_copy = r;
							r = rand() % 4 + 1;
							if (r_copy == r)
							{
								while (r_copy == r)
								{
									r = rand() % 4 + 1;
								}
							}
						}
					}
				}
			}
			else if (control == 2)
			{
				r = rand() % 2 + 1;
				while (r == 1 || r == 2)
				{
					if (deck > 5)
					{
						r = rand() % 4 + 1;
						while (r == 1 || r == 2 || r == 3 || r == 4)
						{
							if (r == 1)
							{
								k = InfShipFromUs(x_vec.back(), y_vec.back());
								if (k == 3)
								{
									x = ReturnShipFromUs_3(x_vec.back(), y_vec.back()).x1_ship3;
									y = ReturnShipFromUs_3(x_vec.back(), y_vec.back()).y1_ship3;
									if (correctly(x, y) && Shoot(x, y, v_enemy))
									{
										w = GetAttackOnUs(x, y, v_enemy);
										if (w == 0)
											return 0;
										else if (w == 1)
										{
											x_vec.push_back(x);
											y_vec.push_back(y);
											control = 3;
											return 1;
										}
										else
										{
											number_3_use--;
											control = 0;
											return 2;
										}
									}
									else
									{
										r_copy = r;
										r = rand() % 4 + 1;
										if (r_copy == r)
										{
											while (r_copy == r)
											{
												r = rand() % 4 + 1;
											}
										}
									}
								}
								else
								{
									x = four_deck_use.x1_ship4;
									y = four_deck_use.y1_ship4;
									if (correctly(x, y) && Shoot(x, y, v_enemy))
									{
										w = GetAttackOnUs(x, y, v_enemy);
										if (w == 0)
											return 0;
										else if (w == 1)
										{
											control = 3;
											return 1;
										}
										else
										{
											control = 0;
											return 2;
										}
									}
									else
									{
										r_copy = r;
										r = rand() % 4 + 1;
										if (r_copy == r)
										{
											while (r_copy == r)
											{
												r = rand() % 4 + 1;
											}
										}
									}
								}
							}
							else if (r == 2)
							{
								k = InfShipFromUs(x_vec.back(), y_vec.back());
								if (k == 3)
								{
									x = ReturnShipFromUs_3(x_vec.back(), y_vec.back()).x2_ship3;
									y = ReturnShipFromUs_3(x_vec.back(), y_vec.back()).y2_ship3;
									if (correctly(x, y) && Shoot(x, y, v_enemy))
									{
										w = GetAttackOnUs(x, y, v_enemy);
										if (w == 0)
											return 0;
										else if (w == 1)
										{
											x_vec.push_back(x);
											y_vec.push_back(y);
											control = 3;
											return 1;
										}
										else
										{
											number_3_use--;
											control = 0;
											return 2;
										}
									}
									else
									{
										r_copy = r;
										r = rand() % 4 + 1;
										if (r_copy == r)
										{
											while (r_copy == r)
											{
												r = rand() % 4 + 1;
											}
										}
									}
								}
								else
								{
									x = four_deck_use.x2_ship4;
									y = four_deck_use.y2_ship4;
									if (correctly(x, y) && Shoot(x, y, v_enemy))
									{
										w = GetAttackOnUs(x, y, v_enemy);
										if (w == 0)
											return 0;
										else if (w == 1)
										{
											control = 3;
											return 1;
										}
										else
										{
											control = 0;
											return 2;
										}
									}
									else
									{
										r_copy = r;
										r = rand() % 4 + 1;
										if (r_copy == r)
										{
											while (r_copy == r)
											{
												r = rand() % 4 + 1;
											}
										}
									}
								}
							}
							else if (r == 3)
							{
								k = InfShipFromUs(x_vec.back(), y_vec.back());
								if (k == 3)
								{
									x = ReturnShipFromUs_3(x_vec.back(), y_vec.back()).x3_ship3;
									y = ReturnShipFromUs_3(x_vec.back(), y_vec.back()).y3_ship3;
									if (correctly(x, y) && Shoot(x, y, v_enemy))
									{
										w = GetAttackOnUs(x, y, v_enemy);
										if (w == 0)
											return 0;
										else if (w == 1)
										{
											x_vec.push_back(x);
											y_vec.push_back(y);
											control = 3;
											return 1;
										}
										else
										{
											number_3_use--;
											control = 0;
											return 2;
										}
									}
									else
									{
										r_copy = r;
										r = rand() % 4 + 1;
										if (r_copy == r)
										{
											while (r_copy == r)
											{
												r = rand() % 4 + 1;
											}
										}
									}
								}
								else
								{
									x = four_deck_use.x3_ship4;
									y = four_deck_use.y3_ship4;
									if (correctly(x, y) && Shoot(x, y, v_enemy))
									{
										w = GetAttackOnUs(x, y, v_enemy);
										if (w == 0)
											return 0;
										else if (w == 1)
										{
											control = 3;
											return 1;
										}
										else
										{
											control = 0;
											return 2;
										}
									}
									else
									{
										r_copy = r;
										r = rand() % 4 + 1;
										if (r_copy == r)
										{
											while (r_copy == r)
											{
												r = rand() % 4 + 1;
											}
										}
									}
								}
							}
							else
							{
								k = InfShipFromUs(x_vec.back(), y_vec.back());
								if (k == 3)
								{
									r_copy = r;
									r = rand() % 4 + 1;
									if (r_copy == r)
									{
										while (r_copy == r)
										{
											r = rand() % 4 + 1;
										}
									}
								}
								else
								{
									x = four_deck_use.x4_ship4;
									y = four_deck_use.y4_ship4;
									if (correctly(x, y) && Shoot(x, y, v_enemy))
									{
										w = GetAttackOnUs(x, y, v_enemy);
										if (w == 0)
											return 0;
										else if (w == 1)
										{
											x_vec.push_back(x);
											y_vec.push_back(y);
											control = 3;
											return 1;
										}
										else
										{
											control = 0;
											return 2;
										}
									}
									else
									{
										r_copy = r;
										r = rand() % 4 + 1;
										if (r_copy == r)
										{
											while (r_copy == r)
											{
												r = rand() % 4 + 1;
											}
										}
									}
								}
							}
						}
					}
					else if (r == 1)
					{
						k = InfShipFromUs(x_vec.back(), y_vec.back());
						if (k == 3)
						{
							if (ReturnShipFromUs_3(x_vec.back(), y_vec.back()).position3)
							{
								x = ReturnCoordinate(x_vec.back(), y_vec.back())[0];
								y = ReturnCoordinate(x_vec.back(), y_vec.back())[1] - 1;
								if (correctly(x, y) && Shoot(x, y, v_enemy))
								{
									w = GetAttackOnUs(x, y, v_enemy);
									if (w == 0)
										return 0;
									else if (w == 1)
									{
										x_vec.push_back(x);
										y_vec.push_back(y);
										control = 2;
										return 1;
									}
									else
									{
										number_3_use--;
										control = 0;
										return 2;
									}
								}
								else
								{
									deck++;
									r = 2;
								}
							}
							else
							{
								x = ReturnCoordinate(x_vec.back(), y_vec.back())[0] - 1;
								y = ReturnCoordinate(x_vec.back(), y_vec.back())[1];
								if (correctly(x, y) && Shoot(x, y, v_enemy))
								{
									w = GetAttackOnUs(x, y, v_enemy);
									if (w == 0)
										return 0;
									else if (w == 1)
									{
										x_vec.push_back(x);
										y_vec.push_back(y);
										control = 2;
										return 1;
									}
									else
									{
										number_3_use--;
										control = 0;
										return 2;
									}
								}
								else
								{
									deck++;
									r = 2;
								}
							}
						}
						else
						{
							if (four_deck_use.position4)
							{
								x = ReturnCoordinate(x_vec.back(), y_vec.back())[0];
								y = ReturnCoordinate(x_vec.back(), y_vec.back())[1] - 1;
								if (correctly(x, y) && Shoot(x, y, v_enemy))
								{
									w = GetAttackOnUs(x, y, v_enemy);
									if (w == 0)
										return 0;
									else if (w == 1)
									{
										x_vec.push_back(x);
										y_vec.push_back(y);
										control = 3;
										return 1;
									}
									else
									{
										control = 0;
										return 2;
									}
								}
								else
									r = 2;
							}
							else
							{
								x = ReturnCoordinate(x_vec.back(), y_vec.back())[0] - 1;
								y = ReturnCoordinate(x_vec.back(), y_vec.back())[1];
								if (correctly(x, y) && Shoot(x, y, v_enemy))
								{
									w = GetAttackOnUs(x, y, v_enemy);
									if (w == 0)
										return 0;
									else if (w == 1)
									{
										x_vec.push_back(x);
										y_vec.push_back(y);
										control = 3;
										return 1;
									}
									else
									{
										control = 0;
										return 2;
									}
								}
								else
									r = 2;
							}
						}
					}
					else
					{
						k = InfShipFromUs(x_vec.back(), y_vec.back());
						if (k == 3)
						{
							if (ReturnShipFromUs_3(x_vec.back(), y_vec.back()).position3)
							{
								x = ReturnCoordinate(x_vec.back(), y_vec.back())[0];
								y = ReturnCoordinate(x_vec.back(), y_vec.back())[1] + 1;
								if (correctly(x, y) && Shoot(x, y, v_enemy))
								{
									w = GetAttackOnUs(x, y, v_enemy);
									if (w == 0)
										return 0;
									else if (w == 1)
									{
										x_vec.push_back(x);
										y_vec.push_back(y);
										control = 3;
										return 1;
									}
									else
									{
										number_3_use--;
										control = 0;
										return 2;
									}
								}
								else
								{
									deck++;
									r = 1;
								}
							}
							else
							{
								x = ReturnCoordinate(x_vec.back(), y_vec.back())[0] + 1;
								y = ReturnCoordinate(x_vec.back(), y_vec.back())[1];
								if (correctly(x, y) && Shoot(x, y, v_enemy))
								{
									w = GetAttackOnUs(x, y, v_enemy);
									if (w == 0)
										return 0;
									else if (w == 1)
									{
										x_vec.push_back(x);
										y_vec.push_back(y);
										control = 3;
										return 1;
									}
									else
									{
										number_3_use--;
										control = 0;
										return 2;
									}
								}
								else
								{
									deck++;
									r = 1;
								}
							}
						}
						else
						{
							if (four_deck_use.position4)
							{
								x = ReturnCoordinate(x_vec.back(), y_vec.back())[0];
								y = ReturnCoordinate(x_vec.back(), y_vec.back())[1] + 1;
								if (correctly(x, y) && Shoot(x, y, v_enemy))
								{
									w = GetAttackOnUs(x, y, v_enemy);
									if (w == 0)
										return 0;
									else if (w == 1)
									{
										x_vec.push_back(x);
										y_vec.push_back(y);
										control = 3;
										return 1;
									}
									else
									{
										control = 0;
										return 2;
									}
								}
								else
								{
									deck++;
									r = 1;
								}
							}
							else
							{
								x = ReturnCoordinate(x_vec.back(), y_vec.back())[0] + 1;
								y = ReturnCoordinate(x_vec.back(), y_vec.back())[1];
								if (correctly(x, y) && Shoot(x, y, v_enemy))
								{
									w = GetAttackOnUs(x, y, v_enemy);
									if (w == 0)
										return 0;
									else if (w == 1)
									{
										x_vec.push_back(x);
										y_vec.push_back(y);
										control = 3;
										return 1;
									}
									else
									{
										control = 0;
										return 2;
									}
								}
								else
								{
									deck++;
									r = 1;
								}
							}
						}
					}
				}
			}
			else // control == 3 четырехпалубный
			{
				r = rand() % 2 + 1;
				while (r == 1 || r == 2)
				{
					if (qwerty > 5)
					{
						r = rand() % 4 + 1;
						while (r == 1 || r == 2 || r == 3 || r == 4)
						{
							if (r == 1)
							{
								x = four_deck_use.x1_ship4;
								y = four_deck_use.y1_ship4;
								if (correctly(x, y) && Shoot(x, y, v_enemy))
								{
									w = GetAttackOnUs(x, y, v_enemy);
									if (w == 0)
										return 0;
									else if (w == 1)
									{
										x_vec.push_back(x);
										y_vec.push_back(y);
										control = 3;
										return 1;
									}
									else
									{
										number_4_use--;
										control = 0;
										return 2;
									}
								}
								else
								{
									r_copy = r;
									r = rand() % 4 + 1;
									if (r_copy == r)
									{
										while (r_copy == r)
										{
											r = rand() % 4 + 1;
										}
									}
								}
							}
							else if (r == 2)
							{
								x = four_deck_use.x2_ship4;
								y = four_deck_use.y2_ship4;
								if (correctly(x, y) && Shoot(x, y, v_enemy))
								{
									w = GetAttackOnUs(x, y, v_enemy);
									if (w == 0)
										return 0;
									else if (w == 1)
									{
										x_vec.push_back(x);
										y_vec.push_back(y);
										control = 3;
										return 1;
									}
									else
									{
										number_4_use--;
										control = 0;
										return 2;
									}
								}
								else
								{
									r_copy = r;
									r = rand() % 4 + 1;
									if (r_copy == r)
									{
										while (r_copy == r)
										{
											r = rand() % 4 + 1;
										}
									}
								}
							}
							else if (r == 3)
							{
								x = four_deck_use.x3_ship4;
								y = four_deck_use.y3_ship4;
								if (correctly(x, y) && Shoot(x, y, v_enemy))
								{
									w = GetAttackOnUs(x, y, v_enemy);
									if (w == 0)
										return 0;
									else if (w == 1)
									{
										x_vec.push_back(x);
										y_vec.push_back(y);
										control = 3;
										return 1;
									}
									else
									{
										number_4_use--;
										control = 0;
										return 2;
									}
								}
								else
								{
									r_copy = r;
									r = rand() % 4 + 1;
									if (r_copy == r)
									{
										while (r_copy == r)
										{
											r = rand() % 4 + 1;
										}
									}
								}
							}
							else
							{
								x = four_deck_use.x4_ship4;
								y = four_deck_use.y4_ship4;
								if (correctly(x, y) && Shoot(x, y, v_enemy))
								{
									w = GetAttackOnUs(x, y, v_enemy);
									if (w == 0)
										return 0;
									else if (w == 1)
									{
										x_vec.push_back(x);
										y_vec.push_back(y);
										control = 3;
										return 1;
									}
									else
									{
										number_4_use--;
										control = 0;
										return 2;
									}
								}
								else
								{
									r_copy = r;
									r = rand() % 4 + 1;
									if (r_copy == r)
									{
										while (r_copy == r)
										{
											r = rand() % 4 + 1;
										}
									}
								}
							}
						}
					}
					else if (r == 1)
					{
						if (four_deck_use.position4)
						{
							x = ReturnCoordinate(x_vec.back(), y_vec.back())[0];
							y = ReturnCoordinate(x_vec.back(), y_vec.back())[1] - 1;
							if (correctly(x, y) && Shoot(x, y, v_enemy))
							{
								w = GetAttackOnUs(x, y, v_enemy);
								if (w == 0)
									return 0;
								else if (w == 1)
								{
									x_vec.push_back(x);
									y_vec.push_back(y);
									control = 0;
									return 1;
								}
								else
								{
									number_4_use--;
									control = 0;
									return 2;
								}
							}
							else
							{
								qwerty++;
								r = 2;
							}
						}
						else
						{
							x = ReturnCoordinate(x_vec.back(), y_vec.back())[0] - 1;
							y = ReturnCoordinate(x_vec.back(), y_vec.back())[1];
							if (correctly(x, y) && Shoot(x, y, v_enemy))
							{
								w = GetAttackOnUs(x, y, v_enemy);
								if (w == 0)
									return 0;
								else if (w == 1)
								{
									x_vec.push_back(x);
									y_vec.push_back(y);
									control = 0;
									return 1;
								}
								else
								{
									number_4_use--;
									control = 0;
									return 2;
								}
							}
							else
							{
								qwerty++;
								r = 2;
							}
						}
					}
					else
					{
						if (four_deck_use.position4)
						{
							x = ReturnCoordinate(x_vec.back(), y_vec.back())[0];
							y = ReturnCoordinate(x_vec.back(), y_vec.back())[1] + 1;
							if (correctly(x, y) && Shoot(x, y, v_enemy))
							{
								w = GetAttackOnUs(x, y, v_enemy);
								if (w == 0)
									return 0;
								else if (w == 1)
								{
									x_vec.push_back(x);
									y_vec.push_back(y);
									control = 0;
									return 1;
								}
								else
								{
									number_4_use--;
									control = 0;
									return 2;
								}
							}
							else
							{
								qwerty++;
								r = 1;
							}
						}
						else
						{
							x = ReturnCoordinate(x_vec.back(), y_vec.back())[0] + 1;
							y = ReturnCoordinate(x_vec.back(), y_vec.back())[1];
							if (correctly(x, y) && Shoot(x, y, v_enemy))
							{
								w = GetAttackOnUs(x, y, v_enemy);
								if (w == 0)
									return 0;
								else if (w == 1)
								{
									x_vec.push_back(x);
									y_vec.push_back(y);
									control = 0;
									return 1;
								}
								else
								{
									number_4_use--;
									control = 0;
									return 2;
								}
							}
							else
							{
								qwerty++;
								r = 1;
							}
						}
					}
				}
			}
		}
		return 0;
	}
	bool GameOverPc() //проверка на конец игры
	{
		if (number_1_pc == 0 && number_2_pc == 0 && number_3_pc == 0 && number_4_pc == 0)
			return false;
		else
			return true;
	}
};
void cout_start() // функция вывода 1
{
	cout << "Инициализируйте свои корабли!\n" << endl;
	cout << "Управление курсором: a - \"влево\", w - \"вверх\", d - \"вправо\", s - \"вниз\"" << endl;
	cout << "Чтобы повернуть корабль, используйте Space." << endl;
	cout << "Чтобы установить корабль на выбранную позицию, нажмите Enter.\n" << endl;
}
void cout_end(int stat, string & s1) //функция вывода 2
{
	cout << "ИГРА НАЧАЛАСЬ!\n" << endl;
	cout << "Обозначения: \"-\" - промах, \"@\" - попадание." << endl;
	cout << "Через \"*\" обозначены Ваши корабли, в которые еще не попала пуля." << endl;
	cout << "Управление курсором: a - \"влево\", w - \"вверх\", d - \"вправо\", s - \"вниз\"" << endl;
	cout << "Чтобы атаковать выбранную координату, нажмите Enter." << endl;
	cout << "              Оставшиеся корабли:" << endl;
	cout << "Пользователь:                    Компьютер:" << endl;
	cout << "Однопалубные:" << PlayerSeaBattle::number_1_use << "                   " << "Однопалубные:" << PlayerSeaBattle::number_1_pc << endl;
	cout << "Двухпалубные:" << PlayerSeaBattle::number_2_use << "                   " << "Двухпалубные:" << PlayerSeaBattle::number_2_pc << endl;
	cout << "Трехпалубные:" << PlayerSeaBattle::number_3_use << "                   " << "Трехпалубные:" << PlayerSeaBattle::number_3_pc << endl;
	cout << "Четырехпалубные:" << PlayerSeaBattle::number_4_use << "                " << "Четырехпалубные:" << PlayerSeaBattle::number_4_pc << endl;
	if (stat == 1)
		cout << "Состояние : ВАШ ХОД! - " << s1 << endl;
	else if (stat == 2)
		cout << "Состояние : ХОД КОМПЬЮТЕРА! - " << s1 << endl;
	else
		cout << "Состояние : ИГРА ЗАВЕРШИЛАСЬ!" << endl;
}
// ИНИЦИАЛИЗАЦИЯ СТАТИЧЕСКИХ ПЕРЕМЕННЫХ
int PlayerSeaBattle::number_1_use = 4;
int PlayerSeaBattle::number_2_use = 3;
int PlayerSeaBattle::number_3_use = 2;
int PlayerSeaBattle::number_4_use = 1;
int PlayerSeaBattle::number_1_pc = 4;
int PlayerSeaBattle::number_2_pc = 3;
int PlayerSeaBattle::number_3_pc = 2;
int PlayerSeaBattle::number_4_pc = 1;
int PlayerUser::number_ship = 0;
bool PlayerUser::number_position = true;
int PlayerComputer::temp = 0;
int PlayerComputer::control = 0;
int PlayerComputer::deck = 0;
int PlayerComputer::qwerty = 0;
vector<ship_1> PlayerSeaBattle::one_deck_use;
vector<ship_2> PlayerSeaBattle::two_deck_use;
vector<ship_3> PlayerSeaBattle::three_deck_use;
ship_4 PlayerSeaBattle::four_deck_use;
vector<ship_1> PlayerSeaBattle::one_deck_pc;
vector<ship_2> PlayerSeaBattle::two_deck_pc;
vector<ship_3> PlayerSeaBattle::three_deck_pc;
ship_4 PlayerSeaBattle::four_deck_pc;
int main()
{
	setlocale(LC_ALL, "Russian");
	PlayerComputer pc;
	PlayerUser use;
	int a;
	int x = 5, y = 5;
	int b = -1;
	int at;
	string status = " ";
	bool t = false;
	vector<vector<int>> save_attack_use(10), save_attack_pc(10);
	vector<int> x_save_pc, y_save_pc;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			save_attack_use[i].push_back(0);
			save_attack_pc[i].push_back(0);
		}
	cout << "Морской бой!\n" << endl;
	cout << "1. Начать игру." << endl;
	cout << "2. Выйти." << endl;
	cout << ">>";
	cin >> a;
	system("cls");
	if (a == 1)
	{
		while (PlayerUser::number_ship != 10)
		{
			cout_start();
			use.InitializeShip(x, y);
			if (PlayerUser::number_ship <= 9)
				setcur(0, 0);
		}
		cout << endl;
		cout << "Корабли установлены. Подождите, противник устанавливает свои корабли..." << endl;
		_sleep(2000);
		pc.GetBoard(use.ReturnBoard());
		if (!pc.InitializeShipComputer())
			while (!t)
			{
				PlayerComputer::temp = 0;
				t = pc.InitializeShipComputer();
			}
		use.GetBoard(pc.ReturnBoard());
		system("cls");
		x = 5, y = 5;
		while (use.GameOverUse() == true && pc.GameOverPc() == true)
		{
			while (b == -1)
			{
				cout_end(1, status);
				use.DrawBoard(x, y, save_attack_pc, save_attack_use);
				if (pc.GameOverPc() && use.GameOverUse())
				{
					b = use.AttackUser(x, y, save_attack_pc, save_attack_use);
				}
				else
					break;
				setcur(0, 0);
			}
			if (b == 1 || b == 2)
			{
				while (b == 1 || b == 2)
				{
					if (b == 1)
						status = "Попадание!";
					else
						status = "Корабль уничтожен!";
					cout_end(1, status);
					use.DrawBoard(x, y, save_attack_pc, save_attack_use);
					if (pc.GameOverPc() && use.GameOverUse())
					{
						b = use.AttackUser(x, y, save_attack_pc, save_attack_use);
					}
					else
						break;
					if (b == -1 && status == "Попадание!")
						b = 1;
					else if (b == -1 && status == "Корабль уничтожен!")
						b = 2;
					system("cls");
				}
			}
			if (b == 0)
			{
				status = "Мимо!";
				cout_end(1, status);
				use.DrawBoard(x, y, save_attack_pc, save_attack_use);
				_sleep(2000);
				system("cls");
			}
			if (b != 0)
				_sleep(2000);
			status = " ";
			cout_end(2, status);
			use.DrawBoard(x, y, save_attack_pc, save_attack_use);
			_sleep(2000);
			if (pc.GameOverPc() && use.GameOverUse())
			{
				at = pc.AttackComputer(x_save_pc, y_save_pc, save_attack_pc);
			}
			else
				break;
			setcur(0, 0);
			if (at == 1 || at == 2)
			{
				while (at == 1 || at == 2)
				{
					if (at == 1)
						status = "Попадание!";
					else
						status = "Корабль уничтожен!";
					cout_end(2, status);
					use.DrawBoard(x, y, save_attack_pc, save_attack_use);
					_sleep(2000);
					if (pc.GameOverPc() && use.GameOverUse())
					{
						at = pc.AttackComputer(x_save_pc, y_save_pc, save_attack_pc);
					}
					else
						break;
					system("cls");
				}
			}
			if (at == 0)
			{
				status = "Мимо!";
				cout_end(2, status);
				use.DrawBoard(x, y, save_attack_pc, save_attack_use);
				_sleep(2000);
				system("cls");
			}
			b = -1;
			status = " ";
		}
		system("cls");
		status = " ";
		if (!use.GameOverUse())
		{
			cout_end(3, status);
			use.DrawBoard(x, y, save_attack_pc, save_attack_use);
			cout << endl;
			cout << "Игра закончена! Вы програли." << endl;
		}
		else
		{
			cout_end(3, status);
			use.DrawBoard(x, y, save_attack_pc, save_attack_use);
			cout << endl;
			cout << "Игра закончена! Вы выиграли." << endl;
		}

	}
	else
		return 0;
}