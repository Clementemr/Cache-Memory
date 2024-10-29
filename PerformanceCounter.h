#include <chrono>
#ifndef PERFORMANCECOUNTER_H
#define PERFORMANCECOUNTER_H

class PerformanceCounter {

    private:
        int hits;
        int misses;
        int reads;
        int writes;
        int accesses;
        long start_time;
        long end_time;
        long total_time;
        int writeBacks;

        
    
    public:
        PerformanceCounter();
        void start();
        void stop();
        void display();
        void reset();
        int getHits();
        int getMisses();
        int getReads();
        int getWrites();
        long getStartTime();
        long getEndTime();
        long getTotalTime();
        void incrementHits();
        void incrementMisses();
        void incrementReads();
        void incrementWrites();
        void incrementAccesses();
        int getAccesses();
        void incrementWriteBacks();
        int getWriteBacks();

        
        

};

#endif