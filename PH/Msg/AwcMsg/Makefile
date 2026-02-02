OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/AwcMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libAwcMsg.so
SOOBJS = AwcMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz  -ljson-c

all	: $(COMPSO)
