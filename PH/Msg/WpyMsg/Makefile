OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/WpyMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libWpyMsg.so
SOOBJS = WpyMsg.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash -lz

all	: $(COMPSO)
