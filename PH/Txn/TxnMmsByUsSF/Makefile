OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmsByUsSF
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmsByUsSF.so
SOOBJS = TxnMmsByUsSF.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
