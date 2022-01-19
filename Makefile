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
SOURCES := drawable.cpp player.cpp buttons.cpp obstacle.cpp menu.cpp sprite_factory.cpp builder.cpp

# header files in this project
HEADERS :=  drawable.hpp game_screen.hpp player.hpp menu.hpp gamestates.hpp buttons.hpp obstacle.hpp window_part.hpp sprite_factory.hpp builder.hpp simplefunction.hpp list_includes.hpp

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)./
include $(RELATIVE)Makefile.native
