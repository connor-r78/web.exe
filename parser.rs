use std::convert::TryInto;
use std::fs::File;
use std::io::prelude::*;
use std::path::Path;

mod errcodes;
use errcodes::{FILE_NOT_FOUND, SUCCESS};

const DATA_SIZE: u8 = 2;
const DATA_SIZE_NULL_TERM: u8 = DATA_SIZE + 1;
const STARTING_OFFSET: u8 = 0x0;

const PE_HEADER_LOC: u8 = 0x3C;

fn parseImport()
{

}

#[no_mangle]
pub extern "C" fn run(exePath: &str, wasmPath: &str) -> u8
{
  let mut path = Path::new(exePath);
  let mut display = path.display();

  let mut exe = match File::open(&path) {
    Err(why) => panic!("Could not open {}: {}", display, why),
    Ok(exe) => exe,
  };

  path = Path::new(wasmPath);
  display = path.display();

  let mut wasm = match File::create(&path) {
    Err(why) => panic!("Could not open {}: {}", display, why),
    Ok(wasm) => wasm,
  };

  let mut data = String::new();
  match exe.read_to_string(&mut data) {
    Err(why) => panic!("Could not read {}: {}", display, why),
    Ok(_) => print!("{} contains:\n{}", display, data),
  }

  let mut offset: u32 = STARTING_OFFSET.into();

  while offset <= data.len().try_into().unwrap() {
    
  }

  SUCCESS
}
