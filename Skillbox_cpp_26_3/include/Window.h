#pragma once
#include <iostream>
#include "Coord.h"
#include "Screen.h"


class Window{
    int height=0,width=0;
    Coord coord[2];
    Screen screen;
    Coord size;
public:
    void init (){
        coord[0].setXY(10,10);
        setHeight(20);
        setWidth(30);
        screen.placeWindow(&coord[0],&coord[1]);
    }
    const Coord* getSize(){return &size;}
    enum CMD {
        MOVE,
        RESIZE,
        DISPLAY,
        CLOSE,
        NONE
    };
    std::string CMD_STR[4] = {"move","resize","display","close"};
    CMD input_CMD(){
        std::string input;
        std::cout<<"Input command:";
        std::cin >>input;
        for(int i=0;i<4;++i){
            if (input==CMD_STR[i]) return (CMD)i;
        }
        return NONE;
    }
    bool move(Coord* vector){
        Coord new_coords[2];
        new_coords[0].copy(&coord[0]);
        new_coords[1].copy(&coord[1]);
        for(int i=0;i<2;++i){
            new_coords[i].copy(&coord[i]);
            new_coords[i].move(vector);
            if (!Coord::coordsOnScreen(&new_coords[i],screen.getSize()))
            return false;
        }
        for(int i=0;i<2;++i)
            coord[i].copy(&new_coords[i]);
        return true;
    }
    void setHeight(int new_height){
        size.setY((new_height<0?0:new_height));
        completeCoords();
    }
    void setWidth(int new_width){
        size.setX((new_width<0?0:new_width));
        completeCoords();
    }
    bool resize(){
        Coord new_size;
        Coord new_corner;
        new_size.setXY(Coord::inputInt("Input Width:"),
                        Coord::inputInt("Input Height:"));
        new_corner.copy(&coord[0]);
        new_corner.move(&new_size);
        if(Coord::coordsOnScreen(&new_corner,screen.getSize())) {
            size.copy(&new_size);
            completeCoords();
            return true;
        }
        return false;
    }

    void show(){
        screen.placeWindow(&coord[0],&coord[1]);
        screen.show();
    }
    void completeCoords(){
        coord[1].copy(&coord[0]);
        coord[1].move(&size);
    }
    void control(){
        while (true){
            CMD cmd=NONE;
            while (cmd==NONE){
                cmd=input_CMD();
            };
            switch (cmd) {
                case MOVE:
                    {Coord vector;
                    vector.input_coord();
                    std::cout<<(move(&vector)?"":"Not move out of screen\n");}
                    break;
                case RESIZE:
                    std::cout<<(resize()?"":"Not move out of screen\n");
                    break;
                case DISPLAY:
                    show();
                    break;
                case CLOSE:
                    return;
                case NONE:
                    continue;
                default:
                    break;

            }
        }
    }
};
