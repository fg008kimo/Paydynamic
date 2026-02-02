OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmsOnUsSTT
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmsOnUsSTT.so
SOOBJS = TxnMmsOnUsSTT.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
