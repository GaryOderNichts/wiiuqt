#!/bin/bash

for app in nandBinCheck nandFixer nandCbhcRemover fileInjector
do
    cd $app
    make clean
    rm $app
    cd ..
done

rm -rf bin
