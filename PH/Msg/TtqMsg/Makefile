OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/TtqMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTtqMsg.so
SOOBJS = TtqMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz -ljson-c

all	: $(COMPSO)
