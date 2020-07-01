#!/bin/sh
# use clang tools to tidy and reformat code

tidy=clang-tidy90
format=clang-format90

if [ -f build/compile_commands.json ]
then
  printf '===> tidying\n'
  ${tidy} src/*.cpp -fix -checks="readability-braces-around-statements" -p build
else
  d=''
  [ -d build ] || d='mkdir -p build && '
  printf 'suggest running: (%scd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..)\n' "${d}"
  printf 'and re-running this script to run the tidy operation\n'
fi

printf '===> reformatting\n'
find src include '(' -name '*.h' -or -name '*.cpp' ')' -exec ${format} -i '{}' ';'
