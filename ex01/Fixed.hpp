/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:19:16 by rhiguita          #+#    #+#             */
/*   Updated: 2026/02/01 19:35:10 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <iomanip>
# include <cmath>

class Fixed {
    private:
        int     _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed &other);
        ~Fixed();
        
        float   toFloat(void) const;
        int     toInt(void) const;

        int getRawBits(void) const;
        void    setRawBits(int const raw);    
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
