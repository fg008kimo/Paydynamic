OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/AtmMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libAtmMsg.so
SOOBJS = AtmMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
