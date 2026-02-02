OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMifByUsCOM
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMifByUsCOM.so
SOOBJS = TxnMifByUsCOM.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
