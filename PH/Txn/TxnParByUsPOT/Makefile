OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnParByUsPOT
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnParByUsPOT.so
SOOBJS = TxnParByUsPOT.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
