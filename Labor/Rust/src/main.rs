
struct Date {
    day: u8,
    month: u8,
    year: u16,
}
struct Customer {
    name: String,
    surname: String,
    dob: Date,
}
impl Customer {
    pub fn setName(&mut self, name: String) {
        self.name = name
    }
}

fn main() {
    println!("Hello, world!");
}
