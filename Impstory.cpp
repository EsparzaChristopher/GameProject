#include "story.h"
#include <iostream>
#include <fstream>

// Function to open the file where the story will be written.
void Story::file(string& filename) {
    visual.open(filename); // Attempt to open the specified file
    if (visual.is_open()) { // If the file was successfully opened
        openArea(); // Call the function to print the introductory area (first scene)
    } else { // If the file could not be opened
        cerr << "Error: Could not open file " << filename << " for Story generation!"; // Print error message
    }
}

// Function to flush the output stream (ensures all data is written to the file).
void Story::flusher() {
    visual.flush(); // Flush the output to ensure the data is written to the file
}

// Function to print the description of the opening area of the story.
void Story::openArea() {
    string indent = "     "; // Indentation for formatting
    visual << indent << " _______________________\n";
    visual << indent << "You awaken beneath a twilight sky, stretched across a field of cracked stone and wild grass.\n";
    visual << indent << "Ahead lies the mouth of an ancient ruin — its archway broken, its shadows deep.\n";
    visual << indent << "The wind carries whispers of forgotten heroes… and things best left buried.\n";
    visual << indent << "This is where your journey begins.\n";
    visual << indent << "You take your first step into the unknown.\n";
}

// Function for describing a dusty chamber room in the dungeon.
void Story::DustyChamber() {
    string indent = "     "; // Indentation for formatting
    visual << indent << " _______________________\n";
    visual << indent << "You enter a quiet, dust-covered chamber. Cracks spiderweb across the stone walls, and the air smells ancient.\n"; 
    visual << indent << "Cobwebs stretch between broken furniture and a faded mural whispers tales of forgotten times.\n";
    visual << indent << "This place feels abandoned… but not hostile.\n";
}

// Function for describing a forked pathway (room with choices).
void Story::ForkedPathway() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "The tunnel splits ahead, three worn paths diverging in the dim torchlight.\n"; 
    visual << indent << "A gust of stale wind rolls past, carrying with it a faint whisper.\n";
    visual << indent << "You feel the weight of choice pressing down on you.\n";
}

// Function for describing a hollow cavern with natural formations.
void Story::TheSplitHollow() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "A natural cavern opens wide, supported by jagged pillars.\n"; 
    visual << indent << "Faint glowing moss clings to the walls, casting an eerie green hue. \n";
    visual << indent << "The silence here is heavy — not threatening, just… watching.\n";
}

// Function for describing an intersection of multiple paths.
void Story::CrossroadsOfFate() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "An ancient intersection. Four paths converge beneath a shattered stone arch etched with unreadable runes. \n"; 
    visual << indent << "Each road feels charged with its own energy — like fate itself waits for your next step.\n";
}

// Function for describing a void that shouldn't exist.
void Story::Default() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "You stumble into an empty void — black, formless, and cold. Something's wrong.\n"; 
    visual << indent << "This room shouldn't exist.\n";
}

// MEDIUM DANGER ROOMS
// Describes a room where whispers echo through the walls.
void Story::WhisperingTunnels() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "The walls here whisper. Actual voices. Not loud — just barely audible, as if the stone remembers every footstep, every scream. \n"; 
    visual << indent << "Your torch flickers violently. Something doesn't want you here. \n";
}

// Describes a forgotten workshop filled with abandoned tools and strange symbols.
void Story::ForgottenWorkshop() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "Abandoned tools and shattered glass litter the floor. Strange symbols are scrawled across the tables. \n"; 
    visual << indent << "This was once a place of creation, but now it stinks of rot and regret.\n";
}

// Describes an ancient library with eerie, self-turning books.
void Story::AncientLibrary() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "Shelves stretch up into darkness. Books lie scattered, some with pages still turning… by themselves. \n"; 
    visual << indent << "Something unseen watches from the shadows between the shelves.\n";
}

// HIGH DANGER ROOMS
// Describes a pit of bones and decay, a dangerous, unsettling environment.
void Story::High_BoneshadePit() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "You descend into a pit layered with bones and the stench of decay. \n"; 
    visual << indent << "The shadows here move, twitch, and breathe. Something is buried beneath — or waiting to rise.\n";
}

// Describes a room filled with unstable magical crystals that pulse with energy.
void Story::High_CrystalNexus() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "Blinding crystals jut from every surface, pulsing with unstable magic. \n"; 
    visual << indent << "Energy arcs between them with sharp cracks — stepping wrong here might mean instant death. \n";
    visual << indent << "The room hums with raw power and violent potential.\n";
}

// Describes a room where the ground constantly shifts and rearranges.
void Story::High_ShiftingStones() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "The ground constantly moves, grinding underfoot.\n"; 
    visual << indent << "Stones slide and rearrange with no pattern, like the dungeon is rethinking itself.\n";
    visual << indent << "Walls appear and vanish. This place doesn’t obey logic.\n";
}

// DEATH ROOMS
// Describes a death room where the player falls into a bottomless abyss.
void Story::Death_AbyssalMaw() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "You step toward the edge of the chasm, drawn by something you can’t explain.\n"; 
    visual << indent << "The stone beneath you gives way.\n";
    visual << indent << "You fall, deeper and deeper, into a swirling void that stretches beyond time.\n";
    visual << indent << "There is no light, no ground, no escape — only the sensation of being erased.\n"; 
    visual << indent << "Whatever you were… is no longer.\n";
    visual << indent << "**YOU DIED.**\n";
}

// Describes a death room where the player is surrounded by a swarming nest of creatures.
void Story::Death_BroodNest() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "The nest is silent — too silent.\n"; 
    visual << indent << "Then the sound comes: scratching, skittering, thousands of tiny feet waking all at once.\n";
    visual << indent << "Before you can react, the swarm surrounds you.\n";
    visual << indent << "There’s nowhere to run. Nowhere to hide.\n"; 
    visual << indent << "The last thing you hear is the nest returning to stillness.\n";
    visual << indent << "**YOU DIED.**\n";
}

// MAIN STORY PROGRESSION
// These functions describe the player's progression through various milestones in the dungeon.

// Describes the player's first steps into the cave at the start of the story.
void Story::Main_EnterCave() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "You awaken beneath a twilight sky, stretched across a field of cracked stone and wild grass.\n"; 
    visual << indent << "Ahead lies the mouth of an ancient ruin — its archway broken, its shadows deep.\n";
    visual << indent << "The wind carries whispers of forgotten heroes… and things best left buried.\n";
    visual << indent << "This is where your journey begins.\n";
    visual << indent << "You take your first step into the unknown.\n";
}

// Describes the player at level 5, with the feeling that the dungeon is aware of them.
void Story::Main_AtLevel5() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "The cave seems to shift behind you — the entrance now distant, if it even exists at all.\n";
    visual << indent << "On the walls, symbols you hadn’t seen before now glow faintly, pulsing with each heartbeat.\n";
    visual << indent << "A strange sensation creeps into your mind — not danger, but recognition.\n";
    visual << indent << "Something in this place knows you're here.\n";
}

// Describes the player at level 10, where mysterious connections with the past surface.
void Story::Main_AtLevel10() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "You find a chamber filled with broken stone faces, staring blankly into the dark.\n";
    visual << indent << "One of them matches your own — cracked and weeping black dust.\n";
    visual << indent << "A voice echoes from the walls, speaking your name in a tongue you've never learned.\n";
    visual << indent << "The echo doesn't stop. It follows you into the next tunnel.\n";
}

// Describes the player at level 15, confronting visions of a past betrayal.
void Story::Main_AtLevel15() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "A circular room appears, carved with scenes of a great betrayal.\n";
    visual << indent << "At the center stands a monument — your weapon, buried in stone, older than you remember.\n";
    visual << indent << "Visions burn into your mind: you’ve been here before… and you failed.\n";
    visual << indent << "Your journey wasn’t the beginning. It’s a return.\n";
}

// Describes the player at level 20, reaching a throne room with a dark revelation.
void Story::Main_AtLevel20() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "A sealed gate opens without touch, revealing a throne room made of obsidian and bone.\n";
    visual << indent << "Something sits upon the throne — it looks like you, but older, broken, and smiling.\n";
    visual << indent << "“At last,” it says. “The cycle completes again. Ready to remember?”\n";
    visual << indent << "The floor cracks, revealing a chasm of light. Or maybe memory.\n";
    visual << indent << "You step forward — because you always do.\n";
}

// Describes the player at level 25, ending the journey with a peaceful resolution.
void Story::Main_AtLevel25() {
    string indent = "     ";
    visual << indent << " _______________________\n";
    visual << indent << "You step into the final chamber — vast, quiet, still.\n";
    visual << indent << "The whispers are gone. The stone no longer shifts. The cave no longer resists you.\n";
    visual << indent << "Before you stands a pedestal. On it, a single object: a small, smooth stone pulsing with quiet light.\n";
    visual << indent << "You place your hand on it.\n";
    visual << indent << "It’s warm.\n";
    visual << indent << "The darkness recedes. The walls dissolve. You are no longer underground.\n";
    visual << indent << "A sky spreads above you — unfamiliar stars, endless horizon. You feel… peace.\n";
    visual << indent << "You made it through.\n";
    visual << indent << "Not untouched. Not unscarred. But whole.\n";
    visual << indent << "This is the end of the journey.\n";
    visual << indent << "And this time, there is no cycle.\n";
    visual << indent << "Just light.\n";
    visual << indent << "**YOU WIN.**\n";
}
