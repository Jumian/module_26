#pragma once
#include <vector>
#include "track.h"



class Player{

    enum CMD{
        PLAY,
        PAUSE,
        NEXT,
        STOP,
        EXIT,
        NONE
    };

    std::vector<Track> playList;
    enum CMD command=NONE;
    enum CMD state=NONE;
    int currentTrack=0;
    void inputCommand(){
        std::string input;
        std::cout << "Input command [play,pause,next,stop,exit]:";
        std::cin >> input;
        if(input == "play") command=PLAY;
        else if(input == "pause") command=PAUSE;
        else if(input == "next") command=NEXT;
        else if(input == "stop") command=STOP;
        else if(input == "exit") command=EXIT;
    }

    std::string inputName(){
        std::string input;
        std::cout << "Input track name:";
        std::cin >> input;
        return input;
    }

    void play(){
        if(state!=PLAY) {

            playList.at(currentTrack).play();
            state = PLAY;
        }
    }

    void next(){
        state=NEXT;
        std::srand(std::time(nullptr));
        currentTrack=abs(std::rand())%playList.size();
        play();
    }
    void pause(){
        if(state!=PAUSE&&state!=STOP) {
            std::cout <<"Paused"<<std::endl;
            state=PAUSE;
        }
    }
    void stop(){
        if(state==PLAY||state==PAUSE) std::cout << "Stop" << std::endl;
        if(state!=STOP) state=STOP;
    }
public:
    void turnOn(){
        while(true) {
            inputCommand();
            switch (command) {
                case EXIT:
                    std::cout << "Exit.." << std::endl;
                    return;
                case PLAY:
                    play();
                    break;
                case PAUSE:
                    pause();
                    break;
                case STOP:
                    stop();
                    break;
                case NEXT:
                    next();
                    break;
                case NONE:
                    break;
            }
            command=NONE;
        }
    }
    void addTrack(Track *track){
        playList.push_back(*track);
    }
};