OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMgtByUsTSI
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMgtByUsTSI.so
SOOBJS = TxnMgtByUsTSI.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
