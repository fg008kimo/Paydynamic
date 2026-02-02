OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/NepMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libNepMsg.so
SOOBJS = NepMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz -ljson-c

all	: $(COMPSO)
