OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/OLDefSubProvider
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBOLDefSubProvider.so
SOOBJS =  OLDefSubProvider.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
