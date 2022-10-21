#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>

class Track{
    std::string name= "";
    std::tm date ;
    std::time_t duration;

public:
    void play(){
        std::cout <<
            name << " " <<
            std::put_time(&date,"%d/%m/%Y") << " " <<
            duration << std::endl;
    }
    std::string getName(){return name;}
    std::tm getDate(){return date;}
    std::time_t getDuration(){return duration;}
    static Track *createTrack(std::string name,std::time_t date,std::time_t duration){
        Track *track=new Track;
        track->name=name;
        track->date=*localtime(&date);
        track->duration=duration;
        return track;
    }
};