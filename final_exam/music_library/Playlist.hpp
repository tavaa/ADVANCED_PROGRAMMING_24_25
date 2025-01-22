/*
* Derived class playlist
*/

#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <vector>
#include <algorithm>
#include <random> // shuffles songs

#include "MusicEntity.hpp"
#include "Song.hpp"
#include "Album.hpp"

class Playlist : public MusicEntity {

    public:

        // delagating constructor
        Playlist(int id, const std::string& name) : MusicEntity(id, name) {}

        // method to add and remove items
        void addItem(MusicEntity* item) {
            items.push_back(item);
        }

        void removeItem(int itemId) {
            items.erase(std::remove_if(items.begin(), items.end(), [itemId](MusicEntity* item) { return item->getId() == itemId; }), items.end());
        }

        // function to shuffle
        void shuffle() {

            std::random_device rd; // initialize random_devide 
            std::mt19937 g(rd()); // generate from rd
            std::shuffle(items.begin(), items.end(), g); // apply in items using a iterator
        }   

        // implementation of pure virtual method to get duration
        int getDuration() const override {

            int totalDuration = 0;
            for (const auto& item : items) {
                totalDuration += item->getDuration();
            }
            return totalDuration;
        }

        // implementation of pure virtual method to print details
        void printDetails() const override {

            std::cout << "Playlist ID: " << id << ", Name: " << name << ", Total Duration: " << getDuration() << " seconds" << std::endl;
            for (const auto& item : items) {
                item->printDetails();
            }
        }

    private:

        // polymorphically
        std::vector<MusicEntity*> items;

};

#endif // PLAYLIST_HPP
