/*
* database container for type T: albums, songs and playlists 
* with specialization for playlists
*/

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <vector>
#include <algorithm>
#include <iostream>

#include "Playlist.hpp"
#include "Song.hpp"
#include "Album.hpp"
#include "MusicEntity.hpp"

// generic container class Database<T>
template <typename T>
class Database {

    private:
        // items of type T
        std::vector<T> items;

    public:

        // methods to add and remove items 
        void addItem(const T& item) {
            items.push_back(item);
        }

        // uses a lambda function + iterators to capture id and remove it
        void removeItem(int id) {
            items.erase(std::remove_if(items.begin(), items.end(), [id](const T& item) { return item.getId() == id; }), items.end());
        }

        // uses a lambda function  to find an return the item
        T* getItemById(int id) {

            auto it = std::find_if(items.begin(), items.end(), [id](const T& item) { return item.getId() == id; });
            return it != items.end() ? &(*it) : nullptr;
        }

        // method to search by name     
        // stores results into a vector of results                                                                                                                              
        std::vector<T*> searchByName(const std::string& name) {

            std::vector<T*> results;
            for (auto& item : items) {
                if (item.getName() == name) {
                    results.push_back(&item);
                }
            }
            return results;
        }

        // method to print
        // calls itme.printDetails() depending on the item type
        void printAll() const {

            for (const auto& item : items) {
                item.printDetails();
            }
    }
};

// Specialization for Playlist to allow shuffling
// used in the case that item T is effectively a plalist
template <>
class Database<Playlist> {

    private:

        std::vector<Playlist> items;

    public:

        // methods to add and remove items
        void addItem(const Playlist& item) {
            items.push_back(item);
        }

        void removeItem(int id) {
            items.erase(std::remove_if(items.begin(), items.end(), [id](const Playlist& item) { return item.getId() == id; }), items.end());
        }

        // getter by id
        Playlist* getItemById(int id) {

            auto it = std::find_if(items.begin(), items.end(), [id](const Playlist& item) { return item.getId() == id; });
            return it != items.end() ? &(*it) : nullptr;
        }

        // search by name
        std::vector<Playlist*> searchByName(const std::string& name) {
            
            std::vector<Playlist*> results;
            for (auto& item : items) {
                if (item.getName() == name) {
                    results.push_back(&item);
                }
            }
            return results;
        }

        void printAll() const {

            for (const auto& item : items) {
                item.printDetails();
            }
        }

        // method to shuffle -> from an id gets the playlist 
        // and shuffle it
        void shufflePlaylist(int id) {

            Playlist* playlist = getItemById(id);
            if (playlist) {
                playlist->shuffle();
            }
        }
};

#endif // DATABASE_HPP
