#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <cmath>
#include <iostream>
#include "set_of_numbers.h"
//#include "set_of_numbers.cpp"
using namespace std;

int main()
{
    SetConsoleCP( 1251 );
    SetConsoleOutputCP( 1251 );
    while ( true )
    {

        bool flag_1 = 1;
        bool flag_2 = 1;
        set_of_numbers set_1( 0 );
        set_of_numbers set_2( 0 );

        while ( true )
        {
            try
            {

                cout << "Start" << endl << "Ââåäèòå ðàçìåðíîñòü ïåðâîãî ìàñèâà: " << endl;
                double size_1;
                cin >> size_1;
                if ( double( int( size_1 ) ) != size_1 ) throw "Íåâåðíàÿ ðàçìåðíîñòü ";
                set_of_numbers set_3( size_1 );
                set_1 = set_3;
                cout << "Ââåäèòå ðàçìåðíîñòü âòîðîãî ìàñèâà: " << endl;
                double size_2;
                cin >> size_2;
                if ( double( int( size_2 ) ) != size_2 ) throw "Íåâåðíàÿ ðàçìåðíîñòü ";
                set_of_numbers set_4( size_2 );
                set_2 = set_4;
                break;

            }
            catch ( const char* e )
            {

                cout << e << endl;

            }
            catch ( ... )
            {

                cout << "Something went wrong" << endl;

            }
        }

        cout << endl << "Ïåðâîå ìíîæåñòâî: " << endl << set_1 << endl << "Âòîðîå ìíîæåñòâî: " << endl << set_2 << endl;


        double choice;

        while ( true )
        {

             while ( true )
            {

                cout << endl << "1 - ïîëó÷èòü ÷èñëî ïî èíäåêñó"/**/ << endl << "2 - ðàñïå÷àòàòü ìíîæåñòâà" << endl << "3 - îáúåäèíèòü ìíîæåñòâà" << endl
                << "4 - âû÷åñòü ìíîæåñòâî"/**/ << endl << "5 - äîáàâèòü ÷èñëî âî ìíîæåñòâî"/**/ << endl << "6 - óäàëèòü ÷èñëî èç ìíîæåñòâà"/**/ << endl
                << "7 - âû÷èñëèòü ïåðåñå÷åíèå äâóõ ìíîæåñòâ" << endl << "8 - ïðîâåðèòü íàëè÷èå ÷èñëà âî ìíîæåñòâå"/**/ << endl
                << "9 - ïðîâåðèòü, ÷òî îäíî ìíîæåñòâî ÿâëÿåòñÿ ïîäìíîæåñòâîì äðóãîãî"/**/ << endl << "10 - çàêîí÷èòü" << endl << "11 - íà÷àòü çàíîâî" << endl;
                cin >> choice;
                if ( choice > 0 && choice < 12 && double( int( choice ) ) == choice )  break; 
                else
                {

                    cout << "Íåèçâåñòíûé âûáîð, ïîïðîáóéòå åùå ðàç" << endl;
                    continue;

                }

            }

            while ( true )
            {

                double number_of_set;
                if ( choice == 1 || choice == 4 || choice == 5 || choice == 6 || choice == 8 || choice == 9 )
                {

                    while ( true )//Âûáîð ìíîæåñòâà äëÿ äåéñòâèÿ
                    {

                        try
                        {

                            cout << "Âûáåðèòå ìíîæåñòâî - 1 èëè 2: " << endl;
                            cin >> number_of_set;
                            if ( ( number_of_set == 1 || number_of_set == 2 ) && double( int( number_of_set ) ) == number_of_set ) break;
                            else throw "Âûáðàíî íåñóùåñòâóþùåå ìíîæåñòâî";

                        }
                        catch ( const char * e )
                        {

                            cout << e << endl;

                        }
                        catch ( ... )
                        {

                            cout << "Something went wrong" << endl;

                        }

                    }

                    if ( choice == 1 )
                    {

                        while ( true )
                        {

                            try
                            {

                                if ( number_of_set == 1 )
                                {

                                    double index;
                                    cout << "Ââåäèòå èíäeêñ: " << endl;
                                    cin >> index;
                                    if ( double( int( index ) ) != index ) throw "Íåâåðíûé èíäåêñ";
                                    cout << "Ýëåìåíò 1ãî ìíîæåñòâà ñ èíäåêñîì " << index << " - " << set_1[index - 1] << endl;
                                    break;

                                }
                                else
                                {

                                    double index;
                                    cout << "Ââåäèòå èíäeêñ: " << endl;
                                    cin >> index;
                                    if ( double( int( index ) ) != index ) throw "Íåâåðíûé èíäåêñ";
                                    cout << "Ýëåìåíò 2ãî ìíîæåñòâà ñ èíäåêñîì " << index << " - " << set_2[index - 1] << endl;
                                    break;

                                }

                            }
                            catch ( const char * e )
                            {

                                cout << e << endl;

                            }
                            catch ( ... )
                            {

                                cout << "Something went wrong" << endl;

                            }

                        }
                        break;

                    }

                    if ( choice == 4 )
                    {

                        while ( true )
                        {

                            try
                            {

                                if ( number_of_set == 1 )
                                {

                                    set_of_numbers set_3 = set_1 - set_2;
                                    cout << "Ìíîæåñòâî " << set_1 << " ìèíóñ ìíîæåñòâî " << set_2 << " : " << endl << set_3 << endl;
                                    break;

                                }
                                else
                                {

                                    set_of_numbers set_3 = set_2 - set_1;
                                    cout << "Ìíîæåñòâî " << set_2 << " ìèíóñ ìíîæåñòâî " << set_1 << " : " << endl << set_3 << endl;
                                    break;

                                }

                            }
                            catch ( const char * e )
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

                    if ( choice == 5 )
                    {

                        while ( true )
                        {

                            try
                            {

                                if ( number_of_set == 1 )
                                {

                                    double value;
                                    cout << "Ââåäèòå öåëîå ÷èñëî: " << endl;
                                    cin >> value;
                                    if ( double( int( value ) ) != value ) throw "Ââåäåíî íåöåëîå ÷èñëî";
                                    set_1 += value;
                                    cout << "Èçìåíåííîå ìíîæåñòâî:" << endl << set_1 << endl;
                                    break;

                                }
                                else
                                {

                                    double value;
                                    cout << "Ââåäèòå öåëîå ÷èñëî: " << endl;
                                    cin >> value;
                                    if ( double( int( value ) ) != value ) throw "Ââåäåíî íåöåëîå ÷èñëî";
                                    set_2 += value;
                                    cout << "Èçìåíåííîå ìíîæåñòâî:" << endl << set_2 << endl;
                                    break;

                                    }

                            }
                            catch ( const char * e )
                            {

                                cout << e << endl;

                            }
                            catch ( ... )
                            {

                                cout << "Something went wrong" << endl;

                            }

                        }
                        break;

                    }

                    if ( choice == 6 )
                        {

                        while ( true )
                        {

                            try
                            {

                                if ( number_of_set == 1 )
                                {

                                    double value;
                                    cout << "Ââåäèòå öåëîå ÷èñëî: " << endl;
                                    cin >> value;
                                    if ( double( int( value ) ) != value ) throw "Ââåäåíî íåöåëîå ÷èñëî";
                                    set_1 -= value;
                                    cout << "Èçìåíåííîå ìíîæåñòâî:" << endl << set_1 << endl;
                                    break;

                                }
                                else
                                {

                                    double value;
                                    cout << "Ââåäèòå öåëîå ÷èñëî: " << endl;
                                    cin >> value;
                                    if ( double( int( value ) ) != value ) throw "Ââåäåíî íåöåëîå ÷èñëî";
                                    set_2 -= value;
                                    cout << "Èçìåíåííîå ìíîæåñòâî" << endl << set_2 << endl;
                                    break;

                                }

                            }
                            catch ( const char * e )
                            {

                                cout << e << endl;

                            }
                            catch ( ... )
                            {

                                cout << "Something went wrong" << endl;

                            }

                        }
                        break;

                    }

                    if ( choice == 8 )
                    {

                        while ( true )
                        {

                            try
                            {

                                if ( number_of_set == 1 )
                                {

                                    double value;
                                    cout << "Ââåäèòå öåëîå ÷èñëî: " << endl;
                                    cin >> value;
                                    if ( double( int( value ) ) != value ) throw "Ââåäåíî íåöåëîå ÷èñëî";
                                    if ( set_1.presence( value ) == -1 ) cout << "Taêîãî ÷èñëà íåò" << endl;
                                    else cout << "Taêîå ÷èñëî åñòü" << endl;
                                    break;

                                }
                                else
                                {

                                    double value;
                                    cout << "Ââåäèòå öåëîå ÷èñëî: " << endl;
                                    cin >> value;
                                    if ( double( int( value ) ) != value ) throw "Ââåäåíî íåöåëîå ÷èñëî";
                                    if ( set_2.presence( value ) == -1 ) cout << "Taêîãî ÷èñëà íåò" << endl;
                                    else cout << "Taêîå ÷èñëî åñòü" << endl;
                                    break;

                                }

                            }
                            catch ( const char * e )
                            {

                                cout << e << endl;

                            }
                            catch ( ... )
                            {

                                cout << "Something went wrong" << endl;

                            }

                        }
                        break;

                    }

                    if ( choice == 9 )
                    {

                        while ( true )
                        {

                            try
                            {

                                if ( number_of_set == 1 )
                                {

                                        
                                    if ( set_1.occurrence_of_elements( set_2 ) == true ) cout << "Ìíîæåñòâî " << set_2 << " ñîäåðæèò âñå ýëåìåíòû ìíîæåñòâà " << set_1 << endl;
                                    else cout << "Ìíîæåñòâî " << set_2 << " ñîäåðæèò íå âñå ýëåìåíòû ìíîæåñòâà " << set_1 << endl;
                                    break;

                                }
                                else
                                {

                                    if ( set_2.occurrence_of_elements( set_1 ) == true ) cout << "Ìíîæåñòâî " << set_1 << " ñîäåðæèò âñå ýëåìåíòû ìíîæåñòâà " << set_2 << endl;
                                    else cout << "Ìíîæåñòâî " << set_1 << " ñîäåðæèò íå âñå ýëåìåíòû ìíîæåñòâà " << set_2 << endl;
                                    break;

                                }

                            }
                            catch ( const char * e )
                            {

                                cout << e << endl;
                                break;

                            }
                            catch ( ... )
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

                    if ( choice == 2 )
                    {

                        cout << "Ïåðâîå ìíîæåñòâî:" << endl << set_1 << endl << "Âòîðîå ìíîæåñòâî:" << endl << set_2 << endl;
                        break;

                    }

                    if ( choice == 7 )
                    {

                        cout << "Ïåðåñå÷åíèå ìíîæåñòâ:" << endl << set_1 << endl << "è" << endl << set_2 << endl << "Ðåçóëüòàò: ";
                        set_of_numbers set_3 = set_1.intersection( set_2 );
                        cout << set_3;
                        break;

                    }

                    if ( choice == 3 )
                    {

                        cout << "Îáúåäèíåíèå ìíîæåñòâ:" << endl << set_1 << endl << "è" << endl << set_2 << endl << "Ðåçóëüòàò: ";
                        set_of_numbers set_3 = set_1 + set_2;
                        cout << set_3;
                        break;

                    }

                    if ( choice == 10 )
                    {

                        flag_1 = 0; break;

                    }

                    if ( choice == 11 ) 
                    {

                        flag_2 = 0; break;

                    }

                }

                }

            if ( flag_1 == 0 || flag_2 == 0 ) break;

            }

        if ( flag_1 == 0 ) break;

    }

    return 0;

}
