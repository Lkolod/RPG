#include "items.h"
items::items() {
    start = nullptr;

    attrmap['s'] = "strength";
    attrmap['d'] = "dexterity";
    attrmap['e'] = "endurance";
    attrmap['i'] = "intelligence";
    attrmap['c'] = "charisma";

    rarmap[1] = "Common";
    rarmap[2] = "Rare";
    rarmap[3] = "Epic";
    rarmap[4] = "Legendary";

}

void items::add_element(string item_name, char type, int value, int rar) {

    if( start == nullptr) {
        cout<<" no list created" <<endl;
        return;
    }
    auto *newitem = new(struct itemNode);
    newitem->name = item_name;
    newitem->attrType = type;
    newitem->attrValue = value;
    newitem->rarity = rar;

    newitem->prev = nullptr;
    newitem->next = start;
    start->prev = newitem;
    start = newitem;
}

void items::load_items() {

    fstream file;
    file.open("items.txt", ios::in);

    if(file.good()) {
        string temp_name;
        char temp_attrName;
        int temp_attrN;
        int temp_rarity;

        file >> temp_name >> temp_attrName >> temp_attrN>> temp_rarity;

        for (char & i : temp_name) {
            if (i == '_') {
                i = ' ';
            }
        }
        create_list(temp_name,temp_attrName,temp_attrN,temp_rarity);

        while(!file.eof()) {
            file >> temp_name >> temp_attrName >> temp_attrN>> temp_rarity;
            if(file.eof()) break;

            for (char & i : temp_name) {
                if (i == '_') {
                    i = ' ';
                }
            }

            add_element(temp_name, temp_attrName, temp_attrN, temp_rarity);
        }
    }
    else {
        cout<<"x";
    }

}

void items::display_items() {
    auto* ptr = start;


    cout<<setw(5)<<"ID"<<setw(30)<<"Item Name"<<setw(15)<<"Buff Type"<<setw(10)<<"Value"<<setw(15)<<"Rarity"<<setw(10)<<"Quantity"<<endl;
    int i = 0;
    while(ptr != nullptr) {
        i++;
        if (ptr->quantity > 0) {

            cout << setw(5) << i << setw(30) << ptr->name << setw(15) << attrmap[ptr->attrType] << setw(10)
                 << ptr->attrValue << setw(15) << rarmap[ptr->rarity] << setw(10) << ptr->quantity << endl;
        }

        ptr = ptr->next;

    }

}
void items::display_equipped_items() {
    auto* ptr = start;


    cout<<setw(5)<<"ID"<<setw(30)<<"Item Name"<<setw(15)<<"Buff Type"<<setw(10)<<"Value"<<setw(15)<<"Rarity"<<setw(10)<<"Quantity"<<endl;
    int i = 0;
    while(ptr != nullptr) {
        i++;
        if (ptr->quantity > 0 && ptr->isEquipped) {

            cout << setw(5) << i << setw(30) << ptr->name << setw(15) << attrmap[ptr->attrType] << setw(10)
                 << ptr->attrValue << setw(15) << rarmap[ptr->rarity] << setw(10) << ptr->quantity << endl;
        }

        ptr = ptr->next;

    }

}

void items::create_list(string newname, char newtype, int newval, int newrar) {

    struct itemNode* s;
    struct itemNode* temp;
    temp = new(struct itemNode);
    temp->name = newname;
    temp->attrType = newtype;
    temp->attrValue = newval;
    temp->rarity = newrar;

    temp->next = nullptr;

    if(start == nullptr) {
        temp->prev = nullptr;
        start = temp;
    }
    else {
        s = start;
        while (s->next != nullptr) {
            s = s->next;
            s->next = temp;
            temp->prev = s;
        }
    }
}

void items::equipItem(int ID, character* postac) {
    auto* ptr = start;
    int i = 1;
    while(ptr != nullptr) {
        if(i == ID) {

            if(ptr->quantity < 1) {
                cout<<"You dont have this item"<<endl;
                return;
            }
            else if(ptr->isEquipped) {
                cout<<"This item is already equipped"<<endl;
                return;
            }

            ptr->isEquipped = true;

            switch (ptr->attrType) {
                case 's':
                    postac->set_S(ptr->attrValue);
                    break;
                case 'i':
                    postac->set_I(ptr->attrValue);
                    break;
                case 'c':
                    postac->set_C(ptr->attrValue);
                    break;
                case 'd':
                    postac->set_D(ptr->attrValue);
                    break;
                case 'e':
                    postac->set_E(ptr->attrValue);
                    break;

                default:
                    cout<<"Something went wrong"<<endl;
                    break;

            }

            return;
        }
        ptr = ptr->next;
        i++;
    }
    cout<<"Item ID out of range"<<endl;
}

void items::unequipItem(int ID, character* postac) {
    auto* ptr = start;
    int i = 1;
    while(ptr != nullptr) {
        if(i == ID) {

            if(ptr->quantity < 1) {
                cout<<"You dont have this item"<<endl;
                return;
            }
            else if(!ptr->isEquipped) {
                cout<<"This item isnt equipped"<<endl;
                return;
            }
            ptr->isEquipped = false;

            switch (ptr->attrType) {
                case 's':
                    postac->set_S(-ptr->attrValue);
                    break;
                case 'i':
                    postac->set_I(-ptr->attrValue);
                    break;
                case 'c':
                    postac->set_C(-ptr->attrValue);
                    break;
                case 'd':
                    postac->set_D(-ptr->attrValue);
                    break;
                case 'e':
                    postac->set_E(-ptr->attrValue);
                    break;

                default:
                    cout<<"Something went wrong"<<endl;
                    break;

            }

            return;
        }
        ptr = ptr->next;
        i++;
    }

    cout<<"Item ID out of range"<<endl;
}

void items::addItem(int ID) {
    auto* ptr = start;
    int i = 1;
    while(ptr != nullptr) {
        if(i == ID) {
            ptr->quantity += 1;
            cout<<"Congrats, you got: "<<ptr->name<<endl;
            return;
        }
        ptr = ptr->next;
        i++;
    }
    cout<<"No new items "<<endl;

}


int items::getS() {
    int s = 0;
    auto* ptr = start;
    while(ptr != nullptr) {

        if(ptr-> isEquipped && ptr->attrType == 's') s += ptr->attrValue;
        ptr = ptr->next;
    }
    return s;
}

int items::getI() {
    int s = 0;
    auto* ptr = start;
    while(ptr != nullptr) {

        if(ptr-> isEquipped && ptr->attrType == 's') s += ptr->attrValue;
        ptr = ptr->next;
    }
    return s;
}

int items::getD() {
    int s = 0;
    auto* ptr = start;
    while(ptr != nullptr) {

        if(ptr-> isEquipped && ptr->attrType == 's') s += ptr->attrValue;
        ptr = ptr->next;
    }
    return s;
}

int items::getE() {
    int s = 0;
    auto* ptr = start;
    while(ptr != nullptr) {

        if(ptr-> isEquipped && ptr->attrType == 's') s += ptr->attrValue;
        ptr = ptr->next;
    }
    return s;
}

int items::getC() {
    int s = 0;
    auto* ptr = start;
    while(ptr != nullptr) {

        if(ptr-> isEquipped && ptr->attrType == 's') s += ptr->attrValue;
        ptr = ptr->next;
    }
    return s;
}
