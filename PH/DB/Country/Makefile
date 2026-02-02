OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/Country
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBCountry.so
SOOBJS =  Country.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
