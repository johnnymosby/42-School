#include "Span.hpp"

Span::Span(u_int size): size_(0), maxSize_(size) {}

Span::Span(const Span &copy) {
	*this = copy;
}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		*this = other;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (size_ == maxSize_)
		throw noSpaceLeft();
	data_.push_back(num);
	size_++;
}

void Span::addVector(const std::vector <int> &vec) {
	if (size_ + vec.size() > maxSize_)
		throw noSpaceLeft();
	for (u_long i = 0; i < vec.size(); i++) {
		data_.push_back(vec[i]);
	}
	size_ += vec.size();
}

int Span::shortestSpan(void) {
	if (size_ < 2)
		throw noSpanFound();
	std::sort(data_.begin(), data_.end());
	int minDiff = data_[1] - data_[0];
	int diff;
	for (u_int i = 1; i < size_; i++) {
		diff = data_[i] - data_[i - 1];
		if (diff < minDiff)
			minDiff = diff;
	}
	return minDiff;
}

int Span::longestSpan(void) {
	if (size_ < 2)
		throw noSpanFound();
	std::sort(data_.begin(), data_.end());
	return data_[size_ - 1] - data_[0];
}

const char *Span::noSpaceLeft::what() const throw() {
	return "No space left in the span";
}
const char *Span::noSpaceForSecondVector::what() const throw() {
	return "No space for second vector";
}
const char *Span::noSpanFound::what() const throw() {
	return "No span found";
}