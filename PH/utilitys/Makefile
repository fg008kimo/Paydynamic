OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/utilitys
COMPLIBHOME = $(HOME)/lib/utilitys
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libutilitys.so 
SOOBJS =  des.o \
	ascutility.o \
	numutility.o \
	comutil.o \
	dates.o \
	debug.o \
	logmsg.o \
	sec.o \
	mymd5.o \
	b64.o \
	sha1.o \
	langconvert.o \
	sha1rsa.o \
	blowfishp.o \
	email.o \
	urlcodes.o \
	tpllib.o \
	tplutil.o  \
	rsa.o	\
	aes.o	\
	mystrings.o     \
	syscall.o

include $(HOME)/config/Make.rules

LDLIBS =  -lssl -liconv -lzlog -lpthread

all	: $(COMPSO)
