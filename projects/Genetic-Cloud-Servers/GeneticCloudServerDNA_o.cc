/**  GeneticCloudServerDNA_o.cc  ***********************************************

            Genetic-Cloud-Servers



            Server DNA



                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/

#include "GeneticCloudServerDNA_o.h"


GeneticCloudServerDNA_o::GeneticCloudServerDNA_o() : State(2) , entity_o(2002, 8, 200, 2002, "bob", 2002)  {}

GeneticCloudServerDNA_o::GeneticCloudServerDNA_o(const entity_o& entity) : State(2) , entity_o(entity)  {}

GeneticCloudServerDNA_o::GeneticCloudServerDNA_o(const GeneticCloudServerDNA_o& dna) : State(2) , entity_o(dna)  {}


GeneticCloudServerDNA_o::~GeneticCloudServerDNA_o()  {}


/******************************************************************************/
