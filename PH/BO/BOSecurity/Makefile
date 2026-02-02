OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/BO/BOSecurity
COMPLIBHOME = $(HOME)/lib/BO
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libBOSecurity.so
SOOBJS = BOSecurity.o

include $(HOME)/config/Make.rules

LDLIBS += -lssl -lcrypto
CPPFLAGS += -D_SIMULATOR_
all     : $(COMPSO)
