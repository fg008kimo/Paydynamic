OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/XyeMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libXyeMsg.so
SOOBJS = XyeMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz -ljson-c

all	: $(COMPSO)
