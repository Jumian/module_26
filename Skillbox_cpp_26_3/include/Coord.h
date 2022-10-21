#pragma once
#include <iostream>
#include "Validator.h"


class Coord {
    int x=0, y=0;

public:
    void setX(int new_x){x=new_x;}
    void setY(int new_y){y=new_y;}
    const int X() const {return x;}
    const int Y() const {return y;}
    void setXY(int new_x, int new_y){
        setX(new_x);
        setY(new_y);
    }
    void copy(Coord* new_coord){
        setXY(new_coord->X(),new_coord->Y());
    }
    void move(Coord* vector){
        x+=vector->x;
        y+=vector->y;
    }
    static int inputInt(std::string prompt){
        std::string input=" ";
        bool notNumber=true;
        while(notNumber) {
            std::cout << prompt;
            std::cin >> input;
            notNumber=!Validator::isNumberInt(input);
            if(notNumber)std::cout << "Try again" << std::endl;
            else break;
        }
        return std::stoi(input);
    }
    void input_coord() {
        x= inputInt("Input X:");
        y= inputInt("Input Y:");
    }
    static bool coordsOnScreen (const Coord * coord,const Coord * size){
        if(coord->x<0||coord->y<0) return false;
        if (size->X()<coord->x && size->Y()<coord->y) return false;
        return true;
    }
    static bool coordsInRectangle(Coord *coordRec1,Coord *coordRec2, Coord* coord){
        int maxX,minX,maxY,minY,X,Y;
        X=coord->X();
        Y=coord->Y();
        if (coordRec1->X()>coordRec2->X()){
            maxX=coordRec1->X();minX=coordRec2->X();
        }else {
            maxX=coordRec2->X();minX=coordRec1->X();
        }
        if (coordRec1->Y()>coordRec2->Y()){
            maxY=coordRec1->Y();minY=coordRec2->Y();
        }else {
            maxY=coordRec2->Y();minY=coordRec1->Y();
        }
        return (X<=maxX&&X>=minX)&&(Y<=maxY&&Y>=minY);
    }
};