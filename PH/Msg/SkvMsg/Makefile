OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/SkvMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libSkvMsg.so
SOOBJS = SkvMsg.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash -lz

all	: $(COMPSO)
