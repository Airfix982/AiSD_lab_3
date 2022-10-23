#include <stdio.h>
#include <typeinfo>
#include <iostream>

class Set_of_numbers
{
    private:

    int size;
    int count;
    int* array;

    public:

    Set_of_numbers( int size = 0 )
    {
        this->size = size;
        count = 0;
        array = new int [size];
        for ( int i = 0; i < size; i++ )
        {
            int choice;
            printf( "Закончить создание - 1\n" );
            scanf( "%d", & choice );
            if ( choice == 1 )
            {
                break;
            }
            double number;
            bool flag = 1;
            while ( flag )
            {
                printf( "Введите целое число: \n" );
                scanf( "%lf", & number );
                if ( double(int(number)) != number ) printf( "Введено нецелое число\n" );
                else 
                {
                    bool unic_number = 1;
                    for ( int j = 0; j <= i; j++ )
                    {
                        if ( array[j] == number )
                        {
                            printf( "Число %d не уникальное\n", int(number) );
                            unic_number = 0;
                            break;
                        }
                        else continue;                       
                    }
                    if ( unic_number == 1 )
                    {
                        array[i] = int(number);
                        count++;
                        flag = 0;
                    }
                }
            }
        }
    }

    Set_of_numbers( Set_of_numbers & set, int size ) 
    {
        this->size = size;
        for ( int i = 0; i < size; i++ )
        {
            array[i] = set.array[i];
        }
    }

    int & operator []( int index )
    {
        if ( index > size || index < 1 ) throw "Неверный индекс\n";
        return array[index];
    }

    Set_of_numbers & operator + ( Set_of_numbers & set_1 )
    {
        if ( set_1.size == 0 ) return *this;
        for ( int i = 0; i < size; i++ )
        {
            for ( int j = 0; j < set_1.size; j++ )
            if ( set_1.array[j] != this->array[i] )
            {
                if ( this->count == this->size )
                {
                    int old_arr[this->size]
                    for ( int k = 0; k < this->size; k++ )
                    {
                        old_arr[k] = this->array[k];
                    }
                    this->array = new int [this->size + 10];
                    for ( int k = 0; k < this->size; k++ )
                    {
                        this->array[k] = old_arr[k];
                    }
                    delete[] old_arr;
                }
                this->array[++count] = set_1.array[j];
            }
        }
        return *this;
    }

    Set_of_numbers & operator - ( Set_of_numbers & set_1 )
    {
        if ( set_1.size == 0 ) return *this;
        for ( int i = 0; i < size; i++ )
        {
            for ( int j = 0; j < set_1.size; j++ )
            if ( set_1.array[j] == this->array[i] )
            {
                int old_arr = this->array;
                this->array = new int [this->size - 1];
                for ( int k = 0; k < i; k++ )
                {
                        this->array[k] = old_arr[k];
                }
                for ( int k = i + 1; k < count; k++ )
                {
                        this->array[k] = old_arr[k];
                }
                delete[] old_arr;
                
                this->count--;
            }
        }
        this->size = this->count;
        return *this;
    }
};

int main()
{
    printf( "Start\n Введите размерность масива: \n" );
    int size_1;
    scanf( "%d", &size_1 );
    Set_of_numbers arr1( size_1 );
    printf( "%d", arr1[3] );
    return 0;
}