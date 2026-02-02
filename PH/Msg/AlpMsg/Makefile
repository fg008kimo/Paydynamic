OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/AlpMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libAlpMsg.so
SOOBJS = AlpMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
