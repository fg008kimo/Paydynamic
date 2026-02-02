OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/SfeMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libSfeMsg.so
SOOBJS = SfeMsg.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash -lz -ljson-c

all	: $(COMPSO)
