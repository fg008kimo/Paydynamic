OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/BO/BOOiaSecurity
COMPLIBHOME = $(HOME)/lib/BO
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libBOOiaSecurity.so
SOOBJS = BOOiaSecurity.o

include $(HOME)/config/Make.rules

LDLIBS += -lssl -lcrypto
all     : $(COMPSO)
