OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/OlnMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libOlnMsg.so
SOOBJS = OlnMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
