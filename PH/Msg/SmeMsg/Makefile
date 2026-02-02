OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/SmeMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libSmeMsg.so
SOOBJS = SmeMsg.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash -lz

all	: $(COMPSO)
