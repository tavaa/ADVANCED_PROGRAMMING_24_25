///////////// BINDINGS.cpp //////////

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "Song.hpp"
#include "Album.hpp"
#include "Playlist.hpp"
#include "Database.hpp"

namespace py = pybind11;

// binding for music_library
PYBIND11_MODULE(music_library, m) {

    py::class_<MusicEntity>(m, "MusicEntity")

        .def("get_id", &MusicEntity::getId)
        .def("get_name", &MusicEntity::getName)
        .def("print_details", &MusicEntity::printDetails)
        .def("get_duration", &MusicEntity::getDuration);

    // bindings fdr polymorphism
    py::class_<Song, MusicEntity>(m, "Song")

        .def(py::init<int, const std::string&, const std::string&, int>())
        .def("printDetails", &Song::printDetails)
        .def("getDuration", &Song::getDuration);

    py::class_<Album, MusicEntity>(m, "Album")

        .def(py::init<int, const std::string&>())
        .def("add_song", &Album::addSong)
        .def("remove_song", &Album::removeSong);

    py::class_<Playlist, MusicEntity>(m, "Playlist")

        .def(py::init<int, const std::string&>())
        .def("add_item", &Playlist::addItem)
        .def("remove_item", &Playlist::removeItem)
        .def("shuffle", &Playlist::shuffle);

    // for template specialize every T
    py::class_<Database<Song>>(m, "SongDatabase")

        .def(py::init<>())
        .def("add_item", &Database<Song>::addItem)
        .def("remove_item", &Database<Song>::removeItem)
        .def("get_item_by_id", &Database<Song>::getItemById, py::return_value_policy::reference)
        .def("search_by_name", &Database<Song>::searchByName)
        .def("print_all", &Database<Song>::printAll);

    py::class_<Database<Album>>(m, "AlbumDatabase")

        .def(py::init<>())
        .def("add_item", &Database<Album>::addItem)
        .def("remove_item", &Database<Album>::removeItem)
        .def("get_item_by_id", &Database<Album>::getItemById, py::return_value_policy::reference)
        .def("search_by_name", &Database<Album>::searchByName)
        .def("print_all", &Database<Album>::printAll);

    py::class_<Database<Playlist>>(m, "PlaylistDatabase")

        .def(py::init<>())
        .def("add_item", &Database<Playlist>::addItem)
        .def("remove_item", &Database<Playlist>::removeItem)
        .def("get_item_by_id", &Database<Playlist>::getItemById, py::return_value_policy::reference)
        .def("search_by_name", &Database<Playlist>::searchByName)
        .def("print_all", &Database<Playlist>::printAll)
        .def("shuffle_playlist", &Database<Playlist>::shufflePlaylist);
}

/*
* TO DO:
* binding for exceptions
*/