OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/RpyMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libRpyMsg.so
SOOBJS = RpyMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
