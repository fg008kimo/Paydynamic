OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/OupMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libOupMsg.so
SOOBJS = OupMsg.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash -lz

all	: $(COMPSO)
