OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/DefServiceCode
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBDefServiceCode.so
SOOBJS =  DefServiceCode.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
