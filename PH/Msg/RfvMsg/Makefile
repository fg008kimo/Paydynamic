OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/RfvMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libRfvMsg.so
SOOBJS = RfvMsg.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash -lz -ljson-c

all	: $(COMPSO)
