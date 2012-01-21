#!/bin/bash -x

#
#    Copyright 2011, 2012 Phil Colbourn
#
#    This file is part of simplispic.
#
#
#    simplispic is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    simplispic is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with simplispic.  If not, see <http://www.gnu.org/licenses/>.
#

# make interpreter
#gcc pc-lisp-integer.c
PROJ="pc-lisp-main.c pc-lisp-print.c pc-lisp-read2.c \
  pc-lisp-mem.c pc-lisp-gc.c pc-lisp-pair.c pc-lisp-misc.c \
 pc-lisp-adt.c  pc-lisp-eval-adt.c  pc-lisp-test.c  pc-lisp-primitives.c \
 "
clang -ggdb -Wno-comment -O0 $PROJ
if [ "$?" != "0" ]; then exit 1; fi
cp a.out a.clang.out
#exit 1

gcc -ggdb -fmax-errors=10 -O0 $PROJ
if [ "$?" != "0" ]; then exit 1; fi
cp a.out a.gcc.out
#exit 1


# test it

cat <<END > test.pcl
; CAUTION: most test cases should go after load to ensure environment is booted

(load "pc-scheme.lib")

;(cond ((eq? 1 1) "test" "1==1") (else "1!=0"))
;(if (eq? 1 0) "1==0" "1!=0")
;(car (cons '() '()))

(load "pc-r4rstest.sim")
               
END

if [ "$?" == "0" ]; then 
  echo "PASS: Input file created."
else 
  echo "FAIL: Input file corrupt.."
  exit 1
fi



cat <<END > expect.out
"loaded file"
END
 
#time cat test.pcl | valgrind --leak-check=full --show-reachable=yes -v ./a.out > result.out

#time cat test.pcl | ./a.clang.out     > result.clang.out
#time cat test.pcl | ./a.cpp.clang.out > result.cpp.clang.out
time cat test.pcl | ./a.gcc.out       > result.gcc.out

#try ./pc-r4rstest.bash 2>&1 | less

echo "Compare expected to actual result from gcc..."
diff -abEB -y expect.out result.gcc.out
if [ "$?" == "0" ]; then 
  echo "PASS: Results match expected."
else 
  echo "FAIL: Results don't match expected."
fi

exit 1

echo "Compare gcc v clang results..."
diff -abEB -y --suppress-common-lines result.gcc.out result.clang.out
if [ "$?" == "0" ]; then 
  echo "PASS: gcc and clang results match."
else 
  echo "FAIL: gcc and clang results don't match."
fi

echo "Compare cpp/clang v clang results..."
diff -abEB -y --suppress-common-lines result.cpp.clang.out result.clang.out
if [ "$?" == "0" ]; then 
  echo "PASS: cpp/clang and clang results match."
else 
  echo "FAIL: cpp/clang and clang results don't match."
fi

