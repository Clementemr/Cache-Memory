Simulation: Simulation.o Set.o Cache.o Memory.o Block.o AddressDecoder.o PerformanceCounter.o
	g++ -o Simulation Simulation.o Set.o Cache.o Memory.o Block.o AddressDecoder.o PerformanceCounter.o

Simulation.o: Simulation.cc Set.h Cache.h Memory.h Block.h AddressDecoder.h PerformanceCounter.h
	g++ -c Simulation.cc

Set.o: Set.cc Set.h
	g++ -c Set.cc

Cache.o: Cache.cc Cache.h
	g++ -c Cache.cc

Memory.o: Memory.cc Memory.h
	g++ -c Memory.cc

Block.o: Block.cc Block.h
	g++ -c Block.cc

AddressDecoder.o: AddressDecoder.cc AddressDecoder.h
	g++ -c AddressDecoder.cc

PerformanceCounter.o: PerformanceCounter.cc PerformanceCounter.h
	g++ -c PerformanceCounter.cc

clean:
	rm -f *.o
	rm -f Simulation

