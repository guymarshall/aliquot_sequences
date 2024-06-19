use std::fs::File;
use std::io::{BufReader, Read};
use csv::{Reader, ReaderBuilder};
use num::BigInt;

pub fn read_file_data(file: &File) -> (BigInt, BigInt, Vec<BigInt>) {
    let mut reader: BufReader<&File> = BufReader::new(file);
    let mut contents: String = String::new();
    reader.read_to_string(&mut contents).unwrap();

    let mut csv_reader: Reader<&[u8]> = ReaderBuilder::new().has_headers(false).from_reader(contents.as_bytes());

    let mut last_step: BigInt = BigInt::from(1);
    let mut last_sum_of_factors: BigInt = BigInt::from(0);
    let mut sums_of_factors: Vec<BigInt> = Vec::new();

    csv_reader.records().for_each(|result| {
        if let Ok(record) = result {
            if let Ok(sum_of_factors) = record.get(1).unwrap().parse::<BigInt>() {
                sums_of_factors.push(sum_of_factors.clone());
                last_step = record.get(0).unwrap().parse().unwrap_or_else(|_| BigInt::from(1));
                last_sum_of_factors = sum_of_factors;
            }
        }
    });
    
    sums_of_factors.pop();

    (last_step, last_sum_of_factors, sums_of_factors)
}
