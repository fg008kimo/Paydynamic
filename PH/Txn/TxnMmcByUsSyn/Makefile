OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmcByUsSyn
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmcByUsSyn.so
SOOBJS = TxnMmcByUsSyn.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
