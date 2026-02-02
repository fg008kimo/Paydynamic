OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnCctOnUsCCT
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnCctOnUsCCT.so
SOOBJS = TxnCctOnUsCCT.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
