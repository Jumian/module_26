#pragma once
#include "Coord.h"
class Windows;

class Coord;

class Screen{
    int width = 80, height =50;
    Coord size;
    bool screen[50][80];

    
public:
    const Coord* getSize(){return &size;}
    const int getWidth(){return width;}
    const int getHeight(){return height;}
    void clear(){
        size.setXY(width,height);
        for(int j=0;j<50;++j)
            for(int i=0;i<80;++i) screen[j][i]= false;
    }
    void placeWindow(Coord* coord1,Coord * coord2){
        clear();
        Coord curr;
        curr.setXY(0,0);
        for(int j=0;j<50;++j) {
            curr.setY(j);
            for (int i = 0; i < 80; ++i) {
                curr.setX(i);
                screen[j][i]=Coord::coordsInRectangle(coord1,coord2,&curr);
            }
        }
    }
    void show(){

        for(int j=0;j<50;++j) {
            for (int i = 0; i < 80; ++i) std::cout << (screen[j][i]?"1":"0");
            std::cout <<std::endl;
        }
    }

};
