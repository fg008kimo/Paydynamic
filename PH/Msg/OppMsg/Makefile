OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/OppMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libOppMsg.so
SOOBJS = OppMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
