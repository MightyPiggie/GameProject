# Game Project:
This is a project we made for the second semester of the second year at the Hogeschool Utrecht. The Goal of this project is to make a working game application. 
Our team decided to make our own version of CroasyRoad called "Levensmoedige kip"

# How the game works:
This game is a replica or an own made version of CroasyRoad. In this game you can be a character that is trying to run away from home, or atleast it is weary of life.
You need to walk around obstacals and moving cars and trains. Cross water without touching it so you don't drown. You can do this with the WASD or the arrow keys.
While evoiding all this you can collect coins to unlock new characters. You try to break a new highscore and compare it with your friends who the best running away bird/animal is.
Every character is buyable at 100 coins. They all work in the same enviroment and don't have special extra's.

Enjoy playing our game!

# Student Info:

The next students have worked on this project:

Naam|Studentnummer|GitHub username|
| ------------- |:-------------:| ---------:|
|Ray de Kruif|1787534|Rayax10|
|Daan Smienk|1777127|MightyPiggie|
|Rick Nuhaan|1787435|rick2003|
|Isaak van Luijk|1776211|SjaakyNewton|
|Rogier van Rooijen|1786347|RogiervR|

# Install information:

If you want to use this code you need the SFML libaray's.
In our school program environment you need to add a few lines in the make files of hwlib.
If you work with your own SFML you need to check if the Audio libary is in tact. I have no further information if this has a problem.

# School enviroment changes:

In the code there is a file openal32.dll
This file must be in the same place as the main.

In the root map you need to go to the hwlib map. Here you have to edit the makefile.inc
If you go to line 136 or #add SFML line. (Should be the same line)
Here you have a line with:
LINKER_FLAGS += -lsfml-<>-s
At the end you place -lsfml-audio-s

Now also add the next line before the DEFINES:
LINKER_FLAGS      += -lopenAl32 -lFLAC -lvorbisenc -lvorbisfile -lvorbis -logg

In the else and then the LINKER_FLAGS you can place at the end -lsfml-audio

This should make it work.
