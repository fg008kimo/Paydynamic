OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/XpvMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libXpvMsg.so
SOOBJS = XpvMsg.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash -lz

all	: $(COMPSO)
