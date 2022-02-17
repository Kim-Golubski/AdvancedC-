#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <vector>
using namespace std;

int main()
{
    const size_t dragons{ 10 };
    const size_t characaters{ 10 };

    array<array<string, characaters>, dragons> data{};

    char addCharacter = 'y';
    int count{ 0 };
    int dragonCount;
    char start;

    cout << "Would you like to enter GoT data? y=continue" << endl;
    cin >> start;
    cout << endl;

    if (start == 'y')
    {
        while (addCharacter == 'y' && count < data.size())
        {
            cout << "Enter character name: ";
            cin >> data[0][count];

            cout << "How many dragons? ";
            cin >> dragonCount;

            for (size_t d{ 1 }; d <= dragonCount; d++)
            {
                cout << "Enter the name for dragon " << d << ": ";
                cin >> data[d][count];
            }

            count++;

            cout << "Would you like to enter another character? y=continue" << endl;
            cin >> addCharacter;

        }
        cout << endl;
        for (size_t name{ 0 }; name < data.size(); ++name)
        {
            for (size_t dragName{ 0 }; dragName < data[name].size(); ++dragName)
            {
                cout << setw(8) << data[name][dragName];
            }
            cout << endl;
        }

        vector<string> kingdoms(1);
        vector<unsigned int> armySize(1);
        unsigned int size;
        string kingdomName;
        char choice = 'y';

        while (choice == 'y')
        {
            cout << "Enter kingdom: ";
            cin >> kingdomName;
            kingdoms.push_back(kingdomName);
            cout << "Enter the army size for kingdom " << kingdomName << ': ' << endl;
            cin >> size;
            armySize.push_back(size);
            cout << "Enter another kingdom? y=continue" << endl;
            cin >> choice;
        }
        cout << endl;
        for (int i{ 1 }; i < kingdoms.size(); i++)
        {
            cout << kingdoms[i] << ' ' << armySize[i];
            cout << endl;
        }
    }
    else
    {
        cout << "See ya later!";
    }
}
