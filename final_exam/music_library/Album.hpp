/*
* Derived class album
*/

#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <algorithm>
#include <vector>

#include "MusicEntity.hpp"
#include "Song.hpp"

class Album : public MusicEntity {

    public:

        // delegating constructor
        Album(int id, const std::string& name) : MusicEntity(id, name) {}

        // methods to add and remove songs
        void addSong(const Song& song) {
            songs.push_back(song);
        }

        void removeSong(int songId) {
            songs.erase(std::remove_if(songs.begin(), songs.end(), [songId](const Song& song) { return song.getId() == songId; }), songs.end());
        }

        // implementation of pure virtual method override to get duration
        int getDuration() const override {

            int totalDuration = 0;
            for (const auto& song : songs) {
                totalDuration += song.getDuration();
            }
            return totalDuration;
        }

        // implementation of pure virtual method override to print details
        void printDetails() const override {

            std::cout << "Album ID: " << id << ", Name: " << name << ", Total Duration: " << getDuration() << " seconds" << std::endl;
            for (const auto& song : songs) {
                song.printDetails();
            }
        }

        private:

            std::vector<Song> songs; // List of songs here

};

#endif // ALBUM_HPP
