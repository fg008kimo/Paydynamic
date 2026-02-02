OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/EcmMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libEcmMsg.so
SOOBJS = EcmMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
