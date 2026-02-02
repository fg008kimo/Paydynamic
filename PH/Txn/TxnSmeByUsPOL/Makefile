OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnSmeByUsPOL
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnSmeByUsPOL.so
SOOBJS = TxnSmeByUsPOL.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
