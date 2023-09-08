
#include "profession.h"

void Mage::increase_stats(int *intelligence){
    *intelligence += 10;
}
void warrior::increase_stats(int *endurance){
    *endurance += 10;
}
void berserker::increase_stats(int *strength){
    *strength  += 10;
}
void thief::increase_stats(int *dexterity){
    *dexterity  += 10;
}
