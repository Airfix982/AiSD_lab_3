#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <cmath>
#include <iostream>
using namespace std;

class set_of_numbers
{
private:
    int size;
    int count;
    int* array;

public:
    int presence(const int& number) const
    {

        for (int i = 0; i < this->count; i++)
        {

            if (this->array[i] == number)
                return i;

        }
        return -1;

    } // Проверка наличия

    int& operator [] (const int& index) const
    {

        if (index > count - 1 || index < 0)
            throw "Неверный индекс\n";
        return array[index];

    } // Обращение по индексу

    set_of_numbers(int size = 0)
    {
        if (size < 0) throw "Размерность не может быть отрицательной";
        this->size = size;
        count = 0;
        array = new int[size];
        for (int i = 0; i < size; i++)
        {
            while (1)
            {

                double number;
                cout << "Введите целое число: ";
                cin >> number;
                if (double(int(number)) != number)
                {

                    cout << "Число " << number << " не целое" << endl;

                }
                else if (this->presence(number) != -1)
                {

                    cout << "Число " << number << " не уникальное" << endl;

                }
                else
                {

                    array[i] = int(number);
                    count++;
                    break;

                }
            }
        }
    } // Конструктор

    void operator = (const set_of_numbers& other_set)
    {

        this->size = other_set.size;
        this->count = other_set.count;
        this->array = new int[this->size];
        for (int i = 0; i < other_set.count; i++)
        {

            this->array[i] = other_set.array[i];

        }
    }

    void add(const int& number)
    {

        if (this->presence(number) != -1)
            throw "Введенное число не уникальное\n";
        else if (double(int(number)) != number) throw "Введенное число не целое\n";
        if (this->count == this->size)
        {

            int* old_arr = new int[this->size];
            for (int k = 0; k < this->count; k++)
            {

                old_arr[k] = this->array[k];

            }
            this->array = new int[this->size + 10];
            for (int k = 0; k < this->count; k++)
            {

                this->array[k] = old_arr[k];

            }
            this->size += 10;
            delete[] old_arr;
            this->array[count++] = number;

        }
        else this->array[count++] = number;

    } // Добавление числа в массив

    void delete_(const int& number)
    {

        int value = this->presence(number);
        if (value != -1)
        {

            int* old_arr = new int[this->size];
            for (int k = 0; k < this->size; k++)
            {

                old_arr[k] = this->array[k];

            }
            this->array = new int[--this->size];
            for (int k = 0; k < value; k++)
            {

                this->array[k] = old_arr[k];

            }
            for (int k = value + 1; k < this->size + 1; k++)
            {

                this->array[k - 1] = old_arr[k];

            }
            delete[] old_arr;
            this->count--;

        }
        else throw "Такого числа нет\n";
    } // Удаление числа из массива

    void print() const
    {

        if (this->count == 0) cout << "Пустое множество" << endl;
        else
        {

            for (int i = 0; i < count; i++)
            {

                cout << array[i] << " ";

            }
            cout << endl;
        }

    }

    set_of_numbers& operator + (const set_of_numbers& set_1)
    {

        set_of_numbers new_set(0);
        new_set.size = this->count + set_1.count;
        new_set.array = new int[new_set.size];
        for (int i = 0; i < this->count; i++)
        {

            new_set.array[i] = this->array[i];
            new_set.count++;

        }
        for (int i = 0; i < set_1.count; i++)
        {

            if ((this->presence(set_1.array[i])) == -1)
            {

                new_set.array[new_set.count++] = set_1.array[i];

            }

        }
        return new_set;

    } // Сложение двух массивов

    set_of_numbers& operator - (const set_of_numbers& set_1)
    {

        set_of_numbers new_set(0);
        new_set = *this;
        for (int i = 0; i < set_1.count; i++)
        {
            try
            {

                new_set.delete_(set_1.array[i]);

            }
            catch (const char* e)
            {

                continue;

            }
            catch (...)
            {

                throw "Something went wrong\n";

            }
            new_set.print();
        }
        return new_set;
    } // Вычитание двух массивов

    void operator + (const int& number)
    {

        try
        {

            this->add(number);

        }
        catch (const char* e)
        {

            throw "Такое число уже есть\n";

        }
        catch (...)
        {

            throw "Something went wrong\n";

        }

    } // Прибавить число в массив

    void operator += (const int& number)
    {
        try
        {

            this->add(number);

        }
        catch (const char* e)
        {

            throw "Такое число уже есть\n";

        }
        catch (...)
        {

            throw "Something went wrong\n";

        }
    } // Прибавить число в массив

    void operator - (const int& number)
    {

        try
        {

            this->delete_(number);

        }
        catch (const char* e)
        {

            throw e;

        }
        catch (...)
        {

            throw "Something went wrong";

        }

    } // Удалить число из массива

    void operator -= (const int& number)
    {

        try
        {

            this->delete_(number);

        }
        catch (const char* e)
        {

            throw e;

        }
        catch (...)
        {

            throw "Something went wrong";

        }

    } // Удалить число из массива

    set_of_numbers& intersection(const set_of_numbers& set_2) const
    {

        set_of_numbers new_arr(0);
        for (int i = 0; i < this->count; i++)
        {

            if (set_2.presence(this->array[i]) == -1)
                new_arr += this->array[i];

        }

        return new_arr;
    } // Пересечение

    bool operator == (const set_of_numbers& set_2) const
    {

        if (this->count != set_2.count) return false;
        for (int i = 0; i < this->count; i++)
        {

            if (this->array[i] != set_2.array[i]) return false;

        }
        return true;

    }

    bool occurrence_of_elements(const set_of_numbers& set_2) const
    {

        for (int i = 0; i < this->count; i++)
        {
            if (set_2.presence(this->array[i]) == -1) return false;
        }
        return true;

    };

};

int main()
{
    setlocale(LC_ALL, "Russian");
    while (true)// зацикливание программы
    {

        set_of_numbers set_1(0);
        set_of_numbers set_2(0);

        //Создание 2х множеств
        while (true)
        {
            try
            {

                cout << "Start" << endl << "Введите размерность первого масива: " << endl;
                double size_1;
                cin >> size_1;
                if (double(int(size_1)) != size_1) throw "Неверная размерность ";
                set_of_numbers set_3(size_1);
                set_1 = set_3;
                cout << "Введите размерность второго масива: " << endl;
                int size_2;
                cin >> size_2;
                if (double(int(size_2)) != size_2) throw "Неверная размерность ";
                set_of_numbers set_4(size_2);
                set_2 = set_4;
                break;

            }
            catch (const char* e)
            {

                cout << e << endl;

            }
            catch (...)
            {

                cout << "Something went wrong" << endl;

            }
        }//++
        //++




        double choice;
        while (true)//Выбор действия
        {

            while (true)
            {

                while (true)
                {

                    cout << "1 - получить число по индексу"/**/ << endl << "2 - распечатать множества" << endl << "3 - объединить множества" << endl
                        << "4 - вычесть множество"/**/ << endl << "5 - добавить число во множество"/**/ << endl << "6 - удалить число из множества"/**/ << endl
                        << "7 - вычислить пересечение двух множеств" << endl << "8 - проверить наличие числа во множестве"/**/ << endl
                        << "9 - проверить, что одно множество является подмножеством другого"/**/ << endl << "10 - закончить" << endl << "11 - начать заново" << endl;
                    cin >> choice;
                    if (choice > 0 && choice < 10 && double(int(choice)) == choice)  break; 
                    else
                    {

                        cout << "Неизвестный выбор, попробуйте еще раз" << endl;
                        continue;

                    }

                }//+++




                while (true)
                {

                    double number_of_set;
                    if (choice == 1 || choice == 4 || choice == 5 || choice == 6 || choice == 8 || choice == 9)
                    {

                        while (true)//Выбор множества для действия
                        {

                            try
                            {

                                cout << "Выберите множество - 1 или 2: " << endl;
                                cin >> number_of_set;
                                if ((number_of_set == 1 || number_of_set == 2) && double(int(number_of_set)) == number_of_set) break;
                                else throw "Выбрано несуществующее множество";

                            }
                            catch (const char* e)
                            {

                                cout << e << endl;

                            }
                            catch (...)
                            {

                                cout << "Something went wrong" << endl;

                            }

                        }//+++

                        if (choice == 1)
                        {

                            while (true)
                            {

                                try
                                {

                                    if (number_of_set == 1)
                                    {

                                        double index;
                                        cout << "Введите индeкс: " << endl;
                                        cin >> index;
                                        if (double(int(index)) != index) throw "Неверный индекс";
                                        cout << "Элемент 1го множества с индексом " << index << " - " << set_1[index - 1] << endl;
                                        break;

                                    }
                                    else
                                    {

                                        int index;
                                        cout << "Введите индeкс: " << endl;
                                        cin >> index;
                                        if (double(int(index)) != index) throw "Неверный индекс";
                                        cout << "Элемент 2го множества с индексом " << index << " - " << set_2[index - 1] << endl;
                                        break;

                                    }

                                }
                                catch (const char* e)
                                {

                                    cout << e << endl;

                                }
                                catch (...)
                                {

                                    cout << "Something went wrong" << endl;

                                }

                            }
                            break;

                        }//+++

                        if (choice == 4)
                        {

                            while (true)
                            {

                                try
                                {

                                    if (number_of_set == 1)
                                    {

                                        set_of_numbers set_3 = set_1 - set_2;
                                        cout << "Множество 1 минус множество 2:" << endl;
                                        set_3.print();
                                        break;

                                    }
                                    else
                                    {

                                        set_of_numbers set_3 = set_2 - set_1;
                                        cout << "Множество 2 минус множество 1:" << endl;
                                        set_3.print();
                                        break;

                                    }

                                }
                                catch (const char* e)
                                {

                                    cout << e << endl;
                                    break;

                                }
                                catch( ... )
                                {

                                    cout << "Something went wrong" << endl;
                                    break;

                                }

                            }
                            break;

                        }//+++

                        if (choice == 5)
                        {

                            while (true)
                            {

                                try
                                {

                                    if (number_of_set == 1)
                                    {

                                        double value;
                                        cout << "Введите целое число: " << endl;
                                        cin >> value;
                                        if (double(int(value)) != value) throw "Введено нецелое число";
                                        set_1 += value;
                                        cout << "Измененное множество \n";
                                        set_1.print();
                                        break;

                                    }
                                    else
                                    {

                                        double value;
                                        cout << "Введите целое число: " << endl;
                                        cin >> value;
                                        if (double(int(value)) != value) throw "Введено нецелое число";
                                        set_2 += value;
                                        cout << "Измененное множество \n";
                                        set_2.print();
                                        break;

                                    }

                                }
                                catch (const char* e)
                                {

                                    cout << e << endl;

                                }
                                catch (...)
                                {

                                    cout << "Something went wrong" << endl;

                                }

                            }
                            break;

                        }//+++

                        if (choice == 6)
                        {

                            while (true)
                            {

                                try
                                {

                                    if (number_of_set == 1)
                                    {

                                        double value;
                                        cout << "Введите целое число: " << endl;
                                        cin >> value;
                                        if (double(int(value)) != value) throw "Введено нецелое число";
                                        set_1 -= value;
                                        cout << "Измененное множество \n";
                                        set_1.print();
                                        break;

                                    }
                                    else
                                    {

                                        double value;
                                        cout << "Введите целое число: " << endl;
                                        cin >> value;
                                        if (double(int(value)) != value) throw "Введено нецелое число";
                                        set_2 -= value;
                                        cout << "Измененное множество \n";
                                        set_2.print();
                                        break;

                                    }

                                }
                                catch (const char* e)
                                {

                                    cout << e << endl;

                                }
                                catch (...)
                                {

                                    cout << "Something went wrong" << endl;

                                }

                            }
                            break;

                        }//+++

                        if (choice == 8)
                        {

                            while (true)
                            {

                                try
                                {

                                    if (number_of_set == 1)
                                    {

                                        double value;
                                        cout << "Введите целое число: " << endl;
                                        cin >> value;
                                        if (double(int(value)) != value) throw "Введено нецелое число";
                                        if (set_1.presence(value) == -1) cout << "Taкого числа нет" << endl;
                                        else cout << "Taкое число есть" << endl;
                                        break;

                                    }
                                    else
                                    {

                                        double value;
                                        cout << "Введите целое число: " << endl;
                                        cin >> value;
                                        if (double(int(value)) != value) throw "Введено нецелое число";
                                        if (set_2.presence(value) == -1) cout << "Taкого числа нет" << endl;
                                        else cout << "Taкое число есть" << endl;
                                        break;

                                    }

                                }
                                catch (const char* e)
                                {

                                    cout << e << endl;

                                }
                                catch (...)
                                {

                                    cout << "Something went wrong" << endl;

                                }

                            }
                            break;

                        }//+++

                        if (choice == 9)
                        {

                            while (true)
                            {

                                try
                                {

                                    if (number_of_set == 1)
                                    {

                                        
                                        if (set_1.occurrence_of_elements(set_2) == true) cout << "Множество 2 содержит все элементы множества 1" << endl;
                                        else cout << "Множество 2 содержит не все элементы множества 1" << endl;
                                        break;

                                    }
                                    else
                                    {

                                        if (set_2.occurrence_of_elements(set_1) == true) cout << "Множество 1 содержит все элементы множества 2" << endl;
                                        else cout << "Множество 1 содержит не все элементы множества 2" << endl;
                                        break;

                                    }

                                }
                                catch (const char* e)
                                {

                                    cout << e << endl;
                                    break;

                                }
                                catch (...)
                                {

                                    cout << "Something went wrong" << endl;
                                    break;

                                }

                            }
                            break;

                        }//+++

                    }
                    else
                    {

                        /*тут выполнение выбора, вывод множества на печать*/

                    }

                }

            }

        }

    }
    return 0;
}