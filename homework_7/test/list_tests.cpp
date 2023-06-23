#include <list>
#include <gtest/gtest.h>

TEST(list, size_of_empty_list) {
	// Arrange
	std::list<int> l;
	const size_t expectedSize = 0;

	// Act

	// Assert
	ASSERT_EQ(l.size(), expectedSize);
}

TEST(list, size_of_not_empty_list) {
	// Arrange
	std::list<int> l;
	const size_t expectedSize = 10;

	// Act
	for (size_t i = 0; i < expectedSize; i++) {
		l.push_back(i);
	}

	// Assert
	ASSERT_EQ(l.size(), expectedSize);
}

TEST(list, back) {
	// Arrange
	const int expectedValue = 4;
	std::list<int> l = {0, 1, 2, 3, expectedValue};

	// Act

	// Assert
	ASSERT_EQ(l.back(), expectedValue);
}

TEST(list, front) {
	// Arrange
	const int expectedValue = 0;
	std::list<int> l = {expectedValue, 1, 2, 3, 4};

	// Act

	// Assert
	ASSERT_EQ(l.front(), expectedValue);
}

TEST(list, push_back) {
	// Arrange
	std::list<int> l = {0, 1, 2, 3, 4};
	const int expectedValue = 10;

	// Act
	l.push_back(expectedValue);

	// Assert
	ASSERT_EQ(l.back(), expectedValue);
}

TEST(list, push_front) {
	// Arrange
	std::list<int> l = {0, 1, 2, 3, 4};
	const int expectedValue = 10;

	// Act
	l.push_front(expectedValue);

	// Assert
	ASSERT_EQ(l.front(), expectedValue);
}

TEST(list, insert) {
	// Arrange
	std::list<int> l = {0, 1, 2, 3, 4};
	const int index = 3;
	const int expectedValue = 10;

	// Act
	l.insert(std::next(l.begin(), index), expectedValue);

	// Assert
	ASSERT_EQ(*std::next(l.begin(), index), expectedValue);
}

TEST(list, pop_back) {
	// Arrange
	const int elementToRemove = 4;
	std::list<int> l = {0, 1, 2, 3, elementToRemove};

	// Act
	l.pop_back();

	// Assert
	ASSERT_NE(l.back(), elementToRemove);
}

TEST(list, pop_front) {
	// Arrange
	const int elementToRemove = 0;
	std::list<int> l = {elementToRemove, 1, 2, 3, 4};

	// Act
	l.pop_front();

	// Assert
	ASSERT_NE(l.front(), elementToRemove);
}

TEST(list, erase) {
	// Arrange
	const int elementToRemove = 2;
	const int index = 2;
	std::list<int> l = {0, 1, elementToRemove, 3, 4};

	// Act
	l.erase(std::next(l.begin(), index));

	// Assert
	ASSERT_NE(*std::next(l.begin(), index), elementToRemove);
}

TEST(list, resize_greater) {
	// Arrange
	std::list<int> l = {0, 1, 2, 3, 4};
	const size_t newSize = 10;

	// Act
	l.resize(newSize);

	// Assert
	ASSERT_EQ(l.size(), newSize);
}

TEST(list, resize_less) {
	// Arrange
	std::list<int> l = {0, 1, 2, 3, 4};
	const size_t newSize = 10;

	// Act
	l.resize(newSize);

	// Assert
	ASSERT_EQ(l.size(), newSize);
}

TEST(list, clear) {
	// Arrange
	std::list<int> l = {0, 1, 2, 3, 4};	

	// Act
	l.clear();

	// Assert
	ASSERT_TRUE(l.empty());
}