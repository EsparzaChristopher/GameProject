# Story Generation - Recursion Strategy

## Overview

This project generates a story where the user progresses through different rooms, each with its own description and unique setting. The story is structured to simulate a dungeon crawl, where the player encounters various environments, some with higher danger levels, others with lower risk, and some leading to death. As the player progresses through levels, the story deepens and introduces more complex scenarios and settings.

## Recursion Strategy

The recursion strategy used in this project is built around simulating the journey of a character through a series of interconnected rooms. At each step, the player's progression through the dungeon triggers different narrative elements, allowing the story to branch and develop based on predefined events. This is achieved through recursive functions that are structured to deliver specific scenes in a continuous flow, enabling the narrative to evolve as the player advances through the "levels" of the dungeon.

### Key Concepts

1. **Recursive Narrative Flow**:
    - The narrative is not simply linear but rather allows the player to experience different outcomes based on decisions and predefined events.
    - Each function in the code represents a "room" or scene the player enters, which is described with detailed, atmospheric text.
    - Recursion helps build a continuous flow in the story without needing to explicitly define each possible scene in a large sequence of if/else conditions.

2. **Function Calls and Depth**:
    - Each room description (such as `openArea`, `DustyChamber`, `ForkedPathway`, etc.) is called based on the current state or depth of the story.
    - As the player moves deeper into the dungeon, the description and complexity of the rooms increase. These deeper levels are designed to be triggered recursively as the player progresses, with the depth of recursion corresponding to the player's progression through the dungeon.

3. **Branching Based on Player Choices**:
    - Some rooms, such as the `ForkedPathway`, allow the player to choose between different paths. These choices are modeled with recursive function calls, where the player's choice can lead to different narrative branches.
    - This branching structure ensures that the recursion is not one-dimensional, and it keeps the story dynamic and responsive to player choices.

4. **Danger and Death Rooms**:
    - In high-difficulty rooms like `High_BoneshadePit` or `Death_AbyssalMaw`, recursion is used to represent the character's potential demise. If the player enters these rooms, the story will recursively "end" by printing death-related descriptions and marking the character's journey as complete with "**YOU DIED.**"
    - These rooms serve as critical points that can halt the progression and offer a sense of finality, ensuring that the story feels impactful even when the player "fails."

5. **Recursive Scene Transition**:
    - The function calls themselves represent recursive transitions. Each time a function for a room is called, it outputs the narrative and then potentially calls the next room or stage in the story.
    - For example, `Main_AtLevel5()` triggers further story progression and may even loop back to previous rooms if the narrative requires it, creating a non-linear, recursive experience where events and settings interconnect.

---

## User Instructions

### How to Play

1. **Launch the Game**: Run the program to begin your adventure. You will start at the **Dungeon Entrance**.
2. **Navigating the Dungeon**: The game is structured as a dungeon crawl, where you will enter different rooms. As you progress through the dungeon, each room presents a unique description and scenario. 
    - The player will encounter various environments, some dangerous and some more peaceful.
3. **Making Choices**: Some rooms will present you with choices. For example, you might encounter a **Forked Pathway** where you must choose one of two paths:
    - **Choice**: Do you want to explore the left path or the right path?
    - Your choice will impact the flow of the story and lead you down different paths.
4. **Progression**: As you make your way through the dungeon, the rooms will become more complex, and you will encounter more dangerous scenarios. Recursion ensures that the story adapts to your decisions, making each playthrough unique.
5. **Death and Victory**: If you encounter one of the **death rooms**, such as the **Death Abyssal Maw**, the story will end with "**YOU DIED.**"
    - **Death Room Example**: You might fall into a trap or face a deadly monster, halting your progress. 
    - If you manage to progress far enough, you may reach the end of the dungeon and win the game!

### Example Interaction

Here’s a sample of how the game might flow:

1. **Dungeon Entrance**: You enter a dimly lit cavern.
    - **Choice**: Do you want to explore the left path or the right path?
  
2. **Left Path**: The path seems to go deeper into the darkness. A faint sound echoes through the hall.
    - **Choice**: Do you press forward or turn back?

3. **Death Room (High_BoneshadePit)**: You fall into a pit of bones and darkness.
    - **Result**: "**YOU DIED.**"

---

## Base Cases and Recursive Cases in the Story Generation

### Recursive Cases

The **recursive cases** are the heart of the storytelling process, where the narrative evolves based on the player's progression through the dungeon. Each room or scenario in the dungeon is represented by a function that describes the scene and potentially triggers the next part of the story. The recursive nature allows the story to unfold as the player moves deeper into the dungeon.

For example:
- **Main_EnterCave**: This is the first scene where the player begins their journey. It describes the initial setting, and upon completing this scene, it may recursively call the next level function, such as `Main_AtLevel5()`, continuing the player’s journey.
- **Main_AtLevel5**: Once the player reaches Level 5, this function triggers a new description and sets up the narrative to proceed further. It may also recursively call subsequent rooms such as `Main_AtLevel10()` to describe further events as the player progresses.

Recursive cases can also involve **choices** (such as in `ForkedPathway`), where the player's decisions determine which room or path to take next. These decisions trigger different recursive calls based on the player's input, ensuring that the story adapts dynamically to the player's choices.

### Base Cases

The **base cases** represent the termination conditions for the recursive flow. When these conditions are met, the story stops progressing further, and the player either "dies" or wins the game, depending on the scenario.

- **Death Rooms**: Rooms like `Death_AbyssalMaw` or `Death_BroodNest` are examples of base cases. If the player enters these rooms, the story reaches a dead-end, and the program outputs "**YOU DIED.**" This serves as a termination point, halting the recursion and ending the story.

  Example:
  ```cpp
  void Story::Death_AbyssalMaw() {
      visual << indent << "You fall into the abyss, lost to time.\n";
      visual << indent << "**YOU DIED.**\n"; // End of recursion (base case)
  }
