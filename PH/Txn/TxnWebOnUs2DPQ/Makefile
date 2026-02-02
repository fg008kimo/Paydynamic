OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnWebOnUs2DPQ
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnWebOnUs2DPQ.so
SOOBJS = TxnWebOnUs2DPQ.o

include $(HOME)/config/Make.rules

LDLIBS +=
#CPPFLAGS += -D_SIMULATOR_

all     : $(COMPSO)
