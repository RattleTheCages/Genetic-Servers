# Genetic-Servers
Cloud visualized clusters of servers, self optimized using a genetic algorithm AI.

In the visualized cloud environment, virtual machines are constantly started and stopped as the load changes.  This process of frequently starting and stopping processes lends itself well to the genetic algorithm of spawning new entities while eliminating lesser performers.
To accomplish this, each server instance is afforded a set of DNA chromosomes that will control aspects of the performance of the underlying server.
Periodically the shepherd server will evaluate the performance of each server and reproduce, the DNA, of high performing servers, while eliminating poorer performing servers.
This constant upgrading will continually optimize the cluster of server's performs as traffic changes and the nature of processing the requests change.
