const HEX_BASE: u8 = 16;

fn move_offset(offset: &mut u32, dest: u32)
{
  println!("{}", dest);
  *offset += dest - *offset;
}

fn get_PE_header(input_a: &str, input_b: &str) -> u32 
{
  let a: u8 = input_a.parse().expect("Failed to parse input.");
  let b: u8 = input_b.parse().expect("Failed to parse input.");

  return (b * HEX_BASE ^ 2 + a).into();
}
