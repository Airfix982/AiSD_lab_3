#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <cmath>
#include <iostream>
#include <vector>
#include "set_of_numbers.h"
using namespace std;

template<typename T>
int set_of_numbers<T>::presence(const T& number ) const
{

    for (typename vector<T>::const_iterator it = array.begin(); it != array.end(); ++it ) 
    {

        if (*it == number) return distance(array.begin(), it);
        
    }
    return -1;

}

template<typename T>
T& set_of_numbers<T>::operator [] ( int index )
{

    typename vector<T>::iterator start = this->array.begin();
    typename vector<T>::iterator end = this->array.end();
    if ( index > distance( start, end) || index < 0 ) throw "Not correct index\n";
    return array[index];

}

template<typename T>
void set_of_numbers<T>::add(const T& number )
{

    if ( this->presence( number ) != -1 ) throw "The value isn't unic\n";
    this->array.push_back(number);

} 

template<typename T>
void set_of_numbers<T>::delete_(const T& number )
{

    for (typename vector<T>::iterator it = array.begin(); it != array.end(); )
    {
        if ( *it == number )
            it = array.erase( it );
        else
            ++it;
    }

} 

template<typename T>
set_of_numbers<T> set_of_numbers<T>::operator + ( const set_of_numbers<T>& set_1 )
{

    set_of_numbers<T> new_set = *this;
    for ( auto i : set_1.array )
    {

        if ( ( this->presence( i ) ) == -1 ) new_set.array.push_back( i );

    }
    return new_set;

} 

template<typename T>
set_of_numbers<T> set_of_numbers<T>::operator - (const set_of_numbers<T>& set_1 )
{

    set_of_numbers<T> new_set = *this;
    for ( auto i: set_1.array )
    {

        try
        {

            new_set.delete_( i );

        }
        catch ( const char* e )
        {

            continue;

        }
        catch ( ... )
        {

            throw "Something went wrong\n";

        }

    }
    return new_set;

}

template<typename T>
void set_of_numbers<T>::operator + (const T& number )
{

    try
    {

        this->add( number );

    }
    catch ( const char* e )
    {

        throw "The set already contains such a value\n";

    }
    catch ( ... )
    {

        throw "Something went wrong\n";

    }

} 

template<typename T>
void set_of_numbers<T>::operator += ( const T& number )
{

    try
    {

        this->add( number );

    }
    catch (const char* e)
    {

        throw "The set already contains such a value\n";

    }
    catch ( ... )
    {

        throw "Something went wrong\n";

    }

}

template<typename T>
void set_of_numbers<T>::operator - (const T& number )
{

    try
    {

        this->delete_( number );

    }
    catch ( const char* e )
    {

        throw e;

    }
    catch ( ... )
    {

        throw "Something went wrong";

    }

}

template<typename T>
void set_of_numbers<T>::operator -= (const T& number )
{

    try
    {

        this->delete_( number );

    }
    catch ( const char* e )
    {

        throw e;

    }
    catch ( ... )
    {

        throw "Something went wrong";

    }

}

template<typename T>
set_of_numbers<T> set_of_numbers<T>::intersection( set_of_numbers<T>& set_2 )
{

    set_of_numbers<T> new_arr;
    for ( auto i: this->array )
    {

        if ( set_2.presence( i ) != -1 ) new_arr += i;

    }
    return new_arr;

} 

template<typename T>
bool set_of_numbers<T>::operator == (set_of_numbers<T>& set_2 )
{

    typename vector<T>::iterator start1 = this->array.begin();
    typename vector<T>::iterator end1 = this->array.end();
    typename vector<T>::iterator start2 = set_2.array.begin();
    typename vector<T>::iterator end2 = set_2.array.end();
    if ( distance( start1, end1 ) != distance( start2, end2 ) ) return false;
    for ( start1, start2; start1 != end1; ++start1, ++start2 )
    {

        if ( *start1 != *start2 ) return false;

    }
    return true;

}

template<typename T>
bool set_of_numbers<T>::operator != (set_of_numbers<T>& set_2 )
{

    typename vector<T>::iterator start1 = this->array.begin();
    typename vector<T>::iterator end1 = this->array.end();
    typename vector<T>::iterator start2 = set_2.array.begin();
    typename vector<T>::iterator end2 = set_2.array.end();
    if (distance(start1, end1) != distance(start2, end2)) return true;
    for (start1, start2; start1 != end1; ++start1, ++start2)
    {

        if (*start1 != *start2) return true;

    }
    return false;

}

template<typename T>
bool set_of_numbers<T>::occurrence_of_elements(const set_of_numbers<T>& set_2 ) const
{

    for ( auto i: this->array )
    {

        if ( set_2.presence( i ) == -1 ) return false;

    }
    return true;

};

ostream& operator << (ostream& os, const set_of_numbers<int>& set)
{

    for ( auto i: set.array )
    {

        os << i << " ";

    }
    return os;

}

ostream& operator << (ostream& os, const set_of_numbers<float>& set)
{

    for (auto i : set.array)
    {

        os << i << " ";

    }
    return os;

}

ostream& operator << (ostream& os, const set_of_numbers<string>& set)
{

    for (auto i : set.array)
    {

        os << i << " ";

    }
    return os;

}

ostream& operator << (ostream& os, const set_of_numbers<pair<int, double>>& set)
{

    for (auto i : set.array)
    {

        os << i.first << " " << i.second << " ";

    }
    return os;

}

template<typename T>
typename vector<T>::iterator set_of_numbers<T>::begin()
{

    return array.begin();

}

template<typename T>
typename vector<T>::iterator set_of_numbers<T>::end()
{

    return array.end();

}




