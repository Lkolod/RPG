#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H

#include <string>
#include <fstream>
#include <iostream>
#include "hero.h"
#include "profession.h"

using namespace std;

class character :public hero{

private:
    int profession = 0;
    int level = 0;

public:
    friend class Mage;
    friend class warrior;
    friend class berserker;
    friend class thief;
    friend class monsters;

    character();
    character(string,int,int,int,int,int);
    character(string);
    void setProfession();
    ~character();
    void save();
    void dispStats() override;
    void dispName();
    int get_s() override;
    int get_d() override;
    int get_e() override;
    int get_i() override;
    int get_c() override;
    void gain_exp(int);
    void level_up();
    int attack();
    void set_S(int);
    void set_I(int);
    void set_C(int);
    void set_D(int);
    void set_E(int);

};


#endif //RPG_CHARACTER_H
