OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/TwvMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTwvMsg.so
SOOBJS = TwvMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
