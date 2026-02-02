OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOiaByUsAUC
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOiaByUsAUC.so
SOOBJS = TxnOiaByUsAUC.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
