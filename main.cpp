#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Employee {
public:
    std::string name;
    std::string position;
    double salary;

    Employee(std::string n, std::string p, double s) : name(n), position(p), salary(s) {}
};

int main() {
    std::vector<Employee> employees = {
        Employee("Alice", "Manager", 5000),
        Employee("Bob", "Developer", 4000),
        Employee("Charlie", "Designer", 3500),
        Employee("David", "Developer", 4200)
    };

    std::vector<std::string> employeeStrings;

    std::transform(employees.begin(), employees.end(), std::back_inserter(employeeStrings), [](const Employee& emp) {
        return emp.name + " - " + emp.position;
    });

    for (const auto& empStr : employeeStrings) {
        std::cout << empStr << std::endl;
    }

    return 0;
}
