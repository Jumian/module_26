#include <iostream>
#include "Cellphone.h"

int main() {
    Cellphone* cellphone = new Cellphone;
    cellphone->turnOn();
    delete cellphone;
    cellphone = nullptr;

}
