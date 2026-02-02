OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnSmeByUsINQ
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnSmeByUsINQ.so
SOOBJS = TxnSmeByUsINQ.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
