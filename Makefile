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

SOURCES := drawable.cpp game_screen.cpp player.cpp game_state_menu.cpp buttons.cpp object.cpp window_part.cpp sprite_factory.cpp simple_functions.cpp init_game.cpp label.cpp game_state_shop.cpp game_state_game.cpp game_state_dead.cpp level.cpp line.cpp label_player_settings.cpp

# header files in this project
HEADERS := drawable.hpp game_screen.hpp player.hpp game_state_menu.hpp buttons.hpp object.hpp window_part.hpp sprite_factory.hpp simple_functions.hpp init_game.hpp label.hpp game_state_shop.hpp game_state_game.hpp game_state_dead.hpp game_states.hpp game_settings.hpp level.hpp line.hpp label_player_settings.hpp

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.native
