#ifndef RPG_ITEMS_H
#define RPG_ITEMS_H

#include <string>
#include "character.h"
#include <map>
#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>


using namespace std;

struct itemNode {
    string name;
    char attrType;
    int attrValue;
    int rarity;
    int quantity = 0;
    bool isEquipped = false;
    struct itemNode *next;
    struct itemNode *prev;
};

class items {
public:

    void load_items();
    void display_items();
    void display_equipped_items();
    void add_element(string, char, int, int);
    void create_list(string, char, int, int);

    void equipItem(int, character*);
    void unequipItem(int, character*);
    void addItem(int);

    int getS();
    int getI();
    int getC();
    int getE();
    int getD();

    items();
    itemNode* start;
    map<char, string> attrmap;
    map<int, string> rarmap;

};


#endif //RPG_ITEMS_H
