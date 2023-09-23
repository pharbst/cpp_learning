/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:38:48 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/23 17:12:39 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class	Array {
	private:
		T*				_array;
		unsigned int	_length;
	public:
		Array() : _array(NULL), _length(0) {};
		Array(unsigned int n) : _array(new T[n]), _length(n) {};
		Array(Array const &ref) : _array(new T[ref._length]), _length(ref._length) {};
		Array&	operator=(Array const &ref) {
			if (this == &ref)
				return (*this);
			_array = new T[ref._length];
			_length = ref._length;
			for (unsigned int i = 0; i < _length; i++)
				_array[i] = ref._array[i];
			return (*this);
		};
		~Array() {
			if (_array)
				delete [] _array;
		};

		T&	operator[](unsigned int i) {
			if (i >= _length)
				throw Array::OutOfLimitsException();
			return _array[i];
		};
		unsigned int	size() const {
			return _length;
		};
		class	OutOfLimitsException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return "index out of bound\n";
				};
		};
};

#endif