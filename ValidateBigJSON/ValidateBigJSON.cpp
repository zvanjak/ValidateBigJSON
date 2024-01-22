// ValidateBigJSON.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "simdjson.h"

using namespace simdjson;

int main(void) {
  ondemand::parser parser;
  padded_string json = padded_string::load("ScanSystem_Registry_bad.json");
  ondemand::document tweets = parser.iterate(json);
  //std::cout << uint64_t(tweets["search_metadata"]["count"]) << " results." << std::endl;
}