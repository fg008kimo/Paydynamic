OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnAlpByUsPOL
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnAlpByUsPOL.so
SOOBJS = TxnAlpByUsPOL.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
