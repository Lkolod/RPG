
#ifndef RPG_PROFESSION_H
#define RPG_PROFESSION_H
#include "character.h"
#include "hero.h"


class Mage :public hero{
public:
    friend class character;
    static void increase_stats(int*);
};

class warrior :public hero{
public:
    friend class character;
    static void increase_stats(int*);
};

class berserker: public hero{
public:
    friend class character;
    static void increase_stats(int*);
};
class thief: public hero{
public:
    friend class character;
    static void increase_stats(int*);
};

#endif //RPG_PROFESSION_H
