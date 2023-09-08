#include "monsters.h"

monsters::monsters() {
    name = "monster";
    strength = rand()%10 +1;
    dexterity = rand()%10 +1;
    endurance = rand()%10 +1;
    intelligence = rand()%10 +1;
    charisma = rand()%10 +1;
    experience = rand()%10 +1;

}
void monsters::dispStats() {
    cout<<"Statistics of: "<<name<<endl;
    cout<<"Strength = "<<strength<<endl;
    cout<<"Dexterity = "<<dexterity<<endl;
    cout<<"Endurance = "<<endurance<<endl;
    cout<<"Intelligence = "<<intelligence<<endl;
    cout<<"Charisma = "<<charisma<<endl;
    cout<<"experience = "<<experience<<endl;
    cout << endl;
}
int monsters::get_s(){
    return strength;
}

int monsters::get_d(){
    return dexterity;
}
int monsters::get_e(){
    return endurance;
}
int monsters::get_i(){
    return intelligence;
}
int monsters::get_c(){
    return charisma;
}
int monsters::get_exp(){
    return experience;
}


