#include <string>
#include <iostream>
#include <list>
#include <vector>

using namespace std;
struct hashSchool
{
    string name;
    string address;
    string city;
    string state;
    string county;

    hashSchool(string n = "", string a = "", string c = "", string s = "", string cty = ""): name(n), address(a), city(c), state(s), county(cty) {}

};

class SchoolHashTable
{
private:
    int size = 10;
    int items = 0;
    vector<list<hashSchool>> table;

    int hashFunction(string key) {
        int hash = 0;
        for (char ch : key) {
            hash += ch;
        }
        return hash % size;
    }

public:
    SchoolHashTable() {
        table.resize(size);
    }

    void insert(hashSchool school)
    {
        int index = hashFunction(school.name);
        table[index].push_back(school);
        items++;
    }

    void deleteByName(string name)
    {
        int index = hashFunction(name);

        for (auto i = table[index].begin(); i != table[index].end();) {
            if ((*i).name == name) {
                i = table[index].erase(i);
                items--;
            }
            else
            {
                i++;
            }
        }

    }

    void findByName(string name)
    {
        int index = hashFunction(name);
        list<hashSchool>::iterator i = table[index].begin();
        while (i != table[index].end()) {
            if ((*i).name == name)
            {
                cout << (*i).name << endl;
                cout << (*i).address << endl;
                cout << (*i).city << endl;
                cout << (*i).state << endl;
                cout << (*i).county << endl;
            }
            ++i;
        }


    }

    void display()
    {
        for (int i = 0; i < size; i++) {
            if (!table[i].empty()) {
                cout << "Bucket " << i << ":\n";
                for (hashSchool school : table[i]) {
                    cout << "Name: " << school.name << endl;
                    cout << "Address: " << school.address << endl;
                    cout << "City: " << school.city << endl;
                    cout << "State: " << school.state << endl;
                    cout << "County: " <<school.county << endl;
                    cout << "---\n";
                    cout << i << endl;
                }
                cout << "\n";

            }
        }
    }
};
