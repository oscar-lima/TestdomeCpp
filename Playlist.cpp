#include <stdexcept>
#include <iostream>
#include <vector>
#include <unordered_map>

class Song
{
  public:
    Song(std::string name): name(name), nextSong(NULL) {}
    
    void next(Song* song)
    {
        this->nextSong = song;
    }

    bool checkHistory(std::unordered_map<std::string, int> &history)
    {
        if(this->nextSong == NULL)
        {
            return false;
        }
        
        // traverse history and compare to current song name, return true if song is found
        if ( history.find(this->nextSong->name) == history.end() )
        {
            // not found, add
            history[this->name] =  0;
        }
        else
        {
            return true;
        }
        
        return this->nextSong->checkHistory(history);
    }

    bool isRepeatingPlaylist()
    {
        std::unordered_map<std::string, int> empty_vector;

        return this->checkHistory(empty_vector);
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
