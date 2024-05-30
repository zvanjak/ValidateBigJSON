#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

namespace ns
{
// a simple struct to model a person
struct person
{
    std::wstring name;
    std::string address;
    int age;
};
} // namespace ns

void test2()
{
	// create a JSON object
    json j =
    {
        {"pi", 3.141},
        {"happy", true},
        {"name", "Niels"},
        {"nothing", nullptr},
        {
            "answer", {
                {"everything", 42}
            }
        },
        {"list", {1, 0, 2}},
        {
            "object", {
                {"currency", "USD"},
                {"value", 42.99}
//            	,                {L"Menú Inicio", 42.99}
            }
        }
    };

    // add new values
    j["new"]["key"]["value"] = {"another", "list"};

    // count elements
    auto s = j.size();
    j["size"] = s;

    // pretty print with indent of 4 spaces
    std::cout << std::setw(4) << j << '\n';
}
namespace ns
{
void to_json(json& j, const person& p)
{
    j = json{ {"name", p.name}, {"address", p.address}, {"age", p.age} };
}
} // namespace ns

int main()
{
    ns::person p = {L"Menú Inicio", "744 Evergreen Terrace", 60};

    json j = p;

    std::cout << j << std::endl;

    test2();
}