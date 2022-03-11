#include <iostream>
#include <array>
#include <limits>
#include <cstdint>  // uint32_t
#include "UniformRandIntGen.hh"


namespace X13_12 {


// Stroustrup's original link of http://143.53.36.235:8080/tea.htm was not
//   available, instead basing the following off these sources:
//   - https://en.wikipedia.org/wiki/Tiny_Encryption_Algorithm
//   - https://link.springer.com/content/pdf/10.1007%2F3-540-60590-8_29.pdf
//   - http://derekwilliams.us/docs/CPSC-6128-TEA-Encryption.pdf

// Also, note that in actual application code TEA already has successors like
//   XTEA and XXTEA, see:
//   - https://cryptography.fandom.com/wiki/XTEA


constexpr uint32_t delta {0x9e3779b9};  // key schedule constant
constexpr uint32_t rounds {32};


void TEAEncode(std::array<uint32_t, 2> &data,
               const std::array<const std::array<const uint32_t, 2>, 2> &keys) {
    uint32_t d0 {data[0]};
    uint32_t d1 {data[1]};
    for (uint32_t sum {0}, i {0}; i < rounds; ++i) {
        sum += delta;
        d0 += ((d1 << 4) + keys[0][0]) ^ (d1 + sum) ^
            ((d1 >> 5) + keys[0][1]);
        d1 += ((d0 << 4) + keys[1][0]) ^ (d0 + sum) ^
            ((d0 >> 5) + keys[1][1]);
    }
    data[0] = d0;
    data[1] = d1;
}


void TEADecode(std::array<uint32_t, 2> &data,
               const std::array<const std::array<const uint32_t, 2>, 2> &keys) {
    uint32_t d0 {data[0]};
    uint32_t d1 {data[1]};
    // starting sum = (delta << 5) & 0xFFFFFFFF
    for (uint32_t sum {0xc6ef3720}, i {0}; i < rounds; ++i) {
        d1 -= ((d0 << 4) + keys[1][0]) ^ (d0 + sum) ^
                      ((d0 >> 5) + keys[1][1]);
        d0 -= ((d1 << 4) + keys[0][0]) ^ (d1 + sum) ^
                      ((d1 >> 5) + keys[0][1]);
        sum -= delta;
    }
    data[0] = d0;
    data[1] = d1;
}


}  // namespace X13_12


int main() {
    UniformRandIntGen<uint32_t> rng {0, std::numeric_limits<uint32_t>::max()};
    std::array<uint32_t, 2> data {rng(), rng()};
    const std::array<const std::array<const uint32_t, 2>, 2> keys {
        rng(), rng(), rng(), rng()};  // nested braces init causes error
    std::cout << "Encoding data points " << data[0] << " and " << data[1] <<
        " with key pairs (" << keys[0][0] << ", " << keys[0][1] <<
        ") and (" << keys[1][0] << ", " << keys[1][1] << ')' << std::endl;
    X13_12::TEAEncode(data, keys);
    std::cout << "Encoded data points " << data[0] << " and " << data[1] << std::endl;
    X13_12::TEADecode(data, keys);
    std::cout << "Decoded data points " << data[0] << " and " << data[1] << std::endl;
}
