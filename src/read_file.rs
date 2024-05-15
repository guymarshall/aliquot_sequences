use std::fs::File;
use std::io::{BufReader, Read};
use csv::{Reader, ReaderBuilder};
use num::BigInt;

pub fn read_file_data(file: &File) -> (BigInt, BigInt) {
    let mut reader: BufReader<&File> = BufReader::new(file);
    let mut contents: String = String::new();
    reader.read_to_string(&mut contents).unwrap();

    let mut csv_reader: Reader<&[u8]> = ReaderBuilder::new().has_headers(false).from_reader(contents.as_bytes());

    if let Some(Ok(record)) = csv_reader.records().next() {
        let step: BigInt = record.get(0).unwrap().parse().unwrap_or_else(|_| BigInt::from(1));
        let sum_of_factors: BigInt = record.get(1).unwrap().parse().unwrap_or_else(|_| BigInt::from(0));
        return (step, sum_of_factors);
    }

    (BigInt::from(1), BigInt::from(0))
}