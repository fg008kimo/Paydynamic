OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/OmtMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libOmtMsg.so
SOOBJS = OmtMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz -lexpat

all	: $(COMPSO)
