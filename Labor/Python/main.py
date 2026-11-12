from person import Person
from customer import Customer
from excepts import *

def main() -> int:
    a_person = Customer()
    
    try:
        a_person.set_name("Michael")
        a_person.set_surname("Kohlhaas")
        a_person.set_dob(1, 1, 2000)
        a_person.set_address(
            "Bergiusstraße",
            105,
            28357,
            "Bremen",
            "Deutschland"
        )
    except DigitInName :
        print("There is a digit in the name")
        return 1
    
    print(a_person)
    return 0

if __name__ == "__main__":
    main()
