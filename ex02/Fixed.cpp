/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:50:24 by rhiguita          #+#    #+#             */
/*   Updated: 2026/02/05 20:02:28 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _fixedPointValue(roundf(value * (1 << _fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy iassignent operator called" << std::endl;
    if (this != &other)
        _fixedPointValue = other._fixedPointValue;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const {
    return _fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return _fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
    return _fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    return _fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
    return _fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    return _fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(_fixedPointValue + other._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    long tmp = static_cast<long>(this->_fixedPointValue) * static_cast<long>(other.getRawBits());
    result.setRawBits(static_cast<int>(tmp >> _fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    result.setRawBits((_fixedPointValue << _fractionalBits) / other._fixedPointValue);
    return result;
}

Fixed& Fixed::operator++(void) {
    _fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _fixedPointValue++;
    return temp;
}

Fixed& Fixed::operator--(void) {
    _fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _fixedPointValue--;
    return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b; 
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b; 
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
