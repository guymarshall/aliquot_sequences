use std::collections::HashSet;

use num::BigInt;
use num::FromPrimitive;
use num_traits::One;
use num_traits::Zero;
use rayon::prelude::*;

fn generate_permutations(
    numbers: &[BigInt],
    start: usize,
    path: &mut Vec<BigInt>,
    result: &mut HashSet<Vec<BigInt>>,
) {
    if start == numbers.len() {
        return;
    }

    for i in start..numbers.len() {
        path.push(numbers[i].clone());
        result.insert(path.clone());

        generate_permutations(numbers, i + 1, path, result);

        path.pop();
    }
}

fn get_prime_factors(mut number: BigInt) -> Vec<BigInt> {
    let mut factors: Vec<BigInt> = vec![];

    let two: BigInt = BigInt::from_u32(2).unwrap();
    let mut factor: BigInt = BigInt::from_u32(3).unwrap();

    while &number % &two == BigInt::zero() {
        factors.push(two.clone());
        number /= &two;
    }

    let mut limit: BigInt = number.sqrt();
    while factor <= limit {
        while &number % &factor == BigInt::zero() {
            factors.push(factor.clone());
            number /= &factor;
        }
        factor += &two;
        limit = number.sqrt();
    }

    if number > BigInt::one() {
        factors.push(number);
    }

    factors
}

pub fn get_factor_sum(number: &BigInt) -> BigInt {
    let numbers: Vec<BigInt> = get_prime_factors(number.clone());
    let mut permutations: HashSet<Vec<BigInt>> = HashSet::new();
    let mut path: Vec<BigInt> = Vec::new();

    generate_permutations(&numbers, 0, &mut path, &mut permutations);

    let factor_sum: BigInt = permutations
        .par_iter()
        .map(|permutation: &Vec<BigInt>| {
            permutation
                .iter()
                .fold(BigInt::one(), |accumulator: BigInt, element: &BigInt| {
                    accumulator * element
                })
        })
        .filter(|product: &BigInt| product != number)
        .reduce(BigInt::zero, |accumulator: BigInt, product: BigInt| {
            accumulator + product
        });

    factor_sum + 1
}
