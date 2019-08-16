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



EXECS       = GeneticCloudServer_o gcsCloudShepard_o

GCSS_HEADERS= GeneticCloudServer_o.h gcsDNA_o.h gcsShepardPacket_o.h gcsCloudShepard_o.h \
              gcsLoad.h

GCSS_OBJS   = gcsDNA_o.o gcsShepardPacket_o.o gcsLoad.o


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

GeneticCloudServer_o.o: ./servers/GeneticCloudServer_o.h ./servers/GeneticCloudServer_o.cc
	$(CC) $(OBJFLAGS) -c ./servers/GeneticCloudServer_o.cc

gcsDNA_o.o: ./containers/gcsDNA_o.h ./containers/gcsDNA_o.cc
	$(CC) $(OBJFLAGS) -c ./containers/gcsDNA_o.cc

gcsLoad.o: ./containers/gcsLoad.h ./containers/gcsLoad.cc
	$(CC) $(OBJFLAGS) -c ./containers/gcsLoad.cc

gcsShepardPacket_o.o: ./containers/gcsShepardPacket_o.h ./containers/gcsShepardPacket_o.cc
	$(CC) $(OBJFLAGS) -c ./containers/gcsShepardPacket_o.cc

gcsCloudShepard_o.o: ./executives/gcsCloudShepard_o.h ./executives/gcsCloudShepard_o.cc
	$(CC) $(OBJFLAGS) -c ./executives/gcsCloudShepard_o.cc

GeneticCloudServer_o: GeneticCloudServer_o.o $(GCSS_OBJS)
	$(CC) $(LINKFLAGS) -o GeneticCloudServer_o                             \
        $(GCSS_OBJS)                                                           \
        -Wl,--start-group \
        -lpserver_o    \
        -lplib_o                  \
        -lgenetic_o    \
        GeneticCloudServer_o.o                                                 \
        -Wl,--end-group \

gcsCloudShepard_o: gcsCloudShepard_o.o $(GCSS_OBJS)
	$(CC) $(LINKFLAGS) -o gcsCloudShepard_o               \
        $(GCSS_OBJS)                                                           \
        gcsCloudShepard_o.o                                                 \
        -lgenetic_o    \
        -lpserver_o    \
        -lplib_o                  \



################################################################################
## Clean.                                                                     ##
################################################################################
clean:
	rm -f *.o $(EXECS)


################################################################################
################################################################################
