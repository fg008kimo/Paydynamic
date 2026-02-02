OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnParByUsMAD
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnParByUsMAD.so
SOOBJS = TxnParByUsMAD.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
