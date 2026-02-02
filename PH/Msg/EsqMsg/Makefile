OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/EsqMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libEsqMsg.so
SOOBJS = EsqMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz -ljson-c

all	: $(COMPSO)
