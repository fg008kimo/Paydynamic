OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOiaByUsLST
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOiaByUsLST.so
SOOBJS = TxnOiaByUsLST.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
