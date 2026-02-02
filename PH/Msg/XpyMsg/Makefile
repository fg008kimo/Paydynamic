OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/XpyMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libXpyMsg.so
SOOBJS = XpyMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lmyrecordset

all	: $(COMPSO)
