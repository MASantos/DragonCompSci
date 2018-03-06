#!/bin/bash

mOUTF=programmingPython.md
pOUTF=`echo $mOUTF | sed 's@\.md@.pdf@g'`

cat Python.md \
    <(grep -v "^# Intro" Assignment1-Python.md) \
    <(grep -v "^# Intro" Assignment2-Python.md) \
    <(grep -v "^# Intro\|^%" Assignment3-Python.md) \
     > $mOUTF \
&& pandoc -t latex --variable urlcolor=cyan $mOUTF -o $pOUTF

