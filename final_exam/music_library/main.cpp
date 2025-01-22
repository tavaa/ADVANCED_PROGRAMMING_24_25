//////////////////////// TEST FOR CPP ///////////////////////////////

#include <iostream>

#include "Song.hpp"
#include "Album.hpp"
#include "Playlist.hpp"
#include "Database.hpp"

void printMenu() {
    
    // simply GUI to interact -> choose the number from the list
    std::cout << "[1] Add Song \n";
    std::cout << "[2] Add Album\n";
    std::cout << "[3] Add pllaylist\n";
    std::cout << "[4] View details of All Entities \n";
    std::cout << "[5] Search entity by name\n";
    std::cout << "[6] Remove etity by ID\n";
    std::cout << "[7] Shuffle playlist\n";
    std::cout << "[8] Exit\n";
}

int main() {

    // Initializate the Database<T> istances    
    Database<Song> songDatabase;
    Database<Album> albumDatabase;
    Database<Playlist> playlistDatabase;

    int choice;

    // iterative prgam 
    while (true) {

        printMenu();
        std::cin >> choice;

        if (choice == 1) {
            
            // insert a song into database
            int id, duration;
            std::string name, artist;
            std::cout << "Enter Song Id: ";
            std::cin >> id;
            std::cout << "Enter song name: ";
            std::cin >> name;
            std::cout << "Enter artist: ";
            std::cin >> artist;
            std::cout << "Enter duration: ";
            std::cin >> duration;
            songDatabase.addItem(Song(id, name, artist, duration));

        } else if (choice == 2) {
            
            // insert an album into database 
            int id;
            std::string name;
            std::cout << "Enter album Id: ";
            std::cin >> id;
            std::cout << "Enter album name: ";
            std::cin >> name;
            albumDatabase.addItem(Album(id, name));

        } else if (choice == 3) {
            
            // insert a playlist into database
            int id;
            std::string name;
            std::cout << "Enter playlist id: ";
            std::cin >> id;
            std::cout << "Enter playlist name: ";
            std::cin >> name;
            playlistDatabase.addItem(Playlist(id, name));

        } else if (choice == 4) {

            // calls the specific method according to the type to print all the entities
            std::cout << "Songs:\n";
            songDatabase.printAll();
            std::cout << "Albums:\n";
            albumDatabase.printAll();
            std::cout << "Playlists\n";
            playlistDatabase.printAll();

        } else if (choice == 5) {
            
            // search
            std::string name;
            std::cout << "Enter name to search:";
            std::cin >> name;
            auto songs = songDatabase.searchByName(name);
            auto albums = albumDatabase.searchByName(name);
            auto playlists = playlistDatabase.searchByName(name);
            std::cout << "Songs:\n";

            for (const auto& song : songs) {
                song->printDetails();
            }

            std::cout << "Albums: \n";
            for (const auto& album : albums) {
                album->printDetails();
            }

            std::cout << "Playlists :\n";
            for (const auto& playlist : playlists) {
                playlist->printDetails();
            }

        } else if (choice == 6) {

            // removes
            int id;
            std::cout << "Enter Id to Remove: ";
            std::cin >> id;
            songDatabase.removeItem(id);
            albumDatabase.removeItem(id);
            playlistDatabase.removeItem(id);

        } else if (choice == 7) {

            // calls the method to shuffle
            int id;
            std::cout << "Enter playlist id to Shuffle:";
            std::cin >> id;
            playlistDatabase.shufflePlaylist(id);

        } else if (choice == 8) {

            break; //break the loop if it is not valid

        } else {
            std::cout << "Invalid choice try again.\n";
        }
    }

    return 0;
}
