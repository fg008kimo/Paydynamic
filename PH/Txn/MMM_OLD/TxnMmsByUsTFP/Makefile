OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmsByUsTFP
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmsByUsTFP.so
SOOBJS = TxnMmsByUsTFP.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
