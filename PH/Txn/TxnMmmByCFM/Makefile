OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmmByUsCFM
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmmByUsCFM.so
SOOBJS = TxnMmmByUsCFM.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
