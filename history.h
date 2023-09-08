#ifndef RPG_HISTORY_H
#define RPG_HISTORY_H

#include <iostream>
#include <string>
using namespace std;

struct element{
    element* next;
    string result;
};

class history {
    element* head;
    element* tail;
    int N;

public:
    history();
    ~history();
    element* addBattle(string);
    element* delBattle();
    void display_history();

};


#endif //RPG_HISTORY_H
