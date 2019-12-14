#include <stdexcept>
#include <iostream>
#include <unordered_set>

class Song
{
public:
    Song(std::string name): name(name), nextSong(NULL) {}
    
    void setNextSong(Song* song)
    {
        this->nextSong = song;
    }

    bool isRepeatingPlaylist()
    {
        std::unordered_set<std::string> all_songs;
        
        Song* current_song = this;
        
        while(current_song->nextSong != NULL)
        {
            if(all_songs.find(current_song->name) != all_songs.end()) // song found
                return true;
            
            all_songs.insert(current_song->name);

            // advance song
            current_song = current_song->nextSong;
        }
        
        // we traversed all songs and found no loops
        return false;
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
    
    first->setNextSong(second);
    second->setNextSong(first);

    std::cout << std::boolalpha << first->isRepeatingPlaylist() << std::endl;
}
#endif
