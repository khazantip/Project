// Пятнашки.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;


const int arr1[6][6]{ {100,100,100,100,100,100},{100,1,2,3,4,100},{100,5,6,7,8,100},{100,9,10,11,12,100},{100,13,14,15,0,100},{100,100,100,100,100,100} };
    const int m = 6;
    const int n = 6;
 int arr[m][n]{ {100,100,100,100,100,100},
                   {100,1,2,3,4,100},
                   {100,5,6,7,8,100},
                   {100,9,10,11,12,100},
                   {100,0,13,14,15,100},
                   {100,100,100,100,100,100} };

    

    int tmp, num;
   //bool flag = true;
    
    bool f1()
    {
        for (int i(0); i < m; ++i)
        {
            
            for (int j(0); j < n; ++j)
            {
                if (arr[i][j] != arr1[i][j])
                {
                    return false;
                }
                else
                {
                    return true;
                    break;
                }
            }
            
        }
    }
    /*int f1(bool)
    {
        for (int i(1); i < m - 2; ++i)
        {
            for (int j(1); j < n - 2; ++j)
            {
                if (arr[i][j + 1] - arr[i][j] == 1)
                {
                    return !flag;

                }

            }
        }
        


    }*/

    /*int f2()
    {
        /*for (int i(m - 3); i > 0; --i)
        {

            for (int j(1); j < n - 2; ++j)
            {
                if (arr[i + 1][j] - arr[i][j] == 4)
                {
                    flag = true;
                }
            }
        }
        for (int i(m - 2); i > 0; --i)
        {
            
            for (int j(n - 3); j > 1; --j)
            {
                if (arr[i][j] - arr[i][j - 1] == 1)
                {
                    return !flag;
                }

            }
            
        }
        if (!flag)
        {
            for (int i(1); i < m - 2; ++i)
            {
                for (int j(1); j < n - 2; ++j)
                {
                    if (arr[i][j + 1] - arr[i][j] == 1)
                    {
                        cout << "ПОЗДРАВЛЯЕМ!!! Вы Выиграли!\n";
                        break;

                    }

                }
            }
        }
    }*/

    void f()
    {

        do
        {                                  
                cout << "Выбирете направление : \n";
                cout << "1 - Вверх\n2 - Вниз\n3 - Влево\n4 - Вправо\n5 - Выход!\n";
                cin >> num;
                switch (num)
                {
                case 1:
                    for (int i(0); i < m; ++i)
                    {
                        for (int j(0); j < n; ++j)
                        {
                            if (arr[i][j] == 0)
                            {
                                if (arr[i - 1][j] == 100)
                                {
                                    cout << "Неверно выбрано направление! Введите другое.\n";
                                    break;
                                }
                                tmp = arr[i][j];
                                arr[i][j] = arr[i - 1][j];
                                arr[i - 1][j] = tmp;

                            }
                        }
                    }

                    for (int i(1); i < m - 1; ++i)
                    {
                        cout << "\t";
                        for (int j(1); j < n - 1; ++j)
                        {
                            cout << arr[i][j] << "\t";
                        }
                        cout << "\n\n";
                    }


                    break;

                case 2:
                    for (int i(m - 1); i > 0; --i)
                    {
                        for (int j(0); j < n; ++j)
                        {

                            if (arr[i][j] == 0)
                            {
                                if (arr[i + 1][j] == 100)
                                {
                                    cout << "Неверно выбрано направление! Введите другое.\n";
                                    break;
                                }
                                tmp = arr[i][j];
                                arr[i][j] = arr[i + 1][j];
                                arr[i + 1][j] = tmp;

                            }
                        }
                    }

                    for (int i(1); i < m - 1; ++i)
                    {
                        cout << "\t";
                        for (int j(1); j < n - 1; ++j)
                        {
                            cout << arr[i][j] << "\t";
                        }
                        cout << "\n\n";
                    }
                    break;

                case 3:
                    for (int i(0); i < m; ++i)
                    {
                        for (int j(0); j < n; ++j)
                        {
                            if (arr[i][j] == 0)
                            {
                                if (arr[i][j - 1] == 100)
                                {
                                    cout << "Неверно выбрано направление! Введите другое.\n";
                                    break;
                                }
                                tmp = arr[i][j];
                                arr[i][j] = arr[i][j - 1];
                                arr[i][j - 1] = tmp;

                            }
                        }
                    }

                    for (int i(1); i < m - 1; ++i)
                    {
                        cout << "\t";
                        for (int j(1); j < n - 1; ++j)
                        {
                            cout << arr[i][j] << "\t";
                        }
                        cout << "\n\n";
                    }
                    break;

                case 4:




                    for (int i(0); i < m; ++i)
                    {
                        for (int j(n - 1); j > 0; --j)
                        {
                            if (arr[i][j] == 0)
                            {
                                if (arr[i][j + 1] == 100)
                                {
                                    cout << "Неверно выбрано направление! Введите другое.\n";
                                    break;
                                }
                                tmp = arr[i][j];
                                arr[i][j] = arr[i][j + 1];
                                arr[i][j + 1] = tmp;

                            }
                        }

                    }

                    for (int i(1); i < m - 1; ++i)
                    {
                        cout << "\t";
                        for (int j(1); j < n - 1; ++j)
                        {
                            cout << arr[i][j] << "\t";
                        }
                        cout << "\n\n";
                    }                  
                    break;

                case 5:
                    
                    cout << "До встречи!\n";
                    break;

                default:
                    cout << "Неверный ввод. Выбирете пункт от 1 до 4!\n";
                    break;

                }
                              
        } while (num != 5);
                                                                                
    }
    


int main()
{
    setlocale(LC_ALL, "ru");

    for (int i(1); i < m - 1; ++i)
    {
        cout << "\t";
        for (int j(1); j < n - 1; ++j)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n\n";
    }


    f();

    
     
 //f();
   
    
        cout << "ПОЗДРАВЛЯЕМ!!! Вы Выиграли!\n";

    //Проверка!

   /* for (int i(1); i < m - 1; ++i)
    {       
        for (int j(1); j < n - 2; ++j)
        {
            if (arr[i][j + 1] - arr[i][j] == 1)
            {
                return f();
            }

        }       
    }*/
    

}

