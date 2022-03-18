// File Inventory.cpp
// Berisi implementasi class Inventory

#include <iostream>
#include "Inventory.h"

Inventory::Inventory() {
    this->slot = new SlotInventory[27];
    for (int i=0; i<27; i++) {
        string id = "I" + to_string(i);
        this->slot[i].setId(id);
    }
}

Inventory::~Inventory() {
    delete[] this->slot;
}

Inventory::Inventory(const Inventory& other) {
    for (int i=0; i<27; i++) {
        this->slot[i] = other.slot[i];
    }
}

Inventory& Inventory::operator=(const Inventory& other) {
    delete[] this->slot;
    for (int i=0; i<27; i++) {
        this->slot[i] = other.slot[i];
    }
    return *this;
}

int Inventory::countSlotEmpty() {
    int count = 0;
    for (int i=0; i<27; i++) {
        if (this->slot[i].getPointerItem() == NULL) {
            count++;
        }
    }
    return count;
}

int Inventory::findIndexEmpty() {
    for (int i=0; i<27; i++) {
        if (this->slot[i].getPointerItem() == NULL) {
            return i;
        }
    }
    return -1;
}

int Inventory::findIndexItem(Item* ptr) {
    for (int i=0; i<27; i++) {
        if (this->slot[i].getPointerItem() == ptr && this->slot[i].getQuantity() < 64) {
            return i;
        }
    }
    return -1;
}

int Inventory::findIndexBySlotId(string id) {
    for (int i=0; i<27; i++) {
        if (this->slot[i].getId() == id) {
            return i;
        }
    }
    return -1;
}


int Inventory::getQuantityAtIndex(int index) {
    return this->slot[index].getQuantity();
}

string Inventory::getItemNameAtIndex(int index) {
    return this->getPtrItemAtIndex(index)->getName();
}

Item* Inventory::getPtrItemAtIndex(int index) {
    return this->slot[index].getPointerItem();
}

void Inventory::addQuantityAtIndex(int index, int quantity) {
    this->slot[index].addQuantity(quantity);
}

void Inventory::setQuantityAtIndex(int index, int quantity) {
    this->slot[index].setQuantity(quantity);
}

void Inventory::setPtrItemAtIndex(int index, Item* ptr) {
    this->slot[index].setPointerItem(ptr);
}

bool Inventory::isSlotEmptyAtIndex(int index) {
    return this->slot[index].getPointerItem() == NULL;
}

SlotInventory* Inventory::getSlots() {
    return this->slot;
}

void Inventory::print() {
    for (int i=0; i<27; i++) {
        cout << "[" << this->slot[i].getId() << " " << this->slot[i].getQuantity() << "] ";
        if (i%9 == 8) {
            cout << endl;
        } 
    }
}