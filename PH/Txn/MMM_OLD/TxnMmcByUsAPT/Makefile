OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmcByUsAPT
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmcByUsAPT.so
SOOBJS = TxnMmcByUsAPT.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
