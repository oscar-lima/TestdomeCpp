#include <stdexcept>
#include <iostream>
#include <unordered_set>

class Song
{
public:
    Song(std::string name): name(name), nextSong(NULL) {}
    
    void next(Song* song)
    {
        this->nextSong = song;
    }
    
    bool isRepeatingPlaylist()
    {
        std::unordered_set<std::string> all_songs;
        return isRepeatingPlaylist(all_songs, *this);
    }

    bool isRepeatingPlaylist(std::unordered_set<std::string> &all_songs, Song &current_song)
    {
        if(all_songs.find(current_song.name) != all_songs.end()) // song found
            return true;
        
        all_songs.insert(current_song.name);

        if(current_song.nextSong == NULL) // reached end of playlist
            return false;

        return this->isRepeatingPlaylist(all_songs, *current_song.nextSong);
    }

private:
    const std::string name;
    Song* nextSong;
};

#ifndef RunTests
int main()
{
    Song* first = new Song("Hello");
    Song* second = new Song("Eye of the tiger");
    
    first->next(second);
    second->next(first);

    std::cout << std::boolalpha << first->isRepeatingPlaylist() << std::endl;
}
#endif
