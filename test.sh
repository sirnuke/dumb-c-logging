#/bin/sh
cd tests

perform_test()
{
  echo "Running test ${1}..."
  echo "===================="
  cp ../logging.h $1
  if [ -e "$1/setup.sh" ] ; then
    cd $1
    ./setup.sh
    cd ..
  fi
  $CC -o $1/bin $1/test.c -I $1 -Wall -Wextra -Wno-unused-function
  if [ "$?" -ne "0" ] ; then
    echo "Unable to compile $1!\n"
    return
  fi
  ./$1/bin 2> $1/test.out
  if [ "$?" -ne "0" ] ; then
    echo "Unable to run $1!\n"
    return
  fi
  diff $1/test.out $1/correct.out
  if [ "$?" -ne "0" ] ; then
    echo "Output of $1 differs!\n"
    return
  fi
  echo "Success!\n"
}

for dir in `ls`; do 
  perform_test $dir
done
