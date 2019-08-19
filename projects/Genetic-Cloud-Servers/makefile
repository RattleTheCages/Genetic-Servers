################################################################################
################################################################################
##                               Copyright 2019  Rattle  All rights reserved. ##
##                                                                            ##
##    Genetic Cloud Servers                                                   ##
##                                                                            ##
##                                                                            ##
##                                                                            ##
##                                                                            ##
##                                                                            ##
##                                                                            ##
##    Please note.  The header file dependences are not complete in this      ##
##    makefile.  If any changes are made to header files, please `make clean' ##
##    before executing `make all'.                                            ##
##                                                                            ##
##                                                                            ##
################################################################################
################################################################################


CC          = g++

PSERVER_DIR = ../../../Code-from-the-90s/projects/library/pserver/
PLIB_DIR    = ../../../Code-from-the-90s/projects/library/lib/
PLIB_INCLUDE= ../../../Code-from-the-90s/projects/library/include
GENETIC_DIR = ../../../Code-from-the-90s/projects/library/genetic/


OBJFLAGS    = -g -I$(PLIB_INCLUDE) -I./containers

LINKFLAGS   = -pthread -L$(PLIB_DIR) -L$(GENETIC_DIR) -L$(PSERVER_DIR)



EXECS       = gcsCloudShepard gcsGeneticCloudServer gcsLoadSimulator

GCSS_HEADERS= gcsGeneticCloudServer.h gcsDNA_o.h gcsStatusPacket_o.h gcsCloudShepard.h \
              gcsLoad_o.h gcsVMInfo_o.h gcsExpressServerDNA_o.h gcsLoadSimulator.h

GCSS_OBJS   = gcsDNA_o.o gcsStatusPacket_o.o gcsLoad_o.o gcsVMInfo_o.o gcsExpressServerDNA_o.o


################################################################################
## All.                                                                       ##
################################################################################

all:
	@echo "Genetic Cloud Servers  v0.200     08.08.2019"
	@echo "Copyright 2019  Rattle  All rights reserved."
	@echo `date`
	make $(GCSS_OBJS)
	make $(EXECS)
	@echo `date`


################################################################################
##                                                                            ##
################################################################################

gcsDNA_o.o: ./containers/gcsDNA_o.h ./containers/gcsDNA_o.cc
	$(CC) $(OBJFLAGS) -c ./containers/gcsDNA_o.cc

gcsLoad_o.o: ./containers/gcsLoad_o.h ./containers/gcsLoad_o.cc
	$(CC) $(OBJFLAGS) -c ./containers/gcsLoad_o.cc

gcsVMInfo_o.o: ./containers/gcsVMInfo_o.h ./containers/gcsVMInfo_o.cc
	$(CC) $(OBJFLAGS) -c ./containers/gcsVMInfo_o.cc

gcsStatusPacket_o.o: ./containers/gcsStatusPacket_o.h ./containers/gcsStatusPacket_o.cc
	$(CC) $(OBJFLAGS) -c ./containers/gcsStatusPacket_o.cc

gcsMatchVMService_o.o: ./servers/gcsMatchVMService_o.h ./servers/gcsMatchVMService_o.cc
	$(CC) $(OBJFLAGS) -c ./servers/MatchVMService_o.cc

gcsExpressServerDNA_o.o: ./servers/gcsExpressServerDNA_o.h ./servers/gcsExpressServerDNA_o.cc
	$(CC) $(OBJFLAGS) -c ./servers/gcsExpressServerDNA_o.cc


gcsGeneticCloudServer.o: ./servers/gcsGeneticCloudServer.h ./servers/gcsGeneticCloudServer.cc
	$(CC) $(OBJFLAGS) -c ./servers/gcsGeneticCloudServer.cc

gcsGeneticCloudServer: gcsGeneticCloudServer.o $(GCSS_OBJS)
	$(CC) $(LINKFLAGS) -o gcsGeneticCloudServer                             \
        $(GCSS_OBJS)                                                           \
        -Wl,--start-group \
        -lpserver_o    \
        -lplib_o                  \
        -lgenetic_o    \
        gcsGeneticCloudServer.o                                                 \
        -Wl,--end-group \


gcsCloudShepard.o: ./executives/gcsCloudShepard.h ./executives/gcsCloudShepard.cc
	$(CC) $(OBJFLAGS) -c ./executives/gcsCloudShepard.cc

gcsCloudShepard: gcsCloudShepard.o $(GCSS_OBJS)
	$(CC) $(LINKFLAGS) -o gcsCloudShepard               \
        $(GCSS_OBJS)                                                           \
        gcsCloudShepard.o                                                 \
        -lgenetic_o    \
        -lpserver_o    \
        -lplib_o                  \

gcsLoadSimulator.o: ./tests/gcsLoadSimulator.h ./tests/gcsLoadSimulator.cc
	$(CC) $(OBJFLAGS) -c ./tests/gcsLoadSimulator.cc

gcsLoadSimulator: gcsLoadSimulator.o $(GCSS_OBJS)
	$(CC) $(LINKFLAGS) -o gcsLoadSimulator               \
        gcsStatusPacket_o.o    \
        gcsLoad_o.o    \
        gcsVMInfo_o.o   \
        gcsLoadSimulator.o                                                 \
        -lpserver_o    \
        -lplib_o                  \



################################################################################
## Clean.                                                                     ##
################################################################################
clean:
	rm -f *.o *.log $(EXECS)


################################################################################
################################################################################
