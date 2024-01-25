// ValidateBigJSON.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "simdjson.h"

using namespace simdjson;

class JSONValidator {
public:
  static bool isValidJSON(std::string inFileName) {
    ondemand::parser parser;

    padded_string json = padded_string::load(inFileName);
    ondemand::document parsed_doc;
    try {
      parsed_doc = parser.iterate(json);

      //ondemand::document doc;
      //auto error = parser.iterate(json).get(doc);
    }
    catch (simdjson_error& error) {
      auto wht = error.what();
      auto location = parsed_doc.current_location();

      return false;
    }
    return true;
  }
};

int main(void) {
  ondemand::parser parser;
  padded_string json = padded_string::load("C:\\Projects\\ValidateBigJSONOld\\ValidateBigJSON\\ScanSystem_Registry_Valid_2.json");

  ondemand::document tweets = parser.iterate(json);

  std::cout << "DONE!!!";
}