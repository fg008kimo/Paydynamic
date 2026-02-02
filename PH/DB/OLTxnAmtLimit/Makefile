OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/OLTxnAmtLimit
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBOLTxnAmtLimit.so
SOOBJS =  OLTxnAmtLimit.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
