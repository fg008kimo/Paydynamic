OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnWebOnUs2NEQ
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnWebOnUs2NEQ.so
SOOBJS = TxnWebOnUs2NEQ.o

include $(HOME)/config/Make.rules

LDLIBS +=
#CPPFLAGS += -D_SIMULATOR_

all     : $(COMPSO)
