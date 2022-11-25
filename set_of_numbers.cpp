#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
#include <locale.h>
#include <string.h>
#include <cmath>
#include <iostream>
#include "set_of_numbers.h"
using namespace std;

set_of_numbers::~set_of_numbers()
{

    delete [] array;

}

int set_of_numbers::presence ( const int& number ) const
{

    for ( int i = 0; i < this->count; i++ )
        {

            if ( this->array[i] == number )
            return i;

        }
        return -1;

} // Ïðîâåðêà íàëè÷èÿ

int & set_of_numbers::operator [] ( const int& index ) const
{

    if ( index > count - 1 || index < 0 ) throw "Not correct index\n";
    return array[index];

} // Îáðàùåíèå ïî èíäåêñó

set_of_numbers::set_of_numbers ( int size )
{
            
    if ( size < 0 ) throw "Size can't be negative";
    this->size = size;
    count = 0;
    array = new int[size];
    for ( int i = 0; i < size; i++ )
    {

        while ( 1 )
        {

            double number;
            cout << "Enter integer: ";
            while( !( cin >> number ) || ( cin.peek() != '\n' ) )
            {

                cin.clear();
                while ( cin.get() != '\n' );
                cout << "Text was entered";

            } 
            if ( double( int( number ) ) != number )
            {

                cout << "The number " << number << " isn't integer" << endl;

            }
            else if ( this->presence( number ) != -1 )
            {

                cout << "The number " << number << " isn't unic" << endl;

            }
            else
            {

                array[i] = int( number );
                count++;
                break;

            }

        }

    }

} // Êîíñòðóêòîð

set_of_numbers::set_of_numbers ( const set_of_numbers & other_set )
{

    this->size = other_set.size;
    this->count = other_set.count;
    this->array = new int[this->size];
    for (int i = 0; i < this->count; i++)
    {

        this->array[i] = other_set.array[i];

    }

}

void set_of_numbers::operator = ( const set_of_numbers & other_set )
{

    this->size = other_set.size;
    this->count = other_set.count;
    this->array = new int[this->size];
    for ( int i = 0; i < other_set.count; i++ )
    {

        this->array[i] = other_set.array[i];

    }

}

void set_of_numbers::add ( const int & number )
{

    if ( this->presence( number ) != -1 ) throw "The number isn't unic\n";
    else if ( double( int( number ) ) != number ) throw "The number isn't integer\n";
    if ( this->count == this->size )
    {

        int* old_arr = new int [this->size];
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

} // Äîáàâëåíèå ÷èñëà â ìàññèâ

void set_of_numbers::delete_ ( const int& number )
{

    int value = this->presence( number );
    if ( value != -1 )
    {

        int * old_arr = new int[this->size];
        for ( int k = 0; k < this->size; k++ )
        {

            old_arr[k] = this->array[k];

        }
        this->array = new int[--this->size];
        for ( int k = 0; k < value; k++ )
        {

            this->array[k] = old_arr[k];

        }
        for ( int k = value + 1; k < this->size + 1; k++ )
        {

            this->array[k - 1] = old_arr[k];

        }
        delete[] old_arr;
        this->count--;

    }
    else throw "The set doesn't contain such a number\n";

} // Óäàëåíèå ÷èñëà èç ìàññèâà

set_of_numbers set_of_numbers::operator + ( const set_of_numbers& set_1 )
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

} // Ñëîæåíèå äâóõ ìàññèâîâ

set_of_numbers set_of_numbers::operator - ( const set_of_numbers & set_1 )
{

    set_of_numbers new_set( 0 );
    new_set = *this;
    for ( int i = 0; i < set_1.count; i++ )
    {

        try
        {

            new_set.delete_( set_1.array[i] );

        }
        catch ( const char * e )
        {

            continue;

        }
        catch ( ... )
        {

            throw "Something went wrong\n";

        }

    }
    return new_set;
            
} // Âû÷èòàíèå äâóõ ìàññèâîâ

void set_of_numbers::operator + ( const int & number )
{

    try
    {

        this->add( number );

    }
    catch ( const char * e )
    {

        throw "The set already contains such a value\n";

    }
    catch ( ... )
    {

        throw "Something went wrong\n";

    }

} // Ïðèáàâèòü ÷èñëî â ìàññèâ

void set_of_numbers::operator += ( const int & number )
{
    
    try
    {

        this->add( number );

    }
    catch ( const char * e )
    {

        throw "The set already contains such a value\n";

    }
    catch ( ... )
    {

        throw "Something went wrong\n";

    }

} // Ïðèáàâèòü ÷èñëî â ìàññèâ

void set_of_numbers::operator - ( const int & number )
{

    try
    {

        this->delete_( number );

    }
    catch ( const char * e )
    {

        throw e;

    }
    catch ( ... )
    {

        throw "Something went wrong";

    }

} // Óäàëèòü ÷èñëî èç ìàññèâà

void set_of_numbers::operator -= ( const int & number )
{

    try
    {

        this->delete_( number );

    }
    catch ( const char * e )
    {

        throw e;

    }
    catch ( ... )
    {

        throw "Something went wrong";

    }

} // Óäàëèòü ÷èñëî èç ìàññèâà

set_of_numbers set_of_numbers::intersection ( const set_of_numbers & set_2 ) const
{

    set_of_numbers new_arr( 0 );
    for ( int i = 0; i < this->count; i++ )
    {

        if ( set_2.presence( this->array[i] ) != -1 ) new_arr += this->array[i];

    }
    return new_arr;

} // Ïåðåñå÷åíèå

bool set_of_numbers::operator == ( const set_of_numbers & set_2 ) const
{

    if ( this->count != set_2.count ) return false;
    for ( int i = 0; i < this->count; i++ )
    {

        if ( this->array[i] != set_2.array[i] ) return false;

    }
    return true;

}

bool set_of_numbers::operator != ( const set_of_numbers & set_2 ) const
{

    if ( this->count != set_2.count ) return true;
    for ( int i = 0; i < this->count; i++ )
    {

        if ( this->array[i] != set_2.array[i] ) return true;

    }
    return false;

}

bool set_of_numbers::occurrence_of_elements( const set_of_numbers & set_2 ) const
{

    for ( int i = 0; i < this->count; i++ )
    {

        if ( set_2.presence( this->array[i] ) == -1 ) return false;

    }
    return true;

};

ostream& operator << (ostream& os, const set_of_numbers& set)
{

    for ( int i = 0; i < set.count; i++ )
    {

        os << set.array[i] << " ";

    }
    return os;

}