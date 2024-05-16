use num::{BigInt, Integer};
use num::bigint::ToBigInt;
use num_traits::One;
use num_traits::Zero;
use rayon::prelude::*;

fn sum_factors_range(number: &BigInt, start: &BigInt, end: &BigInt, step: &BigInt) -> BigInt {
    let mut range_sum: BigInt = BigInt::zero();

    let mut factor: BigInt = start.clone();
    while factor <= *end {
        if number.clone() % factor.clone() == BigInt::zero() {
            range_sum += &factor;
            range_sum += number / &factor;
        }
        factor += step;
    }

    range_sum
}

pub fn get_factor_sum(number: &BigInt) -> BigInt {
    let mut factor_sum: BigInt = BigInt::zero();
    let step: BigInt = if number.is_even() { BigInt::one() } else { 2.to_bigint().unwrap() };
    let square_root: BigInt = number.sqrt();
    let thread_count: usize = num_cpus::get();
    let range_size: BigInt = &square_root / thread_count.to_bigint().unwrap();

    let futures: Vec<BigInt> = (0..thread_count)
        .into_par_iter()
        .map(|future| {
            let start: BigInt = future * &range_size + BigInt::one();
            let end: BigInt = if future == thread_count - 1 {
                square_root.clone()
            } else {
                (future + 1) * &range_size
            };
            sum_factors_range(number, &start, &end, &step)
        })
        .collect();

    for future in futures {
        factor_sum += future;
    }

    factor_sum -= number;

    factor_sum
}
