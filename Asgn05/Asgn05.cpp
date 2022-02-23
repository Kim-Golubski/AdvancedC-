#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 


int main()
{
    string senderName;
    string senderAddy;
    string senderCity;
    string senderState;
    string senderZip;
    string receiverName;
    string receiverAddy;
    string receiverCity;
    string receiverState;
    string receiverZip;
    double packageWeight;
    double const packageCost {.5};
    double const twoDayFee{4.95};
    double const overnightFee{9.95};

    cout << "Enter sender's full name: ";
    cin.ignore();
    getline(cin, senderName);
    cout << "Enter sender's street address: ";
    cin.ignore();
    getline(cin, senderAddy);
    cout << "Enter sender's city: ";
    cin.ignore();
    getline(cin, senderCity);
    cout << "Enter sender's state: ";
    cin.ignore();
    getline(cin, senderState);
    cout << "Enter sender's zipcode: ";
    cin.ignore();
    getline(cin, senderZip);
    cout << "Enter receiver's full name: ";
    cin.ignore();
    getline(cin, receiverName);
    cout << "Enter receiver's street address: ";
    cin.ignore();
    getline(cin, receiverAddy);
    cout << "Enter receiver's city: ";
    cin.ignore();
    getline(cin, receiverCity);
    cout << "Enter receiver's state: ";
    cin.ignore();
    getline(cin, receiverState);
    cout << "Enter receiver's zipcode: ";
    cin.ignore();
    getline(cin, receiverZip);
    cout << "Enter package weight in ounces: ";
    cin >> packageWeight;



    Package standard(senderName, senderAddy, senderCity, senderState, senderZip, receiverName, receiverAddy, receiverCity, receiverState, receiverZip, packageWeight, packageCost);
    TwoDayPackage twoDay(senderName, senderAddy, senderCity, senderState, senderZip, receiverName, receiverAddy, receiverCity, receiverState, receiverZip, packageWeight, packageCost, twoDayFee);
    OvernightPackage overnight(senderName, senderAddy, senderCity, senderState, senderZip, receiverName, receiverAddy, receiverCity, receiverState, receiverZip, packageWeight, packageCost, overnightFee);
    cout <<endl<< "SHIPPING OPTIONS FOR PACKAGE WEIGHING " << standard.getWeight()<<" OUNCES"<<endl;
    cout <<"Standard rate: "<< standard.calculateCost() << endl;
    cout << "Two day shipping: " <<twoDay.calculateCost() << endl;
    cout << "Overnight rate: " <<overnight.calculateCost() << endl;
}

