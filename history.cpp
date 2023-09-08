#include "history.h"
history::history() {
    head = nullptr;
    tail = nullptr;
    N = 0;
}
history::~history() {
    element* el;
    while(head){
        el = head->next;
        delete head;
        head = el;
    }
}

element* history::delBattle() {
    element * el;
    if(tail){
        el = tail;
        if(el == head) head= tail = nullptr;
        else {
            tail = head;
            while(tail ->next != el) tail = tail ->next;
            tail->next = nullptr;
        }
        N--;
        return el;
    }
    else return nullptr;
}
element* history::addBattle(string battle_result) {
    auto* ELEMENT = new element;
    ELEMENT->result = battle_result;
    ELEMENT->next = head;
    head = ELEMENT;
    if(!tail) tail = head;
    N++;
    if(N >= 11) {
        delBattle();
    }
    return head;
}
void history::display_history() {
    element* el;
    int i = 1;
    if(!head) cout << "there is no battle yet" << endl;
    else{
        el = head;
        while(el){
            cout << "battle no.: " << i <<" " << el->result << endl;
            el = el ->next;
            i++;
        }
    }

}