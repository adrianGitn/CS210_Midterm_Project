#include <iostream>
#include <fstream>
#include "CSVReader.h"
#include "SchoolList.cpp"
using namespace std;

int main() {
    SchoolList list;
    CSVReader reader;

    vector<vector<string>> data;
    data = reader.readCSV("schoolList.csv");

    for (size_t i = 1; i < data.size(); i++) {
        School school(data[i][0], data[i][1], data[i][2], data[i][3], data[i][4]);
        list.insertFirst(school);
    }

    bool run = true;
    int input;
    string nameInput;
    while (run) {
        cout << "Enter 1 for display, 2 to find by name, 3 for delete by name, or 4 for exit: " << endl;
        cin >> input;

        switch (input){
            case(1):
                list.display();
                break;
            case(2):
                cout << "Enter name to find: " << endl;
                cin.ignore();
                getline(cin, nameInput);
                list.findByName(nameInput);
                break;
            case(3):
                cout << "Enter name to delete: " << endl;
                cin.ignore();
                getline(cin, nameInput);
                list.deleteByName(nameInput);
                break;
            default:
                cout << "Ending process, have a nice day." << endl;
                run = false;
                break;

        }


    }







}