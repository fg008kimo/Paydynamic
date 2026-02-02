OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMifByUsEAC
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMifByUsEAC.so
SOOBJS = TxnMifByUsEAC.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
