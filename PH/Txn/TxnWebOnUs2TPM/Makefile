OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnWebOnUs2TPM
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnWebOnUs2TPM.so
SOOBJS = TxnWebOnUs2TPM.o

include $(HOME)/config/Make.rules

LDLIBS +=
#CPPFLAGS += -D_SIMULATOR_

all     : $(COMPSO)
