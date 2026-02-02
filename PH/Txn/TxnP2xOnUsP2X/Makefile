OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnP2xOnUsP2X
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnP2xOnUsP2X.so
SOOBJS = TxnP2xOnUsP2X.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
