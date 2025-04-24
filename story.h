#ifndef STORY_H             // Ensure the header file is included only once during compilation
#define STORY_H

#include <iostream>          // For standard input/output operations
#include <fstream>           // For file handling (writing game or story data to files)

using namespace std;         // Allows the usage of standard library functions like cout, endl, etc.

// Class definition for Story, which handles the narrative and progression of the game
class Story {
public:
    // Function to display the story text (could be for game or events)
    void textGame();

    // Function to open a specified file for writing story data
    void file(string& filename);

    // Function to flush the output buffer to the file (ensures data is written immediately)
    void flusher();

    // Starting Room story section (initial setting when the game begins)
    void openArea();

    // RELATIVELY SAFE ROOMS (Low danger room events in the story)
    void DustyChamber();     // Story for a dusty, abandoned chamber
    void ForkedPathway();    // Story for a pathway with several choices
    void TheSplitHollow();   // Story for a hollow cavern full of mystery
    void CrossroadsOfFate(); // Story for an ancient crossroads with important decisions

    // MEDIUM DANGER ROOMS (Rooms with higher risks)
    void WhisperingTunnels();  // Story for tunnels with unsettling whispers
    void ForgottenWorkshop();  // Story for an abandoned workshop with ominous history
    void AncientLibrary();     // Story for a vast library full of forgotten knowledge

    // HIGH DANGER ROOMS (Deadly or highly dangerous rooms)
    void High_CrystalNexus();     // Story for a room filled with unstable magical crystals
    void High_BoneshadePit();     // Story for a pit full of bones and dark presence
    void High_ShiftingStones();   // Story for a room where the ground shifts unexpectedly

    // DEATH ROOMS (Rooms where death is inevitable)
    void Death_AbyssalMaw();   // Story for a death scenario where the player falls into an abyss
    void Death_BroodNest();    // Story for a death scenario where the player faces a deadly swarm

    // DEFAULT ROOM (Fallback scenario when an invalid state occurs)
    void Default();            // Story for an invalid or unexpected room

    // Main Story Events (Narrative progression tied to player’s level)
    void Main_EnterCave();     // Story for when the player first enters the cave (initial stage)
    void Main_AtLevel5();      // Story event at level 5
    void Main_AtLevel10();     // Story event at level 10
    void Main_AtLevel15();     // Story event at level 15
    void Main_AtLevel20();     // Story event at level 20
    void Main_AtLevel25();     // Story event at level 25 (game-ending event)

private:
    ofstream visual;    // Output file stream to write the story or game data into a file
};

#endif  // End of the #ifndef STORY_H preprocessor directive
