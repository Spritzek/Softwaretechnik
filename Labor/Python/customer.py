from person import Person
from defs import Address
from excepts import *

class Customer(Person):
    def __init__(self) -> None:
        super().__init__()
        self.__address : Address = Address()
    
    def address(self) -> Address:
        return self.__address
    
    def set_address(
            self,
            street: str,
            number: int,
            postcode: int,
            city: str,
            country: str
    ):
        if any(elem in street for elem in "0123456789"):
            raise DigitInName("Digit in surname")
        if len(str(postcode)) != 5:
            raise PostcodeLengthError("Postcode has to many/little digits")
        
        self.__address = Address(
            street,
            number,
            postcode,
            city,
            country
        )
        
    def _details(self) -> str:
        return (
            f"{super()._details()}"
            f"Address: {self.__address}"
        )
