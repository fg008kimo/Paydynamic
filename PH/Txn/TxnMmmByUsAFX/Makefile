OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmmByUsAFX
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmmByUsAFX.so
SOOBJS = TxnMmmByUsAFX.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
