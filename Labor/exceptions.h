#pragma once
using namespace std;

class digit_in_name : public invalid_argument {
public:
    using invalid_argument::invalid_argument;
};

class date_non_existent : public invalid_argument {
    public:
    using invalid_argument::invalid_argument;
};

class digit_in_word : public invalid_argument {
public:
    using invalid_argument::invalid_argument;
};

class postcode_length_error : public length_error {
    public:
    using length_error::length_error;
};

class letter_in_number : public invalid_argument {
    public:
    using invalid_argument::invalid_argument;
};
