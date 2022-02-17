
#include <iostream>
#include "OverloadDemo.h"
using namespace std;
int main()
{
    //create class instance and retrieve data
    OverloadDemo a;
    int num;
    double dec;
    string word;

    cout << "Enter an integer value: ";
    cin >> num;
    a.setIntOne(num);

    cout << "Enter a decimal value: ";
    cin >> dec;
    a.setDoubleOne(dec);

    cout << "Enter a color: ";
    cin >> word;
    a.setStringOne(word);
    

    cout << "Overload + functions:" << endl;
    //int + overload
    int plus = a + 5;
    cout << a.getIntOne() << "+5 = "  << plus<< endl;
    //double + overload
    double p = a + 5.2;
    cout <<a.getDoubleOne() << "+5.2 = "  << p <<endl;
    //string + overload
    string s = a + " elephant";   
    cout << a.getStringOne()<<"+ elephant = "<<s<<endl;

    cout<< endl<<"Overload - functions:" << endl;
    //int - overload
    int minus = a - 3;
    cout << a.getIntOne() << "-3 = " << minus << endl;
    //double - overload
    double m = a - 2.6;
    cout << a.getDoubleOne() << "-2.6 = " << m << endl;
    //string - overload
    string one = "monkey ";
    string r = a - one;
    cout << a.getStringOne() << "(-)monkey = " << r << endl;

    cout<< endl << "Overload / functions:" << endl;
    //int / overload
    int divide = a / 2;
    cout << a.getIntOne() << "/2 = " << divide << endl;
    //double / overload
    double d = a / 2.5;
    cout << a.getDoubleOne() << "/2.5 = " << d << endl;
    //string / overload
    string div = a / "grape";
    cout << a.getStringOne() << "(/)grape = " << div << endl;

    cout << endl << "Overload * functions:" << endl;
    //int * overload
    int mult = a * 2;
    cout << a.getIntOne() << "*2 = " << mult << endl;
    //double overload
    double multiply = a * 5.5;
    cout << a.getDoubleOne() << "*5.5 = " << multiply << endl;
    //string * overload;
    string mul = a * "rose";
    cout << a.getStringOne() << "(*)rose = " << mul << endl;

    cout << endl << "Overload prefix functions:" << endl;
    //prefix overloads
    cout << "original int value: " << a.getIntOne() << endl;
    cout << "original double value: " << a.getDoubleOne() << endl;
    ++a;
    cout << "prefix ++ int value: " << a.getIntOne() << endl;
    cout << "prefix ++ double value: " << a.getDoubleOne() << endl;
    --a;
    cout << "prefix -- int value: " << a.getIntOne() << endl;
    cout << "prefix -- double value: " << a.getDoubleOne() << endl;

    cout << endl << "Overload postfix functions:" << endl;
    //postfix overloads
    cout << "original int value: " << a.getIntOne() << endl;
    cout << "original double value: " << a.getDoubleOne() << endl;
    a++;
    cout << "postfix ++ int value: " << a.getIntOne() << endl;
    cout << "postfix ++ double value: " << a.getDoubleOne() << endl;
    a--;
    cout << "postfix -- int value: " << a.getIntOne() << endl;
    cout << "postfix -- double value: " << a.getDoubleOne() << endl;
}

