
class Dob:
    def __init__(
            self,
            day    : int = 0,
            month  : int = 0,
            year   : int = 0
    ):
        self.day   : int = day
        self.month : int = month
        self.year  : int = year

    def __format__(self, format_spec: str):
        return f"{self.day}.{self.month}.{self.year}"


class Address:
    def __init__(
            self,
            street    : str = "",
            number    : int = 0,
            postcode  : int = 0,
            city      : str = "",
            country   : str = ""
    ):
        self.street   : str = street
        self.number   : int = number
        self.postcode : int = postcode
        self.city     : str = city
        self.country  : str = country

    def __format__(self, format_spec: str):
        return (
            f"{self.street} {self.number}, {self.postcode} {self.city}, {self.country}"
        )