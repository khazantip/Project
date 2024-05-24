#include <iostream>
using namespace std;


void game(char symbol, int gamen)
{
	static char field[3][3];
	if (symbol == '.')
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				field[i][j] = '.';
				cout << field[i][j] << " ";
			}
			cout << "\n";
		}
	}
	cout << "ход игрока" << gamen;
	cin >> symbol;
	if (symbol == '1' && gamen == 1)
	{
		field[0][0] = 'X';
	}
	else if (symbol == '1' && gamen == 2)
	{
		field[0][0] = '0';
	}

	if (symbol == '2' && gamen == 1)
	{
		field[0][1] = 'X';
	}
	else if (symbol == '2' && gamen == 2)
	{
		field[0][1] = '0';
	}

	if (symbol == '3' && gamen == 1)
	{
		field[0][2] = 'X';
	}
	else if (symbol == '3' && gamen == 2)
	{
		field[0][2] = '0';
	}

	if (symbol == '4' && gamen == 1)
	{
		field[1][0] = 'X';
	}
	else if (symbol == '4' && gamen == 2)
	{
		field[1][0] = '0';
	}

	if (symbol == '5' && gamen == 1)
	{
		field[1][1] = 'X';
	}
	else if (symbol == '5' && gamen == 2)
	{
		field[1][1] = '0';
	}

	if (symbol == '6' && gamen == 1)
	{
		field[1][2] = 'X';
	}
	else if (symbol == '6' && gamen == 2)
	{
		field[1][2] = '0';
	}

	if (symbol == '7' && gamen == 1)
	{
		field[2][0] = 'X';
	}
	else if (symbol == '7' && gamen == 2)
	{
		field[2][0] = '0';
	}

	if (symbol == '8' && gamen == 1)
	{
		field[2][1] = 'X';
	}
	else if (symbol == '8' && gamen == 2)
	{
		field[2][1] = '0';
	}

	if (symbol == '9' && gamen == 1)
	{
		field[2][2] = 'X';
	}
	else if (symbol == '9' && gamen == 2)
	{
		field[2][2] = '0';
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			
			cout << field[i][j] << " ";
		}
		cout << "\n";
	}

	if (field[0][0] == field[1][1] && field[0][0] == field[2][2] && field[1][1] == field[2][2])
		return;
	if (field[0][0] == field[0][1] && field[0][0] == field[0][2] && field[0][1] == field[0][2])
		return;
	//продолжить!!!
	return game(symbol, (gamen % 2) + 1);
}

int main()
{
	setlocale(LC_ALL, "ru");
	game('.', 1);


}