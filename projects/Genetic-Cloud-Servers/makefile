################################################################################
################################################################################
##                                                                            ##
##    Genetic-Cloud-Servers                                                   ##
##                                                                            ##
##    A satirical internet protocol attempting to stymie packet sniffers.     ##
##                                                                            ##
##                                                                            ##
##                                                                            ##
##    Please note.  The header file dependences are not complete in this      ##
##    makefile.  If any changes are made to header files, please `make clean' ##
##    before executing `make all'.                                            ##
##                                                                            ##
##                                                                            ##
##                       Copyright 2019  Daniel Huffman  All rights reserved. ##
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



EXECS       = gcsCloudShepard GeneticCloudServer

GCSS_HEADERS= GeneticCloudServer.h gcsDNA_o.h gcsStatusPacket_o.h gcsCloudShepard.h \
              gcsLoad_o.h gcsVMInfo_o.h MatchVMService_o.h

GCSS_OBJS   = gcsDNA_o.o gcsStatusPacket_o.o gcsLoad_o.o gcsVMInfo_o.o MatchVMService_o.o


################################################################################
## All.                                                                       ##
################################################################################

all:
	@echo "Genetic-Cloud-Servers  v0.200     07.31.2019"
	@echo "Copyright 2019  Daniel Huffman  All rights reserved."
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

MatchVMService_o.o: ./servers/MatchVMService_o.h ./servers/MatchVMService_o.cc
	$(CC) $(OBJFLAGS) -c ./servers/MatchVMService_o.cc


GeneticCloudServer.o: ./servers/GeneticCloudServer.h ./servers/GeneticCloudServer.cc
	$(CC) $(OBJFLAGS) -c ./servers/GeneticCloudServer.cc

GeneticCloudServer: GeneticCloudServer.o $(GCSS_OBJS)
	$(CC) $(LINKFLAGS) -o GeneticCloudServer                             \
        $(GCSS_OBJS)                                                           \
        -Wl,--start-group \
        -lpserver_o    \
        -lplib_o                  \
        -lgenetic_o    \
        GeneticCloudServer.o                                                 \
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



################################################################################
## Clean.                                                                     ##
################################################################################
clean:
	rm -f *.o *.log $(EXECS)


################################################################################
################################################################################
