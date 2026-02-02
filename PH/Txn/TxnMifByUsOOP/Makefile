OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMifByUsOOP
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMifByUsOOP.so
SOOBJS = TxnMifByUsOOP.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
