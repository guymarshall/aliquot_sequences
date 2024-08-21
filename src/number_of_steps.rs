use std::fs;
use std::fs::{File, OpenOptions};
use std::io::Write;
use std::path::Path;

use num::BigInt;

use crate::factors::get_factor_sum;
use crate::read_file::read_file_data;

pub fn get_number_of_steps(number: &BigInt) -> BigInt {
    let directory_name: &str = "results";
    let directory_path: &Path = Path::new(directory_name);
    if !directory_path.exists() {
        fs::create_dir_all(directory_path).expect("Failed to create directory");
    }

    let filename: String = format!("{directory_name}/{number}.csv");
    let mut file: File = OpenOptions::new()
        .read(true)
        .append(true)
        .create(true)
        .open(filename)
        .unwrap();

    let (mut step, mut sum_of_factors, mut sums): (BigInt, BigInt, Vec<BigInt>) =
        read_file_data(&file);

    if sum_of_factors == BigInt::from(1) {
        println!("Number {} has already been calculated.", number);
        return step;
    }

    if step == BigInt::from(1) {
        sum_of_factors = get_factor_sum(number);
        writeln!(&file, "{step},{sum_of_factors}").unwrap();
        file.flush().unwrap();
    }

    while sum_of_factors != BigInt::from(1) {
        if sums.iter().any(|sum: &BigInt| sum == &sum_of_factors) {
            println!("Loop found at step {} for number {}", step, number);
            break;
        }

        step += 1;
        sums.push(sum_of_factors.clone());
        sum_of_factors = get_factor_sum(&sum_of_factors);

        writeln!(&file, "{step},{sum_of_factors}").unwrap();
        file.flush().unwrap();

        println!("{}: {}", step, sum_of_factors);
    }

    step
}
