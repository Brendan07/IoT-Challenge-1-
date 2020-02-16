# WALL-E
WALL-E is a timed challenge game for the BBC microbit controller.

# Overview 
WALL-E is a game where WALL-E, a red dot on the LED matirx must collect a item as much as possible in 60 seconds. The item(s) are displayed as flashing red dots on the LED matrix and each time WALL-E collects a item he receives 1 point. Each time the WALL-E collects a item, a new item will apper in a random location on the LED matrix. After 30 seconds, 2 Items will start appearing on the LED matrix
When 60 seconds is up "GAME OVER" will display then the players score, the player will be taken back to the menu after this.

# How To Play
Hold A or B to start the game after the inital text is displayed.

The player must tilt the microbit in the direction the player wants to move.

The player can collect a item by moving WALL-E on the same position as the item.

# Build 

1.main.cpp - Main application code

microbit-samples/source/main.cpp

# Running Instructions

Commands Required Initially

1.yt target bbc-microbit-classic-gcc

2.yt build

The executable can be found inside /build/bbc-microbit-classic-gcc/source, with the executable being named project_name-combined.hex

Copy this file to /media/username/MICROBIT

# Note

Items in corner on the LED matrix are harder to collect, full tilt to collect corner items.
