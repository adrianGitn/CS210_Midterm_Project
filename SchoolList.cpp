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

    void display()
    {
        School* temp = head;
        while (temp != nullptr)
        {
            cout << temp->name << "," << temp->address << "" << temp->city << "," << temp->state << "," << temp->county << endl;
            temp = temp->next;
        }

    }

};

