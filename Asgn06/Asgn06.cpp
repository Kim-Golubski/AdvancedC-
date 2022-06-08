#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;


int main()
{
    //loop variable to add packages
    char add = 'n';
    //class variables
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
    double const packageCost{ .5 };
    double const twoDayFee{ 4.95 };
    double const overnightFee{ 9.95 };
    //vector of Package pointers
    vector<Package*> packages;

    cout << "Would you like to enter package info? ";
    cin >> add;
    while (add != 'n')
    {
        cout << "Enter sender's full name: ";
        cin.ignore();
        getline(cin, senderName);
        
        cout << "Enter sender's street address: ";
        getline(cin, senderAddy);
        
        cout << "Enter sender's city: ";
        getline(cin, senderCity);
        
        cout << "Enter sender's state: ";
        getline(cin, senderState);
        
        cout << "Enter sender's zipcode: ";
        getline(cin, senderZip);
        
        cout << "Enter receiver's full name: ";
        getline(cin, receiverName);
        
        cout << "Enter receiver's street address: ";
        getline(cin, receiverAddy);
        
        cout << "Enter receiver's city: ";
        getline(cin, receiverCity);
        
        cout << "Enter receiver's state: ";
        getline(cin, receiverState);
        
        cout << "Enter receiver's zipcode: ";
        getline(cin, receiverZip);
        
        cout << "Enter package weight in ounces: ";
        cin >> packageWeight;

        cout << endl << "Standard shipping is the default." << endl << "Has shipping been upgraded? If so, enter 1 for overnight shipping or 2 for two day shipping: ";
        string choice;
        cin >> choice;

        if (choice == "1")
        {
            OvernightPackage* o = new OvernightPackage{ senderName, senderAddy, senderCity, senderState, senderZip, receiverName, receiverAddy, receiverCity, receiverState, receiverZip, packageWeight, packageCost, overnightFee };
            packages.push_back(o);
        }
        else if (choice == "2")
        {
            TwoDayPackage* t = new TwoDayPackage{ senderName, senderAddy, senderCity, senderState, senderZip, receiverName, receiverAddy, receiverCity, receiverState, receiverZip, packageWeight, packageCost, twoDayFee };
            packages.push_back(t);
        }
        else
        {
            Package* s = new Package{ senderName, senderAddy, senderCity, senderState, senderZip, receiverName, receiverAddy, receiverCity, receiverState, receiverZip, packageWeight, packageCost
            };
            packages.push_back(s);
        }
        cout <<endl<< "Enter another package? " << endl;
        cin >> add;
    }

    //total cost variable
    double totalCost = 0;

    for (auto& packagePtr : packages)
    {
        cout << endl;
        packagePtr->report();
        cout << endl;
        totalCost += packagePtr->calculateCost();
    }

    cout << endl<< "Total shipping costs for all packages: " << totalCost;

    //release pointer objects in vector
    for (auto* packageptr : packages)
    {
        delete packageptr;
    }
}
