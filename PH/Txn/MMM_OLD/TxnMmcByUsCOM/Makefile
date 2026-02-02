OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmcByUsCOM
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmcByUsCOM.so
SOOBJS = TxnMmcByUsCOM.o

include $(HOME)/config/Make.rules

LDLIBS +=

all     : $(COMPSO)
