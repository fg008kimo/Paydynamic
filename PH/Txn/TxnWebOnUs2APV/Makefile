OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnWebOnUs2APV
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnWebOnUs2APV.so
SOOBJS = TxnWebOnUs2APV.o

include $(HOME)/config/Make.rules

LDLIBS +=
#CPPFLAGS += -D_SIMULATOR_

all     : $(COMPSO)
