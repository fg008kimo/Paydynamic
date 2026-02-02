OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/EmlMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libEmlMsg.so
SOOBJS = EmlMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lmyrecordset

all	: $(COMPSO)
