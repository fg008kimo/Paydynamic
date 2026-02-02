OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/UnqMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libUnqMsg.so
SOOBJS = UnqMsg.o UnqXml.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz  -ljson-c  -lexpat

all	: $(COMPSO)
