OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/XjeMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libXjeMsg.so
SOOBJS = XjeMsg.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash -lz -ljson-c

all	: $(COMPSO)
