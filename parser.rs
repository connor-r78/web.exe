mod errcodes;

use std::convert::TryInto;
use std::ffi::CStr;
use std::fs::File;
use std::io::Read;
use std::os::raw::c_char;
use errcodes::{FILE_NOT_FOUND, SUCCESS};

const DATA_SIZE: u8 = 2;
const DATA_SIZE_NULL_TERM: u8 = DATA_SIZE + 1;
const STARTING_OFFSET: u8 = 0x0;

const PE_HEADER_LOC: u8 = 0x3C;

fn parse_import()
{

}

#[no_mangle]
pub extern "C" fn run(exe_path: *const c_char, wasm_path: *const c_char) -> i8
{
  let exe_path_rs = unsafe {
    match CStr::from_ptr(exe_path).to_str() {
      Ok(s) => s,
      Err(_) => return FILE_NOT_FOUND,
    }
  };

  let mut exe = File::open(exe_path_rs)
    .expect("Could not open .exe");
  let mut data = Vec::new();
  exe.read_to_end(&mut data);

  let wasm_path_rs = unsafe {
    match CStr::from_ptr(wasm_path).to_str() {
      Ok(s) => s,
      Err(_) => return FILE_NOT_FOUND,
    }
  };

  let mut wasm = File::open(wasm_path_rs)
    .expect("Could not open .wasm");
  let mut buffer = Vec::new();
  wasm.read_to_end(&mut buffer);

  let mut offset: u32 = STARTING_OFFSET.into();

  SUCCESS.try_into().unwrap()
}
