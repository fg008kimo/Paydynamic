OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmcByUsBTB
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmcByUsBTB.so
SOOBJS = TxnMmcByUsBTB.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
