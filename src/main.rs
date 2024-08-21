mod factors;
mod number_of_steps;
mod read_file;

extern crate num;

use crate::number_of_steps::get_number_of_steps;
use num::BigInt;

fn main() {
    // let user_input: BigInt = BigInt::from(138);
    // let user_input: BigInt = BigInt::from(276);
    // let user_input: BigInt = BigInt::from(552);
    // let user_input: BigInt = BigInt::from(564);
    // let user_input: BigInt = BigInt::from(660);
    let user_input: BigInt = BigInt::from(966);

    let number_of_steps: BigInt = get_number_of_steps(&user_input);
    println!("Number of steps for {user_input}: {number_of_steps}");
}
