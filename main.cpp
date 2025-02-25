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
    list.display();

    list.deleteByName("KELLAR PRIMARY SCHOOL");

    list.display();

    list.findByName("PLEASANT VALLEY MIDDLE SCHOOL");






}
