use num::bigint::BigInt;
use num::{Integer, One, Zero};

pub fn get_factor_sum(number: &BigInt) -> BigInt {
    let mut factor_sum: BigInt = BigInt::zero();
    let step: BigInt = if number.is_even() { BigInt::one() } else { BigInt::from(2) };
    let square_root: BigInt = number.sqrt();

    let mut quotient: BigInt = BigInt::one();
    while quotient <= square_root {
        if number.is_multiple_of(&quotient) {
            let factor: BigInt = number / &quotient;
            factor_sum += &quotient;
            if quotient != factor {
                factor_sum += factor;
            }
        }
        quotient += &step;
    }

    factor_sum - number
}