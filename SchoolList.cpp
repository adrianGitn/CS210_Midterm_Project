#include <iostream>
using namespace std;

struct School {
    string name;
    string address;
    string city;
    string state;
    string county;
    School* next;

    School(string n = "", string a = "", string c = "", string s = "", string cty = "", School* nxt = nullptr): name(n), address(a), city(c), state(s), county(cty), next(nxt) {}
};

class SchoolList
{
    School* head;

public:
    SchoolList() : head(nullptr) {}

    void insertFirst(School& school)
    {
      School* temp = new School(school);
      temp->next = head;
      head = temp;
    }

    void insertLast(School& school)
    {
        School* newNode = new School(school);
        if(head==nullptr)
        {
            head = newNode;
        }else
        {
            School* temp = head;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteByName(const string& name)
    {
        if (head == nullptr)
            return;

        if (head->name == name)
        {
            School* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        School* current = head;
        while (current->next != nullptr && current->next->name != name)
        {
            current = current->next;
        }

        if (current->next != nullptr) {
            School* temp = current->next;
            current->next = temp->next;
            delete temp;
        }

    }

    void findByName(const string& name)
    {
        School* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                cout << "Name: " << current->name << endl;
                cout << "Address: " << current->address << endl;
                cout << "City: " << current->city << endl;
                cout << "State: " << current->state << endl;
                cout << "County: " << current->county << endl;
            }
            current = current->next;
        }
    }

    void display()
    {
        School* temp = head;
        while (temp != nullptr)
        {
            cout << temp->name << "," << temp->address << "," << temp->city << "," << temp->state << "," << temp->county << endl;
            temp = temp->next;
        }
        cout << endl;
    }

};

