OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnParDSIHand
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnParDSIHand.so
SOOBJS = TxnParDSIHand.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
