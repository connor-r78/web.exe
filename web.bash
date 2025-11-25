exe="tests/test.exe"
wasm="output.wasm"

rustc parser.rs --crate-type=staticlib --o parser.a
rustc offsets.rs --crate-type=staticlib --o offsets.a

gcc -g -Wall -Wextra -Werror -o web.bin main.c offsets.a parser.a
./web.bin -x $exe -o $wasm
