#include "map.h"          // Includes the map-related functionality (game map, game locations)
#include "story.h"        // Includes the story generation functionality
#include <iostream>       // Standard input/output stream library
#include <fstream>        // File stream for reading/writing files
#include <random>         // For generating random numbers in the game

using namespace std;      // This allows for easier usage of standard library features

// Global variables to track game progress and story flow
int choice, low, high, path, level = 0;
Map game;                // Instance of the Map class
Story story;             // Instance of the Story class
string gamefile, storyfile; // Variables for game and story file paths

// Random number generator function to pick a path based on range
void randomizer() {
    // Check if the chosen path is valid, otherwise prompt the user for a valid one
    if (path < game.getmin() || path > game.getmax()) {
        cout << "Please Pick a valid path!\n";
        cin >> path;   // Input the path again if it's invalid
        randomizer();   // Call the function recursively to get a valid path
    }

    // Set the range of random numbers based on the chosen path
    switch(path) {
        case 1: 
            low = 1;
            high = 5; // Path 1 has random numbers between 1 and 5
            break;
        case 2:
            low = 3;
            high = 7; // Path 2 has random numbers between 3 and 7
            break;
        case 3:
            low = 5;
            high = 11; // Path 3 has random numbers between 5 and 11
            break;
        case 4:
            low = 7;
            high = 12; // Path 4 has random numbers between 7 and 12
            break;
        default:
            low = 1;
            high = 12; // Default path is a full range (1-12)
            break;
    }

    // Set up the random number generator using random_device and mt19937
    random_device rd; 
    mt19937 gen(rd());  // Initialize the generator with a random seed
    uniform_int_distribution<> dist(low, high);  // Define the range for random numbers
    choice = dist(gen);  // Generate a random number within the chosen range
}

// This function controls the main game logic based on player's choices
void brain() {
    cout << "Which path do you want to take?";  // Prompt user to choose a path
    cin >> path;  // Input path choice
    randomizer();  // Generate a random outcome based on the path chosen

    // Process different game locations and story events based on random choice
    switch(choice) {
        case 1: 
            game.DustyChamber();   // Display dusty chamber location
            story.DustyChamber();  // Show story for dusty chamber
            game.flusher();        // Flush game output
            story.flusher();       // Flush story output
            level++;               // Increment level after visiting location
            break;
        case 2: 
            game.ForkedPathway();  // Display forked pathway location
            story.ForkedPathway(); // Show story for forked pathway
            game.flusher();
            story.flusher();
            level++;
            break;
        case 3:
            game.TheSplitHollow(); // Display split hollow location
            story.TheSplitHollow(); // Show story for split hollow
            game.flusher();
            story.flusher();
            level++;
            break;
        case 4:
            game.CrossroadsOfFate(); // Display crossroads of fate location
            story.CrossroadsOfFate(); // Show story for crossroads of fate
            game.flusher();
            story.flusher();
            level++;
            break;
        case 5:
            game.WhisperingTunnels(); // Display whispering tunnels location
            story.WhisperingTunnels(); // Show story for whispering tunnels
            game.flusher();
            story.flusher();
            level++;
            break;
        case 6:
            game.ForgottenWorkshop(); // Display forgotten workshop location
            story.ForgottenWorkshop(); // Show story for forgotten workshop
            game.flusher();
            story.flusher();
            level++;
            break;
        case 7:
            game.AncientLibrary(); // Display ancient library location
            story.AncientLibrary(); // Show story for ancient library
            game.flusher();
            story.flusher();
            level++;
            break;
        case 8:
            game.High_CrystalNexus(); // Display high crystal nexus location
            story.High_CrystalNexus(); // Show story for high crystal nexus
            game.flusher();
            story.flusher();
            level++;
            break;
        case 9:
            game.High_BoneshadePit(); // Display high boneshade pit location
            story.High_BoneshadePit(); // Show story for high boneshade pit
            game.flusher();
            story.flusher();
            level++;
            break;
        case 10:
            game.High_ShiftingStones(); // Display high shifting stones location
            story.High_ShiftingStones(); // Show story for high shifting stones
            game.flusher();
            story.flusher();
            level++;
            break;
        case 11:
            game.Death_AbyssalMaw(); // Death scenario at abyssal maw
            story.Death_AbyssalMaw(); // Show death story for abyssal maw
            game.flusher();
            story.flusher();
            exit(0); // Exit the game after death
            break;
        case 12:
            game.Death_BroodNest(); // Death scenario at brood nest
            story.Death_BroodNest(); // Show death story for brood nest
            game.flusher();
            story.flusher();
            exit(0); // Exit the game after death
            break;
        default:
            game.Default(); // Default room if no valid choice is made
            story.Default(); // Default story if no valid choice is made
            game.flusher();
            story.flusher();
            exit(0); // Exit if default is triggered
    }

    // Main checkpoints: Different events occur at specific levels
    switch(level) {
        case 0:
            story.Main_EnterCave(); // At level 0, enter the cave
            story.flusher();
            break;
        case 5: 
            story.Main_AtLevel5(); // At level 5, show the story event for level 5
            story.flusher();
            break;
        case 10:
            story.Main_AtLevel10(); // At level 10, show the story event for level 10
            story.flusher();
            break;
        case 15:
            story.Main_AtLevel15(); // At level 15, show the story event for level 15
            story.flusher();
            break;
        case 20:
            story.Main_AtLevel20(); // At level 20, show the story event for level 20
            story.flusher();
            break;
        case 25:
            story.Main_AtLevel25(); // At level 25, show the story event for level 25 (endgame)
            story.flusher();
            exit(0); // Exit the game after reaching the final level
    }
    
    brain(); // Recursively call the brain function to continue the game
}

// Main function to start the game
int main() {
    // Ask for game and story files
    cout << "Please Insert a valid game file!\n";
    cin >> gamefile;  // User inputs the path to the game file
    game.file(gamefile);  // Open the game file using the Map class
    cout << "\nPlease insert a valid story file!\n";
    cin >> storyfile;  // User inputs the path to the story file
    story.file(storyfile);  // Open the story file using the Story class
    
    // Flush any output to files
    game.flusher();
    story.flusher();

    // Start the main game loop
    brain();
}
