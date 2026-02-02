OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnParDSIApp
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnParDSIApp.so
SOOBJS = TxnParDSIApp.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
