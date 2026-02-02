OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/PgnMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libPgnMsg.so
SOOBJS = PgnMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz 

all	: $(COMPSO)
