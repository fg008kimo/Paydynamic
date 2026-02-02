OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMgtByUs2Host
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMgtByUs2Host.so
SOOBJS = TxnMgtByUs2Host.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
