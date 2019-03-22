#!/bin/bash

for f in $2*.in; do
    $1 <$f >ans.out 2> ans.err
    diff ans.out ${f%in}out -q -w &> /dev/null
    if [ $? -eq 0 ]
    then
        diff ans.err ${f%in}err -q -w &> /dev/null
        if [ $? -eq 0 ]
        then
            echo "test $f OK"
        else
            echo "test $f ZŁA ODPOWIEDŹ"
        fi
    else
        echo "test $f ZŁA ODPOWIEDŹ"
    fi

    if [ $# -eq 3 ]; then
        valgrind --error-exitcode=15 --leak-check=full --show-leak-kinds=all\
         --errors-for-leak-kinds=all $1 <$f >ans.out
    fi
done
