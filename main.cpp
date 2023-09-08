#include <iostream>
#include <utility>
#include "character.h"
#include "monsters.h"
#include "history.h"
#include "items.h"

using namespace std;

character* create_new(){

    fstream file;
    string text;

    string temp_name;
    int temp_strength;
    int temp_dexterity;
    int temp_endurance;
    int temp_intelligence;
    int temp_charisma;

    cout<<"Set name of character: ";
    cin>>temp_name;
    cout<<"Set strength of character: ";
    cin>>temp_strength;
    cout<<"Set dexterity of character: ";
    cin>>temp_dexterity;
    cout<<"Set endurance of character: ";
    cin>>temp_endurance;
    cout<<"Set intelligence of character: ";
    cin>>temp_intelligence;
    cout<<"Set charisma of character: ";
    cin>>temp_charisma;

    return new character(temp_name,temp_strength,temp_dexterity, temp_endurance, temp_intelligence, temp_charisma);
}

character* load_character(string name){
    return new character(std::move(name));

}
void save_monsters(monsters* MONSTERS){
    fstream file;
    file.open("monsters.txt", ios::out);
    if(file.good()) {
        for(int i =0; i<5; i++ ){
            file<<"Monster "<<i+1<<endl;
            file<<MONSTERS[i].get_s()<<endl;
            file<<MONSTERS[i].get_d()<<endl;
            file<<MONSTERS[i].get_e()<<endl;
            file<<MONSTERS[i].get_i()<<endl;
            file<<MONSTERS[i].get_c()<<endl;
            file<<MONSTERS[i].get_exp()<<endl;
        }
        cout << "you succesfully saved monsters";
    }
}
template <class T>
class Battle {
public:
        int fight(T chara, monsters *rival) {
        int hero_hp = chara->get_e() * 10;
        int monster_hp = rival->get_e() * 10;


        while (hero_hp > 0 && monster_hp > 0) {
            cout << "current health of hero is: " << hero_hp << endl;
            cout << "current health of monster is: " << monster_hp << endl;
            cout << "\n\n\n\n";

            cout << "press anything to throw a dice" << endl;
            int dice;
            cin >> dice;
            int dice_throw1 = rand() % 6 + 1;
            int dice_throw2 = rand() % 6 + 1;

            cout << "hero throw: " << dice_throw1<< endl;
            cout << "monster throw: " << dice_throw2<< endl;

            hero_hp -= rival->get_s()*dice_throw1;
            monster_hp -= chara->attack()*dice_throw1;
        }if(hero_hp > 0) return 1;
        return 0;
    }
};


int main() {

    character* chara = nullptr;
    auto* MONSTER = new monsters[5];
    Battle<character*> combat;
    bool salacted_character = false;
    bool generated_monsters = false;

    history battle_hist;

    struct itemNode* head = nullptr;
    items items_list;
    items_list.load_items();

    while(true) {
        cout << "chose your action" << endl;
        cout << "1: load character" << endl;
        cout << "2: create new character " << endl;
        cout << "3: save character " << endl;
        cout << "4: display statistics of current character" << endl;
        cout << "5: select profession " << endl;
        cout << "6: generate monsters " << endl;
        cout << "7: save monsters" << endl;
        cout << "8: level up" << endl;
        cout << "9: fight monsters" << endl;
        cout << "10: show battle history" << endl;
        cout << "11: display your items" << endl;
        cout << "12: display equipped items" << endl;
        cout << "13: equip item" << endl;
        cout << "14: unequip item" << endl;
        cout << "15: exit" << endl;

        int choise;
        cin >> choise;

        switch (choise) {
            case 1: {
                string character_choice;
                cout << "write name of your character" << endl;
                cin >> character_choice;
                chara = load_character(character_choice);
                cout << "you have chosen: " << endl;
                chara->dispName();
                cout << '\n';
                salacted_character = true;
                break;
            }
            case 2:
                chara = create_new();
                salacted_character = true;
                break;
            case 3:
                if(salacted_character) {
                    chara->save();
                }
                break;
            case 4:
                if(salacted_character) {
                    chara->dispStats();
                }
                break;
            case 5:
                if(salacted_character) {
                    cout << '\n';
                    chara->setProfession();
                }
                break;
            case 6:
                for(int i=0;i<5;i++) {
                    MONSTER[i] = monsters();
                    cout<<"Monster "<<i+1<<" with stats: "<<endl;
                    MONSTER[i].dispStats();
                    cout<<"\n";
                    generated_monsters = true;
                }
                break;
            case 7:
                if (generated_monsters) {
                    save_monsters(MONSTER);
                }
                break;
            case 8:
                if(salacted_character) {
                    chara->level_up();
                }
                break;
            case 9:
                if(salacted_character && generated_monsters) {
                    cout << "Choose monster to fight from 1-5" << endl;
                    int monster_choice;
                    cin >> monster_choice;

                    if (monster_choice < 1 || monster_choice > 5) {
                        cout << "there is no such monster" << endl;
                        break;
                    } else {
                        if (combat.fight(chara, &MONSTER[monster_choice - 1]) == 1) {
                            cout << "your hero won the battle" << endl;
                            cout << "gained experience: " << MONSTER[monster_choice - 1].get_exp() << endl;
                            chara->gain_exp(MONSTER[monster_choice - 1].get_exp());
                            battle_hist.addBattle("Hero won a battle and gain " + to_string(MONSTER[monster_choice - 1].get_exp()) + "experience points");
                            items_list.addItem((rand()%60+1));

                        } else {
                            cout << "monster won a battle" << endl;
                            cout << "lost experience: " << MONSTER[monster_choice - 1].get_exp() << endl;
                            chara->gain_exp(-MONSTER[monster_choice - 1].get_exp());
                            battle_hist.addBattle("Monster won a battle and lost " + to_string(MONSTER[monster_choice - 1].get_exp()) + "experience points");
                        }
                    }
                }
                break;
            case 10:
                battle_hist.display_history();
                break;
            case 11:
                items_list.display_items();
                break;

            case 12:
                items_list.display_equipped_items();
                break;


            case 13:
                int choice;
                cout<<"Select item to equip by ID: "<<endl;
                cin>>choice;
                items_list.equipItem(choice, chara);
                break;

            case 14:
                cout<<"Select item to unequip by ID: "<<endl;
                cin>>choice;
                items_list.unequipItem(choice, chara);
                break;

            case 15:
                exit(0);

            default:
                cout << "Please enter valid choice" << endl;

        }
    }
    return 0;
}
