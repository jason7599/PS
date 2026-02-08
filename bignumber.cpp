#include <iostream>
#include <vector>

class BigInt {
private:
    bool m_neg;
    std::string m_str;

public:
    BigInt() : m_neg(false), m_str("0") {}
    BigInt(std::string s) {
        auto invalid = [&] { 
            throw std::invalid_argument("Invalid BigInt string: \"" + s + '\"'); 
        };

        if (s.empty() || s == "-") invalid();

        m_neg = s.front() == '-';

        size_t t = s.find_first_not_of('0', m_neg);
        if (t == std::string::npos) {
            m_neg = false;
            m_str = "0";
            return;
        }

        for (size_t i = t; i < s.length(); ++i) {
            if (!isdigit(static_cast<u_char>(s[i]))) {
                invalid();
            }
        }

        m_str = (m_neg ? "-" : "") + s.substr(t);
    }

    friend std::istream& operator>>(std::istream& is, BigInt& n) {
        std::string s;
        if (!(is >> s)) return is; // propagate EOF/fail

        try {
            BigInt tmp(std::move(s));
            n = std::move(tmp);
        } catch (const std::invalid_argument& e) {
            is.setstate(std::ios::failbit);
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const BigInt& n) {
        os << n.m_str;
        return os;
    }
};

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

}