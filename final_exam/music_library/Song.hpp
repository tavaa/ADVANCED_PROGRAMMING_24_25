/*
* derived class song
*/

#ifndef SONG_HPP
#define SONG_HPP

#include "MusicEntity.hpp"
#include <iostream>

class Song : public MusicEntity {

    public:

        // constructor for song
        Song(int id, const std::string& name, const std::string& artist, int duration)
        : MusicEntity(id, name), artist(artist), duration(duration) {}

        // implementation for print details
        void printDetails() const override {
            std::cout << "Song ID: " << id << ", Name: " << name << ", Artist: " << artist << ", Duration: " << duration << " seconds" << std::endl;
        }

        // getter for duration
        int getDuration() const override {
            return duration;
        }

    private:

        std::string artist;
        int duration; 

};

#endif // SONG_HPP
