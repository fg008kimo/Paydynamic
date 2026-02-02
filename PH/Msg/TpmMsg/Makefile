OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/TpmMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTpmMsg.so
SOOBJS = TpmMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
