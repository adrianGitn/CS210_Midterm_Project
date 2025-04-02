#ifndef SCHOOL_H
#define SCHOOL_H
using namespace std;

struct School {
    string name;
    string address;
    string city;
    string state;
    string county;
    School* next;
};

#endif //SCHOOL_H
