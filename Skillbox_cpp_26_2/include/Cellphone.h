#pragma once
#include <vector>
#include "Contact.h"


class Cellphone{
    enum CMD{
        ADD,
        CALL,
        SMS,
        EXIT,
        NONE
    };
    std::string CMD_STR[5] = {"add","call","sms","exit",""};
    std::vector<Contact> contacts;

    CMD command=NONE;

    void add(){
        Contact* new_contact = new Contact;
        new_contact->inputName();
        new_contact->inputNumber();
        contacts.push_back(*new_contact);
        delete new_contact;
        new_contact= nullptr;
    }

    Contact* findNumber(){
        std::string name=Contact::inputString();
        bool useNumber=Contact::validNumber(name);
        for(int i=0;i<contacts.size();++i)
            if(useNumber&&contacts[i].getNumber()==name) return &contacts[i];
            else if(!useNumber&&contacts[i].getName()==name) return &contacts[i];
        Contact* contact = new Contact;
        contact->setName("Nothing");
        contact->setNumber("");
        return contact;
    }

    void call(){
        std::cout << "Input name or number:";
        Contact* contact = findNumber();
        std::cout<< "CALL "<<contact->getNumber() << std::endl;
    }
    void sms(){
        std::string smsText;
        std::cout << "Input name or number:";
        Contact* contact = findNumber();
        std::cout<<"Input Text:";
        std::cin>> smsText;
        std::cout<< "SMS to "<<contact->getNumber() <<std::endl
                    <<"Text:"<< smsText<< std::endl;
    }

    CMD inputCommand(){
        CMD command=NONE;
        std::string input;
        std::cout<<"Input command[";
        for(int i=0;i<4;++i) std::cout<<CMD_STR[i] <<",";
        std::cout<<"]:";
        std::cin >> input;
#define CMDSTRTOINT(comm) (input==CMD_STR[comm] ) command=comm;
        if(input==CMD_STR[ADD]) command=ADD;
        else if CMDSTRTOINT(CALL)
        else if CMDSTRTOINT(SMS)
        else if CMDSTRTOINT(EXIT)
        else if CMDSTRTOINT(NONE)
#undef CMDSTRTOINT
        if(command==NONE) std::cout <<"Try again"<<std::endl;
        return command;
    }

public:
    
    void turnOn() {
        while (command == NONE) {
            while (command == NONE) command = inputCommand();
            switch (command) {
                case ADD:
                    add();
                    break;
                case SMS:
                    sms();
                    break;
                case CALL:
                    call();
                    break;
                case NONE:
                    break;
                case EXIT:
                    return;
            }
            command = NONE;
        }
    }
};