OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMgtByUsEAT
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMgtByUsEAT.so
SOOBJS = TxnMgtByUsEAT.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
