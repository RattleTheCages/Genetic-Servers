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

OBJFLAGS    = -g -I$(PLIB_INCLUDE)

#LINKFLAGS   = -pthread -L$(PLIB_DIR) -L$(GENETIC_DIR) -L$(PSERVER_DIR) -Wl,--start-group -lpserver_o -lplib_o -lgenetic_o -lplib_o -Wl,--end-group
LINKFLAGS   = -pthread -L$(PLIB_DIR) -L$(GENETIC_DIR) -L$(PSERVER_DIR)



EXECS       = GeneticCloudServer_o CloudShepard_o

GCSS_HEADERS= GeneticCloudServer_o.h GeneticCloudServerDNA_o.h CloudShepardPacket_o.h CloudShepard_o.h
GCSS_OBJS   = GeneticCloudServerDNA_o.o CloudShepardPacket_o.o


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

GeneticCloudServer_o.o: GeneticCloudServer_o.h GeneticCloudServer_o.cc
	$(CC) $(OBJFLAGS) -c GeneticCloudServer_o.cc

GeneticCloudServerDNA_o.o: GeneticCloudServerDNA_o.h GeneticCloudServerDNA_o.cc
	$(CC) $(OBJFLAGS) -c GeneticCloudServerDNA_o.cc

CloudShepardPacket_o.o: CloudShepardPacket_o.h CloudShepardPacket_o.cc
	$(CC) $(OBJFLAGS) -c CloudShepardPacket_o.cc

CloudShepard_o.o: CloudShepard_o.h CloudShepard_o.cc
	$(CC) $(OBJFLAGS) -c CloudShepard_o.cc

GeneticCloudServer_o: GeneticCloudServer_o.o $(GCSS_OBJS)
	$(CC) $(LINKFLAGS) -o GeneticCloudServer_o                             \
        $(GCSS_OBJS)                                                           \
        -Wl,--start-group \
        -lpserver_o    \
        -lplib_o                  \
        -lgenetic_o    \
        GeneticCloudServer_o.o                                                 \
        -Wl,--end-group \

CloudShepard_o: CloudShepard_o.o $(GCSS_OBJS)
	$(CC) $(LINKFLAGS) -o CloudShepard_o               \
        $(GCSS_OBJS)                                                           \
         CloudShepard_o.o                                                 \
        -lpserver_o    \
        -lgenetic_o    \
        -lplib_o                  \



################################################################################
## Clean.                                                                     ##
################################################################################
clean:
	rm -f *.o $(EXECS)


################################################################################
################################################################################
