OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/DpqMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDpqMsg.so
SOOBJS = DpqMsg.o DpqXml.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz  -ljson-c  -lexpat

all	: $(COMPSO)
