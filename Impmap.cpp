#include "map.h"
#include <iostream>
#include <fstream>

// Open a file for writing the map data (like room descriptions)
void Map::file(string& filename) {
    // Attempt to open the specified file
    visual.open(filename);
    
    // Check if the file was opened successfully
    if (visual.is_open()) {
        // If the file opens, begin the map with the starting room
        openArea();
    } else {
        // If the file couldn't be opened, print an error message to the console
        cerr << "Error: Could not open file " << filename << " for map generation!";
    }
}

// Flush the output stream to ensure all data is written to the file
void Map::flusher() {
    visual.flush();
}

// Display the starting area of the game: "The Open Entrance"
void Map::openArea() {
    // Define an indent string to format the room description
    string indent = "     ";
    
    // Write the room description to the file
    visual << indent << " _______________________\n";
    visual << indent << "|                       |\n";
    visual << indent << "|          O            |\n";
    visual << indent << "|         /|\\           |\n";
    visual << indent << "|         / \\           |\n";
    visual << indent << "|                       |\n";
    visual << indent << "|   The Open Entrance   |\n";
    visual << indent << "|\"Welcome, adventurer!\" |\n";
    visual << indent << "|        [1] Enter      |\n";
    visual << indent << "|_______________________|\n";
    
    // Set the minimum and maximum options for this room
    min = 1;
    max = 1;
}

// Display the "Dusty Chamber" room description
void Map::DustyChamber() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "|                       |\n";
    visual << indent << "|          O            |\n";
    visual << indent << "|         /|\\           |\n";
    visual << indent << "|         / \\           |\n";
    visual << indent << "|                       |\n";
    visual << indent << "|    Dusty Chamber      |\n";
    visual << indent << "| \"Cobwebs cling to you\"|\n";
    visual << indent << "|    [1] Go deeper      |\n";
    visual << indent << "|_________[___]_________|\n";
    min = 1;
    max = 1;
}

// Display the "Forked Pathway" room description
void Map::ForkedPathway() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "|                       |\n";
    visual << indent << "|          O            |\n";
    visual << indent << "|         /|\\           |\n";
    visual << indent << "|         / \\           |\n";
    visual << indent << "|                       |\n";
    visual << indent << "|   Forked Pathway      |\n";
    visual << indent << "| \"Two paths lie ahead\" |\n";
    visual << indent << "| [2] Left   [3] Right  |\n";
    visual << indent << "|_______[___]_[___]_____|\n";
    min = 2;
    max = 3;
}

// Display the "The Split Hollow" room description
void Map::TheSplitHollow() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "|                       |\n";
    visual << indent << "|          O            |\n";
    visual << indent << "|         /|\\           |\n";
    visual << indent << "|         / \\           |\n";
    visual << indent << "|                       |\n";
    visual << indent << "|   The Split Hollow    |\n";
    visual << indent << "|  \"Which way now?\"     |\n";
    visual << indent << "|[1] L [2] M [3] R      |\n";
    visual << indent << "|____[__]_[__]_[__]_____|\n";
    min = 1;
    max = 3;
}

// Display the "Crossroads of Fate" room description
void Map::CrossroadsOfFate() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "|                       |\n";
    visual << indent << "|          O            |\n";
    visual << indent << "|         /|\\           |\n";
    visual << indent << "|         / \\           |\n";
    visual << indent << "|                       |\n";
    visual << indent << "|  Crossroads of Fate   |\n";
    visual << indent << "|\"Four ways diverge...\"|\n";
    visual << indent << "| [1][2][3][4] Choose...|\n";
    visual << indent << "|__[__]_[__]_[__]_[__]__|\n";
    min = 1;
    max = 4;
}

// Display a default room when something goes wrong or the room isn't defined
void Map::Default() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "|                       |\n";
    visual << indent << "|          O            |\n";
    visual << indent << "|         /|\\           |\n";
    visual << indent << "|         / \\           |\n";
    visual << indent << "|                       |\n";
    visual << indent << "|     ??? Unknown       |\n";
    visual << indent << "|     Something broke   |\n";
    visual << indent << "|_______________________|\n";
}

// MEDIUM DANGER ROOMS

// Display the "Whispering Tunnels" room description
void Map::WhisperingTunnels() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "|                       |\n";
    visual << indent << "|          O            |\n";
    visual << indent << "|         /|\\           |\n";
    visual << indent << "|         / \\           |\n";
    visual << indent << "| Wind echoes from deep |\n";
    visual << indent << "|   tunnels beyond.     |\n";
    visual << indent << "|            [2] Deep   |\n";
    visual << indent << "| [3] ???               |\n";
    visual << indent << "|____________[__][__]___|\n";
    min = 1;
    max = 3;
}

// Display the "Forgotten Workshop" room description
void Map::ForgottenWorkshop() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "|                       |\n";
    visual << indent << "|          O            |\n";
    visual << indent << "|         /|\\           |\n";
    visual << indent << "|         / \\           |\n";
    visual << indent << "| Tools rust in silence |\n";
    visual << indent << "|  \"Which door creaks?\" |\n";
    visual << indent << "|    [2][3][4]          |\n";
    visual << indent << "|______[__][__][__]_____|\n";
    min = 2;
    max = 4;
}

// Display the "Ancient Library" room description
void Map::AncientLibrary() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "|                       |\n";
    visual << indent << "|          O            |\n";
    visual << indent << "|         /|\\           |\n";
    visual << indent << "|         / \\           |\n";
    visual << indent << "| Silent scrolls rest.  |\n";
    visual << indent << "|   Dust lingers in air.|\n";
    visual << indent << "| [1] East  [2] West    |\n";
    visual << indent << "|_______[___]_[___]_____|\n";
    min = 1;
    max = 2;
}

// HIGH DANGER ROOMS

// Display the "Boneshade Pit" room description (high danger)
void Map::High_BoneshadePit() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "|                       |\n";
    visual << indent << "|          O            |\n";
    visual << indent << "|         /|\\           |\n";
    visual << indent << "|         / \\           |\n";
    visual << indent << "| Bones litter the floor|\n";
    visual << indent << "| \"Something watches...\"|\n";
    visual << indent << "|   [1] Descend...      |\n";
    visual << indent << "|_________[___]_________|\n";
    min = 1;
    max = 1;
}

// Display the "Crystal Nexus" room description (high danger)
void Map::High_CrystalNexus() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "|                       |\n";
    visual << indent << "|          O            |\n";
    visual << indent << "|         /|\\           |\n";
    visual << indent << "|         / \\           |\n";
    visual << indent << "|Crystals glow softly. |\n";
    visual << indent << "|\"Magic hums in stone.\"|\n";
    visual << indent << "|    [2][3] Shimmering |\n";
    visual << indent << "|______[__][__]_________|\n";
    min = 2;
    max = 3;
}

// Display the "Shifting Stones" room description (high danger)
void Map::High_ShiftingStones() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "|                       |\n";
    visual << indent << "|          O            |\n";
    visual << indent << "|         /|\\           |\n";
    visual << indent << "|         / \\           |\n";
    visual << indent << "| The floor is moving… |\n";
    visual << indent << "| \"Which stone is safe?\"|\n";
    visual << indent << "|         [3] [4]       |\n";
    visual << indent << "|__________[__][__]_____|\n";
    min = 3;
    max = 4;
}

// DEATH ROOMS

// Display the "Abyssal Maw" room description (death)
void Map::Death_AbyssalMaw() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "|                       |\n";
    visual << indent << "|          O            |\n";
    visual << indent << "|         /|\\           |\n";
    visual << indent << "|         / \\           |\n";
    visual << indent << "|   A void... too deep  |\n";
    visual << indent << "|                       |\n";
    visual << indent << "|     **Your Dead**     |\n";
    visual << indent << "|_______________________|\n";
}

// Display the "Brood Nest" room description (death)
void Map::Death_BroodNest() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "|                       |\n";
    visual << indent << "|          O            |\n";
    visual << indent << "|         /|\\           |\n";
    visual << indent << "|         / \\           |\n";
    visual << indent << "|   Eggs begin to hatch |\n";
    visual << indent << "|   \"They're everywhere\"|\n";
    visual << indent << "|     **Your Dead**     |\n";
    visual << indent << "|_______________________|\n";
}

// Return the maximum option number for a room
int Map::getmax() {
    return max;
}

// Return the minimum option number for a room
int Map::getmin() {
    return min;
}
