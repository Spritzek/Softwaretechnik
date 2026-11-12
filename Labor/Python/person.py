from defs import Dob
from excepts import *

class Person:
    def __init__(self) -> None:
        self.__name     : str
        self.__surName  : str
        self.__dob      : Dob
        
    def set_name(self, name: str) -> None:
        if any(elem in name for elem in "0123456789"):
            raise DigitInName("Digit in name")
        self.__name = name

    def name(self) -> str:
        return self.__name

    def set_surname(self, surname: str) -> None:
        if any(elem in surname for elem in "0123456789"):
            raise DigitInName("Digit in surname")
        self.__surName = surname
    
    def surname(self) -> str:
        return self.__surName
    
    def set_dob (self, day: int, month: int, year: int) -> None:
        self.__dob = Dob(day, month, year)
    
    def dob(self) -> Dob:
        if min(self.__dob.day, self.__dob.month, self.__dob.year) <= 0:
            raise Exception("invalid date")
        return self.__dob
    
    def _details(self) -> str:
        return(
            f"Name: {self.__name} {self.__surName} \n"
            f"DoB: {self.__dob} \n"
        )

    def __str__(self):
        return (
            f"-------------------------------------------------------\n"
            f"{self._details()} \n"
            f"-------------------------------------------------------"
        )