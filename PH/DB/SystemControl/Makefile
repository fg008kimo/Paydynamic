OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/SystemControl
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBSystemControl.so
SOOBJS =  SystemControl.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
