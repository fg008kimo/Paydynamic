OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/TpeMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTpeMsg.so
SOOBJS = TpeMsg.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash -lz -ljson-c

all	: $(COMPSO)
