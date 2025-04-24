#ifndef MAP_H               // Ensure the header file is included only once during compilation
#define MAP_H

#include <iostream>          // Standard I/O stream for displaying messages
#include <fstream>           // For file handling (outputting to files)

using namespace std;         // Allows us to use standard library functions like cout, endl, etc.

// Class declaration for Map, handling the map-related logic of the game
class Map {
public:
    // Function to display the current state of the game (e.g., the current room or scenario)
    void displayGame();

    // Function to open a specified file for writing game data (like the story)
    void file(string& filename);

    // Function to flush the output buffer, ensuring all text is written to the file
    void flusher();

    // Starting Room, where the game begins
    void openArea();

    // RELATIVELY SAFE ROOMS (Low danger rooms)
    void DustyChamber();     // A dusty, abandoned chamber
    void ForkedPathway();    // A path with multiple options
    void TheSplitHollow();   // A hollow cavern with eerie stillness
    void CrossroadsOfFate(); // An intersection of many paths, filled with mystery

    // MEDIUM DANGER ROOMS
    void WhisperingTunnels();  // Tunnels that whisper in an unsettling way
    void ForgottenWorkshop();  // An old, abandoned workshop
    void AncientLibrary();     // A vast library filled with knowledge and danger

    // HIGH DANGER ROOMS (more perilous environments)
    void High_CrystalNexus();     // A room full of dangerous, unstable crystals
    void High_BoneshadePit();     // A dark pit covered in bones and decay
    void High_ShiftingStones();   // A room where the ground moves and shifts unpredictably

    // DEATH ROOMS (These rooms usually lead to the player's death)
    void Death_AbyssalMaw();   // A dangerous abyss where the player falls into darkness
    void Death_BroodNest();    // A death room filled with deadly swarms or creatures

    // DEFAULT ROOM (in case of invalid state or unexpected conditions)
    void Default();            // A "catch-all" room if the game state is invalid or corrupted

    // Function to get the maximum room number (used for random path generation)
    int getmax();

    // Function to get the minimum room number (used for random path generation)
    int getmin();

private:
    ofstream visual;    // Output file stream to write the story or game data to a file

    int max, min;       // Maximum and minimum room numbers (to control random path generation)
};

#endif  // End of the #ifndef MAP_H preprocessor directive
