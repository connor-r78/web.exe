exe="tests/test.exe"
wasm="output.wasm"

rustc parser.rs --crate-type=staticlib --o parser.a

gcc -Wall -Wextra -Werror -o web.bin main.c offsets.c parser.a
./web.bin -x $exe -o $wasm
