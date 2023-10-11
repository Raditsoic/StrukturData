#include <iostream>
#include <string>
#include <list>
#include <Windows.h>

using namespace std;


class Song {
public:
    string title;
    string artist;

    Song(const string& title, const string& artist) : title(title), artist(artist) {}
};

class Album {
public:
    list<Song> songList;
    list<Song>::iterator currentSong;
    int loop = 1;
    int balance = 0;

    void addSong(const string& title, const string& artist) {
        songList.emplace_back(title, artist);
        if (songList.size() == 1) {
            currentSong = songList.begin();
        }
    }

    void insertCoins(int coins)
    {
        balance += coins;
    }

    void play() {
        if (!songList.empty()) {
            while (balance > 0) {
                cout << "Now playing: " << currentSong->title << " by " << currentSong->artist << " #" << loop << endl;
                Sleep(2000);
                nextSong();
            }
            cout << "Loop Ended, Insert more Coins!" << endl;
        } else {
            cout << "Album is empty." << endl;
        }
    }

    void nextSong() {
        if (!songList.empty()) 
        {
            ++currentSong;
            if (currentSong == songList.end()) 
            {
                currentSong = songList.begin();
                balance--;
                loop++;
            }
        }
    }
};

int main()
{
    Album forLovers;

    
    forLovers.addSong("For Lovers", "Lamps");
    forLovers.addSong("Hirogaru-Namida", "Lamps");
    forLovers.addSong("Last Train at 25 O'Clock", "Lamps");
    forLovers.addSong("Out on Sunny Sunday", "Lamps");
    forLovers.addSong("Tomorrow Comes I Wil", "Lamps");
    forLovers.addSong("Rainy Tapestry", "Lamps");
    forLovers.addSong("Words of Love", "Lamps");
    forLovers.addSong("Behind the Moon Shadow", "Lamps");

    int coins;
    cout << "How many times do you want to loop 'For Lovers' by 'Lamps'? (Insert Coins) " << endl;
    cin >> coins;
    forLovers.insertCoins(coins);
    forLovers.play();


}