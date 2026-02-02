OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/OlcMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libOlcMsg.so
SOOBJS = OlcMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
