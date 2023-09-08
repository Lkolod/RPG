#include "character.h"

#include <utility>

using namespace std;

void class_display(int prof){
    if(prof == 1) cout << "berserker" << endl;
    else if(prof == 2) cout << "thief"<< endl;
    else if(prof == 3) cout << "warrior"<< endl;
    else if(prof == 4) cout << "mage"<< endl;
    else if(prof == 0) cout << "no profession"<< endl;
}

character::character() = default;

character::character(string newname, int newstrength, int newdexterity, int newendutance, int newintelligence, int newcharisma) {
    name = std::move(newname);
    strength = newstrength;
    dexterity = newdexterity;
    endurance = newendutance;
    intelligence = newintelligence;
    charisma = newcharisma;
}

character::character(string character_file) {

    fstream file;
    name = std::move(character_file);
    file.open(name +".txt", ios::in);
    if (file.good()) {
        file >> name >>  strength >> dexterity >> endurance >> intelligence >> charisma >> profession >> experience >> level;
    }
    else {
        cout << "wrong file";
    }
    file.close();

}

character::~character() = default;

void character::save(){
    fstream file;

    file.open(name+".txt", ios::out);
    if (file.good()) {
        file << name << " " << strength << " " << dexterity << " " << endurance << " " << intelligence << " "
             << charisma << " " << profession << " " <<experience << " " << level;
    }
    else {
        cout << "wrong file";
    }
    file.close();
}

void character::dispStats() {
    cout<<"Statistics of: "<<name<<endl;
    cout<<"Strength = "<<strength<<endl;
    cout<<"Dexterity = "<<dexterity<<endl;
    cout<<"Endurance = "<<endurance<<endl;
    cout<<"Intelligence = "<<intelligence<<endl;
    cout<<"Charisma = "<<charisma<<endl;
    cout<<"level = "<<level<<endl;
    cout<<"experience  = "<<experience<<endl;
    cout << "profession = "; class_display(profession);
    cout << endl;
}

int character::get_s(){
    return strength;
}

int character::get_d(){
    return dexterity;
}
int character::get_e(){
    return endurance;
}
int character::get_i(){
    return intelligence;
}
int character::get_c(){
    return charisma;
}
void character::dispName() {
    cout << name;
}
void character::setProfession() {
    if(profession == 0 ){
    cout << "choose profession of your character" << endl;
    cout << "mage: select 1" << endl;
    cout << "warrior: select 2" << endl;
    cout << "berserker: select 3" << endl;
    cout << "thief: select 4" << endl;

    int choice  = 0;
    cin>>choice;


    switch (choice) {
        case 1:
            Mage::increase_stats(&intelligence);
            profession = 4;
            break;

        case 2:
            warrior::increase_stats(&endurance);
            profession = 3;
            break;

        case 3:
            berserker::increase_stats(&strength);
            profession = 1;
            break;

        case 4:
            thief::increase_stats(&dexterity);
            profession = 2;
            break;
        default:
            cout << "you have chosen wrong number" << endl;
    }
    }
    else
        cout << "you have already chosen profession" << endl;

}

int character::attack() {
    if(profession == 4) return intelligence;
    else if(profession == 2) return dexterity;
    else return strength;
}
void character::level_up() {
    if (experience < level * 10) {
        cout << "your current experience is:" << experience << endl;
        cout << "\nto level up you need: " << level * 10 << "experience points" << endl;
    }
    else if(experience >= level * 10){
        experience = experience - level * 10;
        cout << "level up your statistic" << endl;
        cout << "1: strength" << endl;
        cout << "2: dexterity" << endl;
        cout << "3: endurance" << endl;
        cout << "4: intelligence" << endl;
        cout << "5: charisma" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                strength += 1;
                cout << "you successfully added strength to your statistics " << endl;
                break;
            case 2:
                dexterity += 1;
                cout << "you successfully added strength to your dexterity " << endl;
                break;
            case 3:
                endurance += 1;
                cout << "you successfully added strength to your endurance " << endl;
                break;
            case 4:
                intelligence += 1;
                cout << "you successfully added strength to your intelligence " << endl;
                break;
            case 5:
                charisma += 1;
                cout << "you successfully added strength to your charisma " << endl;
                break;
            default:
                cout << "select proper number" << endl;

        }
    }


}
void character::gain_exp(int exp) {
    experience += exp;
    if (experience < 0) experience = 0;
}
void character::set_S(int add) {
    strength += add;
}

void character::set_E(int add) {
    endurance += add;
}

void character::set_I(int add) {
    intelligence += add;
}

void character::set_D(int add) {
    dexterity += add;
}

void character::set_C(int add) {
    charisma += add;
}

