OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/TxnAckRetry
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBTxnAckRetry.so
SOOBJS =  TxnAckRetry.o

include $(HOME)/config/Make.rules

LDLIBS +=

all	: $(COMPSO)
