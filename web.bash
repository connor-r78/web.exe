exe="tests/test.exe"
wasm="output.wasm"

gcc -Wall -Wextra -Werror -o web.bin main.c offsets.c parser.c
./web.bin -x $exe -o $wasm
