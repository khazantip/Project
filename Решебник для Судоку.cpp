#include <iostream>
#include<vector>

using namespace std;

void ShowSudoku(int arr[9][9]) // показать 
{
    cout << "\t\t\t\t=============================\n";

    for (int i{ 0 }; i < 9; ++i)
    {
        cout << "\t\t\t\t\t";
        for (int j{ 0 }; j < 9; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\t\t\t\t=============================\n";
}

bool placement(int arr[9][9], int row, int col, int n)   // можно ли здесь разместить число
{
    if (arr[row][col] != 0)
    {
        return false;
    }
    bool num = true;

    int x = (col / 3) * 3;
    int y = (row / 3) * 3;

    for (int i{ 0 }; i < 9; ++i)
    {
        if (arr[row][i] == n)
        {
            num = false;
            break;
        }

        if (arr[i][col] == n)
        {
            num = false;
            break;
        }

        if (arr[y + i / 3][x + i % 3] == n)
        {
            num = false;
            break;
        }
    }
    return num;
}

vector <int> findPlace(int arr[9][9], int a, int b) //нахождение места для числа
{
    vector <int> pl = {};

    for (int i{ 1 }; i <= 9; ++i)
    {
        if (placement(arr, a, b, i))
        {
            pl.push_back(i);
        }       
    }

    return pl;
}

void copyArray(int arr[9][9], int arrCopy[9][9]) //метод копирования массива
{
    for (int i{ 0 }; i < 9; ++i)
    {
        for (int j{ 0 }; j < 9; ++j)
        {
            arrCopy[i][j] = arr[i][j];
        }
    }
}


void nextEmpty(int arr[9][9], int row, int col, int &nRow, int &nCol)  //нахождение следующей строки и столбца
{
    int index = 9 * 9;
    for (int i = row * 9 + col + 1; i < 9 * 9; ++i)
    {
        if (arr[i / 9][i % 9] == 0)
        {
            index = i;
            break;
        }
    }
    nRow = index / 9;
    nCol = index % 9;
}


bool solveSudoku(int arr[9][9], int row, int col) //решается судоку или нет
{
    if (row > 8)
    {
        return true;
    }

    if (arr[row][col] != 0)
    {
        int nextRow, nextCol;
        nextEmpty(arr, row, col, nextRow, nextCol);
        return solveSudoku(arr, nextRow, nextCol);
    }

    vector <int> place = findPlace(arr, row, col);

    if (place.size() == 0)
    {
        return false;
    }

    bool num = false;

    for (int i{ 0 }; i < place.size(); ++i)
    {
        int n = place[i];

        int arrCopy[9][9];
        copyArray(arr, arrCopy);
        arrCopy[row][col] = n;
        int nextCol, nextRow;
        nextEmpty(arrCopy, row, col, nextRow, nextCol);
        if (solveSudoku(arrCopy, nextRow, nextCol))
        {
            copyArray(arrCopy, arr);
            num = true;
            break;
        }
    }

    return num;
}


int main()
{
    setlocale(LC_ALL, "ru");

    cout << "\t\t\t\tДобро пожаловать в Решебник Судоку!\n\n";
    int board[9][9] = {
        {0,0,7,5,0,2,9,0,0},
        {0,9,6,0,8,0,0,1,0},
        {8,0,4,0,0,0,6,2,7},
        {7,0,0,8,0,5,0,0,3},
        {0,4,0,0,1,0,0,6,0},
        {9,0,0,6,0,7,0,0,1},
        {1,7,9,0,0,0,2,0,6},
        {0,3,0,0,7,0,1,8,0},
        {0,0,2,3,0,1,5,0,0}
    };
    cout << "\t\t\t\tНачальный вариант с частично заполненными клетками\n";
    ShowSudoku(board);
    solveSudoku(board, 0, 0);
    cout << "\n\t\t\t\tКонечный (решенный) вариант \n";
    ShowSudoku(board);
}
