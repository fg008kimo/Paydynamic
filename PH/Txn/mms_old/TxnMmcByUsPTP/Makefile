OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmcByUsPTP
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmcByUsPTP.so
SOOBJS = TxnMmcByUsPTP.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
