cmake_minimum_required(VERSION 3.10)
project(harrisrv)

set(CMAKE_CXX_STANDARD 11)

include_directories(dominion)
include_directories(dominion/randomTests)

add_executable(harrisrv
        dominion/randomTests/randomtestcard1.c
        dominion/randomTests/randomtestcard2.c
        dominion/randomTests/testUtility.c
        dominion/randomTests/testUtility.h
        dominion/badTestDrawCard.c
        dominion/betterTestDrawCard.c
        dominion/dominion.c
        dominion/dominion.h
        dominion/dominion_helpers.h
        dominion/interface.c
        dominion/interface.h
        dominion/Makefile
        dominion/playdom.c
        dominion/player.c
        dominion/rngs.c
        dominion/rngs.h
        dominion/rt.c
        dominion/supplyTest.c
        dominion/testBuyCard.c
        dominion/testDrawCard.c
        dominion/testInit.c
        dominion/testShuffle.c
        README.md)
