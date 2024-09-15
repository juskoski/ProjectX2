#include <assert.h>
#include "../src/calculator.h"
#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>
#include <cstdint>
#include <cstddef>
#include <string>

FUZZ_TEST_SETUP() {
  // Perform any one-time setup required by the FUZZ_TEST function.
}

FUZZ_TEST(const uint8_t *data, size_t size) {
  FuzzedDataProvider fuzzed_data(data, size);
  float num1 = fuzzed_data.ConsumeIntegral<int8_t>();
  float num2 = fuzzed_data.ConsumeIntegral<int8_t>();

  float res = calculator(num1, '+', num2);
  assert(res == (num1+num2));

  res = calculator(num1, '-', num2);
  assert(res == (num1-num2));

  res = calculator(num1, '/', num2);
  assert(res == (num1/num2));

  res = calculator(num1, '*', num2);
  assert(res == (num1*num2));
}