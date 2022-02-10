#!/bin/bash

mkdir -p bin

for app in nandBinCheck nandFixer nandCbhcRemover fileInjector
do
    cd $app
    qmake
    make -j4
    cp $app ../bin
    cd ..
done
