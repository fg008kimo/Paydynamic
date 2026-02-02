OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/HxqMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libHxqMsg.so
SOOBJS = HxqMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz  -ljson-c

all	: $(COMPSO)
