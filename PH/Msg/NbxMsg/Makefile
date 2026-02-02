OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/NbxMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libNbxMsg.so
SOOBJS = NbxMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
