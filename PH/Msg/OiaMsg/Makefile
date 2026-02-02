OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/OiaMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libOiaMsg.so
SOOBJS = OiaMsg.o 

include $(HOME)/config/Make.rules

LDFLAGS += -L$(HOME)/lib/Msg
LDLIBS += -lmyhash  -lz -lmsg

all	: $(COMPSO)
