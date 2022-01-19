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
SOURCES := drawable.cpp player.cpp buttons.cpp obstacle.cpp menu.cpp sprite_factory.cpp label.cpp

# header files in this project
HEADERS :=  simplefunction.hpp drawable.hpp game_screen.hpp player.hpp menu.hpp gamestates.hpp buttons.hpp label.hpp obstacle.hpp window_part.hpp sprite_factory.hpp list_includes.hpp

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)./
include $(RELATIVE)Makefile.native
