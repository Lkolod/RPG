//
// Created by kolod on 20.06.2023.
//
#include <string>
#ifndef RPG_HERO_H
#define RPG_HERO_H
using namespace std;

class hero {

protected:
    string name{};
    int strength{};
    int dexterity{};
    int endurance{};
    int intelligence{};
    int charisma{};
    int experience{};

public:
    virtual void dispStats() =0;
    virtual int get_s() = 0;
    virtual int get_d() =0;
    virtual int get_e() =0;
    virtual int get_i() = 0;
    virtual int get_c() =0;

};


#endif //RPG_HERO_H
