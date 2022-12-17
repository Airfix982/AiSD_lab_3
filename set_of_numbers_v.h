#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
#pragma once
template<typename T>
class set_of_numbers
{

private:

   vector<T> array;

public:
    //Изменить в мейне конструктор
    ~set_of_numbers() = default;

    int presence(const T& number) const;

    T& operator [] ( int index);

    set_of_numbers() = default;

    set_of_numbers(const set_of_numbers<T>&) = default;

    set_of_numbers<T>& operator = (const set_of_numbers<T>&) = default;

    void add(const T& number);

    void delete_(const T& number);

    set_of_numbers operator + (const set_of_numbers<T>& set_1);

    set_of_numbers operator - (const set_of_numbers<T>& set_1);

    void operator + (const T& number);

    void operator += ( const T& number);

    void operator - (const T& number);

    void operator -= (const T& number);

    set_of_numbers intersection(set_of_numbers<T>& set_2);

    bool operator == (set_of_numbers<T>& set_2);

    bool operator != ( set_of_numbers<T>& set_2);

    bool occurrence_of_elements(const set_of_numbers<T>& set_2) const;

    friend ostream& operator << (ostream& os, const set_of_numbers<T>& set);

    typename vector<T>::iterator begin();

    typename vector<T>::iterator end(); 

};

template class set_of_numbers<int>;
template class set_of_numbers<float>;
template class set_of_numbers<string>;
template class set_of_numbers<pair<int, double>>;