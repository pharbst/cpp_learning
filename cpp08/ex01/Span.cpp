/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:17:48 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/24 17:10:31 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int size) : _size(size) {}

Span::Span(const Span& ref) : _size(ref._size) {}

Span&	Span::operator=(const Span& ref) {
	if (this == &ref)
		return *this;
	_size = ref._size;
	return *this;
}

Span::~Span() {}

int		Span::operator[](unsigned int index) {
	return _span[index];
}

unsigned int	Span::size() const {
	return _size;
}

void	Span::addNumber(int add) {
	if (_span.size() < _size)
		_span.push_back(add);
	else
		throw FullSpanException();
}

int		Span::shortestSpan() {
	if (_span.size() < 2)
		throw NotEnoughNumbersException();
	std::vector<int>	sortedSpan = _span;
	std::sort(sortedSpan.begin(), sortedSpan.end());
	int	minSpan = sortedSpan[1] - sortedSpan[0];
	for (unsigned int i = 2; i < sortedSpan.size(); i++) {
		int	span = sortedSpan[i] - sortedSpan[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int		Span::longestSpan() {
	if (_span.size() < 2)
		throw NotEnoughNumbersException();
	std::vector<int>	sortedSpan = _span;
	std::sort(sortedSpan.begin(), sortedSpan.end());
	return sortedSpan.back() - sortedSpan.front();
}

const char*	Span::FullSpanException::what() const throw() {
	return "Span is already full";
}

const char*	Span::NotEnoughNumbersException::what() const throw() {
	return "Not enough numbers to calculate span";
}
