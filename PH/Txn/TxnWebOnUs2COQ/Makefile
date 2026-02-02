OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnWebOnUs2COQ
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnWebOnUs2COQ.so
SOOBJS = TxnWebOnUs2COQ.o

include $(HOME)/config/Make.rules

LDLIBS +=
#CPPFLAGS += -D_SIMULATOR_

all     : $(COMPSO)
