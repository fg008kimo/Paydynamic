OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmcByUs2Host
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmcByUs2Host.so
SOOBJS = TxnMmcByUs2Host.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
