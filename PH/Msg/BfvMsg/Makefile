OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/BfvMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libBfvMsg.so
SOOBJS = BfvMsg.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash -lz -ljson-c

all	: $(COMPSO)
