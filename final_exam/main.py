###################### TEST FOR PYTHON BINDINGS #####################

import os
import sys

# Path to include the compiled binding
build_dir = os.path.abspath("build/")
sys.path.append(build_dir)

import music_library

def main():

    # example of instatiate init in python
    song_db = music_library.SongDatabase()
    album_db = music_library.AlbumDatabase()
    playlist_db = music_library.PlaylistDatabase()
    
    song1 = music_library.Song(1, "Notti", "sfera ebbasta", 300)
    song2 = music_library.Song(2, "Dark horse", "kety perry", 250)

    # add to the database
    song_db.add_item(song1)
    song_db.add_item(song2)

    album = music_library.Album(1, "XDVR")
    album.add_song(song1)
    #album.add_song(song2)
    album_db.add_item(album)

    playlist = music_library.Playlist(1, "good_mood")
    playlist.add_item(song1)
    playlist.add_item(album)
    playlist_db.add_item(playlist)

    #debug -> print all
    print()
    print("All Songs:")
    song_db.print_all()
    print()

    print("All Albums:")
    album_db.print_all()
    print()

    print("All Playlists:")
    playlist_db.print_all()
    print()

    print("Shuffling Playlist1")
    playlist_db.shuffle_playlist(1)
    playlist_db.print_all()

if __name__ == "__main__":
    main()
