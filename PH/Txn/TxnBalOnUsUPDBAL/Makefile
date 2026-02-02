OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnBalOnUsUPDBAL
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnBalOnUsUPDBAL.so
SOOBJS = TxnBalOnUsUPDBAL.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
