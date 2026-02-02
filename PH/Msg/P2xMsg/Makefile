OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/P2xMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libP2xMsg.so
SOOBJS = P2xMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
