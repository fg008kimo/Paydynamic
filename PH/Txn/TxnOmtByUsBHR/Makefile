OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOmtByUsBHR
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOmtByUsBHR.so
SOOBJS = TxnOmtByUsBHR.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)

