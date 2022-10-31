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
        int *array;

    public:
        int presence( const int &number ) const
        {

            for ( int i = 0; i < this->count; i++ )
            {

                if ( this->array[i] == number )
                    return i;

            }
            return -1;

        } // Проверка наличия

        int & operator [] ( const int &index ) const
        {

            if ( index > count - 1 || index < 0 )
                throw "Неверный индекс\n";
            return array[index];

        } // Обращение по индексу

        set_of_numbers( int size = 0 )
        {
            if( size < 0 ) throw "Размерность не может быть отрицательной";
            size = size;
            count = 0;
            array = new int[size];
            for ( int i = 0; i < size; i++ )
            {
                while (1)
                {

                    int number;
                    cout << "Введите целое число: ";
                    cin >> number;
                    if ( this->presence( number ) != -1 )
                    {

                        cout << "Число " << number << " не уникальное" << endl;
                        continue;

                    }
                    else
                    {

                        array[i] = number;
                        count++;
                        break;

                    }
                }
            }
        } // Конструктор

        void operator = ( const set_of_numbers &other_set )
        {

            this->size = other_set.size;
            this->count = other_set.count;
            this->array = new int[this->size];
            for ( int i = 0; i < other_set.count; i++ )
            {

                this->array[i] = other_set.array[i];

            }
        } // Конструктор копирования

        void add( const int &number )
        {

            if ( this->presence(number) != -1 )
                throw "Введенное число не уникальное\n";
            if ( this->count == this->size )
            {

                int *old_arr = new int[this->size];
                for ( int k = 0; k < this->count; k++ )
                {

                    old_arr[k] = this->array[k];

                }
                this->array = new int[this->size + 10];
                for ( int k = 0; k < this->count; k++ )
                {

                    this->array[k] = old_arr[k];

                }
                this->size += 10;
                delete[] old_arr;
                this->array[count++] = number;

            }
            else this->array[count++] = number;

        } // Добавление числа в массив

        void delete_( const int &number )
        {

            int value = this->presence( number );
            if ( value != -1 )
            {

                int *old_arr = new int[this->size];
                for ( int k = 0; k < this->size; k++ )
                {

                    old_arr[k] = this->array[k];

                }
                this->array = new int[--this->size];
                for ( int k = 0; k < value; k++ )
                {

                    this->array[k] = old_arr[k];

                }
                for ( int k = value + 1; k < this->size; k++ )
                {

                    this->array[k] = old_arr[k];

                }
                delete[] old_arr;
                this->count--;

            }
            else throw "Такого числа нет\n";
        } // Удаление числа из массива

        void print() const
        {

            if( this->count == 0 ) cout << "Пустое множество" << endl;
            else
            {

                for ( int i = 0; i < count; i++ )
                {

                    cout << array[i] << endl;

                }

            }

        }

        set_of_numbers &operator + ( const set_of_numbers &set_1 )
        {

            set_of_numbers new_set( 0 );
            new_set.size = this->count + set_1.count;
            new_set.array = new int[new_set.size];
            for ( int i = 0; i < this->count; i++ )
            {

                new_set.array[i] = this->array[i];
                new_set.count++;

            }
            for ( int i = 0; i < set_1.count; i++ )
            {

                if ( ( this->presence( set_1.array[i] ) ) == -1 )
                {

                    new_set.array[new_set.count++] = set_1.array[i];

                }

            }
            return new_set;

        } // Сложение двух массивов

        set_of_numbers & operator - ( const set_of_numbers &set_1 )
        {

            set_of_numbers new_set( 0 );
            new_set = *this;
            for ( int i = 0; i < set_1.count; i++ )
            {
                try
                {

                    new_set.delete_( set_1.array[i] );

                }
                catch ( const char *e )
                {

                    continue;

                }
                catch ( ... )
                {

                    throw "Something went wrong\n";

                }

            }
            return new_set;
        } // Вычитание двух массивов

        void operator + ( const int &number )
        {

            try
            {

                this->add( number );

            }
            catch ( const char *e )
            {

                throw "Такое число уже есть\n";

            }
            catch ( ... )
            {

                throw "Something went wrong\n";

            }

        } // Прибавить число в массив

        void operator += ( const int &number )
        {
            try
            {

                this->add( number );

            }
            catch ( const char *e )
            {

                throw "Такое число уже есть\n";

            }
            catch ( ... )
            {

                throw "Something went wrong\n";

            }
        } // Прибавить число в массив

        void operator - ( const int &number )
        {

            try
            {

                this->delete_( number );

            }
            catch ( const char *e )
            {

                throw e;

            }
            catch ( ... )
            {

                throw "Something went wrong";

            }

        } // Удалить число из массива

        void operator -= ( const int &number )
        {

            try
            {

                this->delete_( number );

            }
            catch ( const char *e )
            {

                throw e;

            }
            catch ( ... )
            {

                throw "Something went wrong";

            }

        } // Удалить число из массива

        set_of_numbers &intersection( const set_of_numbers &set_2 ) const
        {

            set_of_numbers new_arr( 0 );
            for ( int i = 0; i < this->count; i++ )
            {

                if ( set_2.presence( this->array[i] ) == -1 )
                    new_arr += this->array[i];

            }

            return new_arr;
        } // Пересечение

        bool operator == ( const set_of_numbers &set_2 ) const
        {

            if( this->count != set_2.count ) return false;
            for( int i = 0; i < this->count; i++ )
            {

                if( this->array[i] != set_2.array[i] ) return false;

            }
            return true;

        }

        bool occurrence_of_elements( const set_of_numbers &set_2 ) const
        {

            if( ( this->intersection( set_2 ) ) == *this ) return true;
            return false;
            
        };

};

int main()
{
    setlocale( LC_ALL, "Russian" );
    while( true )// зацикливание программы
    {

        set_of_numbers set_1( 0 );
        set_of_numbers set_2( 0 );

        //Создание 2х множеств
        try
        {

            cout << "Start" << endl << "Введите размерность первого масива: " << endl;
            int size_1;
            cin >> size_1;
            set_of_numbers set_3( size_1 );
            set_1 = set_3;
            cout << "Введите размерность второго масива: " << endl;
            int size_2;
            cin >> size_2;
            set_of_numbers set_4( size_2 );
            set_2 = set_4;

        }
        catch( const char * e )
        {

            cout << e << endl;

        }
        catch( ... )
        {

            cout << "Something went wrong" << endl;

        }






        int choice;
        while( true )//Выбор действия
        {

            while( true )
            {
                
                cout << "1 - получить число по индексу"/**/ << endl << "2 - распечатать множества" << endl << "3 - объединить множества" << endl 
                << "4 - вычесть множество"/**/ << endl << "5 - добавить число во множество"/**/ << endl << "6 - удалить число из множества"/**/ << endl 
                << "7 - вычислить пересечение двух множеств" << endl << "8 - проверить наличие числа во множестве"/**/ << endl 
                << "9 - проверить, что одно множество являедся подмножеством другого"/**/ << endl << "10 - закончить" << endl;
                cin >> choice;
                if( choice > 0 && choice < 10 ) break;
                else 
                {

                    cout << "Неизвестный выбор, попробуйте еще раз" << endl;
                    continue;

                }

                
        

                while( true )
                {

                        int number_of_set;
                        if( choice == 1 || choice == 4 || choice == 5 || choice == 6 || choice == 8 || choice == 9  )            
                        {

                            while( true )//Выбор множества для действия
                            {

                                try
                                {

                                    cout << "Выберите множество - 1 или 2: " << endl;
                                    cin >> number_of_set;
                                    if( number_of_set == 1 || number_of_set == 2 ) break;
                                    else throw "Выбрано несуществующее множество";

                                }
                                catch( const char * e )
                                {

                                    cout << e << endl;

                                }
                                catch( ... )
                                {

                                    cout << "Something went wrong" << endl;

                                }

                            }

                            if( choice == 1 )
                            {

                                while ( true )
                                {
                                    
                                    try
                                    {

                                        if( number_of_set == 1 )
                                        {

                                            int index;
                                            cout << "Введите индeкс: " << endl;
                                            cin >> index;
                                            cout << "Элемент 1го множества с индексом " << index << " - " << set_1[index - 1] << endl;
                                            break;

                                        }
                                        else
                                        {

                                            int index;
                                            cout << "Введите индeкс: " << endl;
                                            cin >> index;
                                            cout << "Элемент 2го множества с индексом " << index << " - " << set_2[index - 1] << endl;
                                            break;

                                        }

                                    }
                                    catch( const char * e )
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

                            }
                            
                            if (choice == 4 )
                            {

                                while ( true )
                                {
                                    
                                    try
                                    {

                                        if( number_of_set == 1 )
                                        {

                                            set_of_numbers set_3 = set_1 - set_2;
                                            cout << "Множество 1 минус множество 2:"<< endl;
                                            set_3.print();
                                            break;

                                        }
                                        else
                                        {

                                            set_of_numbers set_3 = set_2 - set_1;
                                            cout << "Множество 2 минус множество 1:"<< endl;
                                            set_3.print();
                                            break;

                                        }

                                    }
                                    catch( const char * e )
                                    {

                                        cout << e << endl;

                                    }
                                    /*catch( ... )
                                    {

                                        cout << "Something went wrong" << endl;
                                        break

                                    }*/

                                }

                            }

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