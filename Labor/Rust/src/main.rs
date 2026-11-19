
#[derive(Clone, Default)]
pub struct Date {
    day: u8,
    month: u8,
    year: u16,
}
impl Date {
    pub fn is_empty(&self) -> bool {
        if self.day == 0 || self.month == 0 || self.year == 0 {
            return true
        }
        false
    }
}

#[derive(Clone, Default)]
pub struct Address{
    street: String,
    number: u16,
    postcode: u16,
    city: String,
    country: String,
}
impl Address {
    pub fn is_empty(&self) -> bool {
        if self.street.is_empty() || self.number == 0 || self.postcode == 0 || self.city.is_empty() || self.country.is_empty() {
            return true
        }
        false
    }
}

#[derive(Default)]
pub struct Customer {
    name: String,
    surname: String,
    dob: Date,
    address: Address,
}
impl Customer {
    pub fn set_name(&mut self, name: String) -> Result<(), &'static str> {
        if name.is_empty() {
            return Err("Name must not be empty");
        }
        Ok(self.name = name)
    }
    pub fn get_name(&self) -> String { self.name.clone() }
    pub fn set_surname(&mut self, surname: String) -> Result<(), &'static str> {
        if surname.is_empty() {
            return Err("Surname must not be empty")
        }
        Ok(self.surname = surname)
    }
    pub fn get_surname(&self) -> String { self.surname.clone() }
    pub fn set_dob(&mut self, date: Date) -> Result<(), &'static str> {
        if date.is_empty() {
            return Err("Date must not be empty")
        }
        Ok(self.dob = date)
    }
    pub fn get_dob(&self) -> Date { self.dob.clone() }
    pub fn set_address(&mut self, address: Address) -> Result<(), &'static str> {
        if address.is_empty() {
            return Err("Address must not be empty")
        }
        Ok(self.address = address)
    }
    pub fn get_address(&self) -> Address { self.address.clone() }
}
impl Customer {
    pub fn new() -> Self {
        Self::default()
    }
}

fn main() -> Result<(), String> {
    let mut a_person = Customer::default();
    a_person.set_name("John Smith".to_string())?;
    a_person.set_surname("Smith".to_string())?;
    a_person.set_dob(Date{day: 22, month: 12, year: 2000})?;
    a_person.set_address(Address {
        street: "Bergiusstraße".to_string(),
        number: 105,
        postcode: 28357,
        city: "Bremen".to_string(),
        country: "Deutschland".to_string(),
    })?;

    let mut b_person = Customer{
        name: String::from("Max"),
        surname: String:: from("Mustermann"),
        dob: Date { day: 0, month: 0, year: 0 },
        address: Address {
            street:     "Bergiusstraße" .to_string(),
            number:     105,
            postcode:   28357,
            city:       "Bremen"        .to_string(),
            country:    "Deutschland"   .to_string(),
        },
    };

    let message: String = a_person.get_surname();

    println!("{}", message);

    if true {
        Ok(())
    } else {
        Err("Surname not set".to_string())
    }

}
