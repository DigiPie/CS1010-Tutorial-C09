#!/bin/bash
PROG=$1
if [ ! -e $PROG ]
  then
    echo "$PROG does not exist.  Have you compiled it with make?"
    exit 1
  fi

NUM_OF_TEST_CASES=$2
num_failed=0
for i in $(seq 1 $NUM_OF_TEST_CASES)
do
  out=$(mktemp --suffix=$PROG)
  ./$PROG < inputs/$PROG.$i.in > $out
  if [ `diff -w $out outputs/$PROG.$i.out | wc -l` -ne 0 ] 
  then
    echo -n "$PROG: incorrect output for test case $i: "
    cat inputs/$PROG.$i.in
    num_failed=$((num_failed + 1))
  fi
  rm $out
done
if [ $num_failed -eq 0 ] 
then
  echo "$PROG: passed"
fi
