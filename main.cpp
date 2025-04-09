#include <fstream>
#include <iostream>
#include "CSVReader.h"
#include "SchoolList.cpp"
#include "SchoolBST.h"
#include "SchoolHashTable.cpp"
#include "timer.h"

using namespace std;

int main() {
    SchoolList list;
    SchoolList list2;

    SchoolBST bst;
    SchoolBST bst2;

    SchoolHashTable hashTable;
    SchoolHashTable hashTable2;
    // sets every table for each dataset

    CSVReader reader;

    // sets CSV files
    std::fstream usaFile("USATimeTable.csv");
    if (!usaFile.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    usaFile << "Data Structure Operation, Dataset Size, Time(microseconds)" << endl;

    std::fstream ilFile("ILTimeTable.csv");
    if (!ilFile.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    ilFile << "Data Structure Operation, Dataset Size, Time(microseconds)" << endl;


    //creates vector of data to insert for each data set
    vector<vector<string>> ilVector;
    ilVector = reader.readCSV("Illinois_Schools.csv");

    vector<vector<string>> usaVector;
    usaVector = reader.readCSV("USA_Schools.csv");

    // illinois schools list insert algorithm
    Timer listILInsertTimer;
    listILInsertTimer.start();
    for (size_t i = 1; i < ilVector.size(); i++) {
        School ilSchoolsList(ilVector[i][0], ilVector[i][1], ilVector[i][2], ilVector[i][3], ilVector[i][4]);
        list.insertFirst(ilSchoolsList);
    }
    listILInsertTimer.stop();
    ilFile << "Linked List Insert" << "," << ilVector.size() << "," <<  listILInsertTimer.get_time() << endl;

    // usa schools list insert algorithm
    Timer listUSAInsertTimer;
    listUSAInsertTimer.start();
    for (size_t i = 1; i < usaVector.size(); i++) {
        School usaSchoolsList(usaVector[i][0], usaVector[i][1], usaVector[i][2], usaVector[i][3], usaVector[i][4]);
        list2.insertFirst(usaSchoolsList);
    }
    listUSAInsertTimer.stop();
    usaFile << "Linked List Insert" << "," << usaVector.size() << "," <<  listUSAInsertTimer.get_time() << endl;



    // illinois schools bst insert algorithm
    Timer bstILInsertTimer;
    bstILInsertTimer.start();
    for (size_t i = 1; i < ilVector.size(); i++)
    {
        BSTSchool ilSchoolsBST(ilVector[i][0], ilVector[i][1], ilVector[i][2], ilVector[i][3], ilVector[i][4]);
        bst.insert(ilSchoolsBST);
    }
    bstILInsertTimer.stop();

    ilFile << "Binary Search Tree Insert" << "," << ilVector.size() << "," << bstILInsertTimer.get_time() << endl;

    Timer bstUSAInsertTimer;
    bstUSAInsertTimer.start();
    for (size_t i = 1; i < usaVector.size(); i++)
    {
        BSTSchool usaSchoolsBST(usaVector[i][0], usaVector[i][1], usaVector[i][2], usaVector[i][3], usaVector[i][4]);
        bst2.insert(usaSchoolsBST);
    }
    bstUSAInsertTimer.stop();
    usaFile << "Binary Search Tree Insert" << "," << usaVector.size() << "," <<  bstUSAInsertTimer.get_time() << endl;


    // BST insert algorithm

    //hash Illinois table insert algorithm
    Timer hashILInsertTimer;
    hashILInsertTimer.start();
    for (size_t i = 1; i < ilVector.size(); i++)
    {
        hashSchool ilSchoolsHash(ilVector[i][0], ilVector[i][1], ilVector[i][2], ilVector[i][3], ilVector[i][4]);
        hashTable.insert(ilSchoolsHash);
    }
    hashILInsertTimer.stop();
    ilFile << "Hash Table Insert" << "," << ilVector.size() << "," <<  hashILInsertTimer.get_time() << endl;

    //hash USA table insert algorithm
    Timer hashUSAInsertTimer;
    hashUSAInsertTimer.start();
    for (size_t i = 1; i < usaVector.size(); i++)
    {
        hashSchool usaSchoolsHash(usaVector[i][0], usaVector[i][1], usaVector[i][2], usaVector[i][3], usaVector[i][4]);
        hashTable2.insert(usaSchoolsHash);
    }
    hashUSAInsertTimer.stop();
    usaFile << "Hash Table Insert" << "," << usaVector.size() << "," <<  hashUSAInsertTimer.get_time() << endl;





    //test list search timing
    Timer listILSearchTimer;
    listILSearchTimer.start();

    list.findByName("ALDEN-HEBRON HIGH SCHOOL");
    list.findByName("PUTNAM CO PRIMARY SCH");
    list.findByName("WALTHER LUTHERAN ACADEMY");

    listILSearchTimer.stop();

    ilFile << "Linked List Search" << "," << ilVector.size() << "," << listILSearchTimer.get_time() << endl;

    // test list usa search timing
    Timer listUSASearchTimer;
    listUSASearchTimer.start();

    list2.findByName("ALDEN-HEBRON HIGH SCHOOL");
    list2.findByName("PUTNAM CO PRIMARY SCH");
    list2.findByName("WALTHER LUTHERAN ACADEMY");

    listUSASearchTimer.stop();

    usaFile << "Linked List Search" << "," << usaVector.size() << "," << listUSASearchTimer.get_time() << endl;


    //test bst search timing
    Timer bstILSearchTimer;
    bstILSearchTimer.start();

    bst.find("ALDEN-HEBRON HIGH SCHOOL");
    bst.find("PUTNAM CO PRIMARY SCH");
    bst.find("WALTHER LUTHERAN ACADEMY");

    bstILSearchTimer.stop();
    ilFile << "Binary Search Tree Search" << "," << ilVector.size() << "," <<  bstILSearchTimer.get_time() << endl;

    // test bst usa search timing
    Timer bstUSASearchTimer;
    bstUSASearchTimer.start();

    bst2.find("ALDEN-HEBRON HIGH SCHOOL");
    bst2.find("PUTNAM CO PRIMARY SCH");
    bst2.find("WALTHER LUTHERAN ACADEMY");

    bstUSASearchTimer.stop();
    usaFile << "Binary Search Tree Search" << "," << usaVector.size() << "," <<  bstUSASearchTimer.get_time() << endl;


    //test hash search timing
    Timer hashILSearchTimer;
    hashILSearchTimer.start();

    hashTable.findByName("ALDEN-HEBRON HIGH SCHOOL");
    hashTable.findByName("PUTNAM CO PRIMARY SCH");
    hashTable.findByName("WALTHER LUTHERAN ACADEMY");

    hashILSearchTimer.stop();

    ilFile << "Hash Table Search" << "," << ilVector.size() << "," << hashILSearchTimer.get_time() << endl;

    //test hash usa
    Timer hashUSASearchTimer;
    hashUSASearchTimer.start();

    hashTable2.findByName("ALDEN-HEBRON HIGH SCHOOL");
    hashTable2.findByName("PUTNAM CO PRIMARY SCH");
    hashTable2.findByName("WALTHER LUTHERAN ACADEMY");

    hashUSASearchTimer.stop();

    usaFile << "Hash Table Search" << "," << usaVector.size() << "," << hashUSASearchTimer.get_time() << endl;


    //test list delete timing
    Timer listILDeleteTimer;
    listILDeleteTimer.start();

    list.deleteByName("ALDEN-HEBRON HIGH SCHOOL");
    list.deleteByName("PUTNAM CO PRIMARY SCH");
    list.deleteByName("WALTHER LUTHERAN ACADEMY");

    listILDeleteTimer.stop();

    ilFile << "Linked List Delete" << "," << ilVector.size() << "," << listILDeleteTimer.get_time() << endl;

    //test list delete timing
    Timer listUSADeleteTimer;
    listUSADeleteTimer.start();

    list2.deleteByName("ALDEN-HEBRON HIGH SCHOOL");
    list2.deleteByName("PUTNAM CO PRIMARY SCH");
    list2.deleteByName("WALTHER LUTHERAN ACADEMY");

    listUSADeleteTimer.stop();

    usaFile << "Linked List Delete" << "," << usaVector.size() << "," << listUSADeleteTimer.get_time() << endl;


    //test bst search timing
    Timer bstILDeleteTimer;
    bstILDeleteTimer.start();

    bst.deleteByName("ALDEN-HEBRON HIGH SCHOOL");
    bst.deleteByName("PUTNAM CO PRIMARY SCH");
    bst.deleteByName("WALTHER LUTHERAN ACADEMY");

    bstILDeleteTimer.stop();
    ilFile << "Binary Search Tree Delete" << "," << ilVector.size() << "," << bstILDeleteTimer.get_time() << endl;
    // test bst usa search
    Timer bstUSADeleteTimer;
    bstUSADeleteTimer.start();

    bst2.deleteByName("ALDEN-HEBRON HIGH SCHOOL");
    bst2.deleteByName("PUTNAM CO PRIMARY SCH");
    bst2.deleteByName("WALTHER LUTHERAN ACADEMY");

    bstUSADeleteTimer.stop();
    usaFile << "Binary Search Tree Delete" << "," << usaVector.size() << "," << bstILDeleteTimer.get_time() << endl;


    //test hash search timing
    Timer hashILDeleteTimer;
    hashILDeleteTimer.start();

    hashTable.deleteByName("ALDEN-HEBRON HIGH SCHOOL");
    hashTable.deleteByName("PUTNAM CO PRIMARY SCH");
    hashTable.deleteByName("WALTHER LUTHERAN ACADEMY");

    hashILDeleteTimer.stop();
    ilFile << "Hash Table Delete" << "," << ilVector.size() << "," << hashILDeleteTimer.get_time() << endl;

    //test hash usa search timing
    Timer hashUSADeleteTimer;
    hashUSADeleteTimer.start();

    hashTable2.deleteByName("ALDEN-HEBRON HIGH SCHOOL");
    hashTable2.deleteByName("PUTNAM CO PRIMARY SCH");
    hashTable2.deleteByName("WALTHER LUTHERAN ACADEMY");

    hashUSADeleteTimer.stop();
    usaFile << "Hash Table Delete" << "," << usaVector.size() << "," << hashILDeleteTimer.get_time() << endl;

}