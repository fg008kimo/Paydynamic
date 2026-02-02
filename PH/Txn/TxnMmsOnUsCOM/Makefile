OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmsOnUsCOM
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmsOnUsCOM.so
SOOBJS = TxnMmsOnUsCOM.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
