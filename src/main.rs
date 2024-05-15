mod number_of_steps;
mod factors;
mod read_file;

extern crate num;
use num::BigInt;
use crate::number_of_steps::get_number_of_steps;

fn main() {
    // let user_input: BigInt = BigInt::from(138);
    let user_input: BigInt = BigInt::from(276);

    let number_of_steps: BigInt = get_number_of_steps(&user_input);
    println!("Number of steps for {user_input}: {number_of_steps}");
}