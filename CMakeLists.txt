cmake_minimum_required(VERSION 3.10)
project(CS362_004_F2018 C)

set(CMAKE_C_STANDARD 11)

include_directories(dominion)
include_directories(projects/shaikj/dominion)

add_executable(CS362_004_F2018
        dominion/badTestDrawCard.c
        dominion/betterTestDrawCard.c
        dominion/dominion.c
        dominion/dominion.gcda
        dominion/dominion.h
        dominion/dominion_helpers.h
        dominion/interface.c
        dominion/interface.h
        dominion/playdom.c
        dominion/playdom.gcda
        dominion/player.c
        dominion/READM.md
        dominion/rngs.c
        dominion/rngs.gcda
        dominion/rngs.h
        dominion/rt.c
        dominion/supplyTest.c
        dominion/testBuyCard.c
        dominion/testDrawCard.c
        dominion/testInit.c
        dominion/testShuffle.c
        projects/harrisrv/README.md
        projects/shaikj/dominion/badTestDrawCard.c
        projects/shaikj/dominion/betterTestDrawCard.c
        projects/shaikj/dominion/dominion.c
        projects/shaikj/dominion/dominion.h
        projects/shaikj/dominion/dominion_helpers.h
        projects/shaikj/dominion/interface.c
        projects/shaikj/dominion/interface.h
        projects/shaikj/dominion/playdom.c
        projects/shaikj/dominion/player.c
        projects/shaikj/dominion/rngs.c
        projects/shaikj/dominion/rngs.h
        projects/shaikj/dominion/rt.c
        projects/shaikj/dominion/supplyTest.c
        projects/shaikj/dominion/testBuyCard.c
        projects/shaikj/dominion/testDrawCard.c
        projects/shaikj/dominion/testInit.c
        projects/shaikj/dominion/testShuffle.c
        projects/README.md
        README.md dominion/unitTests/unittest1.c dominion/unitTests/unittest2.c dominion/unitTests/unittest3.c dominion/unitTests/unittest4.c dominion/unitTests/cardtest1.c dominion/unitTests/cardtest2.c dominion/unitTests/cardtest3.c dominion/unitTests/cardtest4.c dominion/unitTests/testUtility.c dominion/unitTests/testUtility.h projects/harrisrv/dominion/randomTests/randomtestcard1.c projects/harrisrv/dominion/randomTests/testUtility.c projects/harrisrv/dominion/randomTests/testUtility.h projects/harrisrv/dominion/randomTests/randomtestcard2.c projects/harrisrv/dominion/randomTests/randomtestadventurer.c)
