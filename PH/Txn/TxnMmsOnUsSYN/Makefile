OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmsOnUsSYN
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmsOnUsSYN.so
SOOBJS = TxnMmsOnUsSYN.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
