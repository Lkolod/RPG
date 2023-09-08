#ifndef RPG_MONSTERS_H
#define RPG_MONSTERS_H
#include "character.h"
#include <string>
#include <fstream>

using namespace std;

class monsters: public hero {
    public:
        monsters();
        void dispStats() override;
        int get_s() override;
        int get_d() override;
        int get_e() override;
        int get_i() override;
        int get_c() override;
        int get_exp();
};


#endif //RPG_MONSTERS_H
