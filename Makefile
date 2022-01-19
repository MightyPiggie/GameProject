#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := drawable.cpp player.cpp buttons.cpp obstacle.cpp menu.cpp sprite_factory.cpp builder.cpp game_screen.cpp simple_functions.cpp window_part.cpp init_game.cpp label.cpp

# header files in this project
HEADERS :=  drawable.hpp game_screen.hpp player.hpp menu.hpp game_states.hpp buttons.hpp obstacle.hpp window_part.hpp sprite_factory.hpp builder.hpp simple_functions.hpp game_object.hpp label.hpp

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)./
include $(RELATIVE)Makefile.native
