#include <vector>
#include <gtest/gtest.h>

TEST(vector, size_of_empty_vector) {
	// Arrange
	std::vector<int> v;
	const size_t expectedSize = 0;

	// Act

	// Assert
	ASSERT_EQ(v.size(), expectedSize);
}

TEST(vector, size_of_not_empty_vector) {
	// Arrange
	std::vector<int> v = {0, 1, 2, 3, 4};
	size_t expectedSize = 5;

	// Act

	// Assert
	ASSERT_EQ(v.size(), expectedSize);
}

TEST(vector, back) {
	// Arrange
	const int expectedValue = 4;
	std::vector<int> v = {0, 1, 2, 3, expectedValue};

	// Act

	// Assert
	ASSERT_EQ(v.back(), expectedValue);
}

TEST(vector, front) {
	// Arrange
	const int expectedValue = 0;
	std::vector<int> v = {expectedValue, 1, 2, 3, 4};

	// Act

	// Assert
	ASSERT_EQ(v.front(), expectedValue);
}


TEST(vector, index) {
	// Arrange
	const int index = 2;
	const int expectedValue = 2;
	std::vector<int> v = {0, 1, expectedValue, 3, 4};

	// Act

	// Assert
	ASSERT_EQ(v[index], expectedValue);
}

TEST(vector, at) {
	// Arrange
	const int index = 2;
	const int expectedValue = 2;
	std::vector<int> v = {0, 1, expectedValue, 3, 4};

	// Act

	// Assert
	ASSERT_EQ(v.at(index), expectedValue);
}

TEST(vector, at_out_of_range) {
	// Arrange
	std::vector<int> v = {0, 1, 2, 3, 4};
	const size_t outOfRangeIndex = 10;

	// Act

	// Assert
	ASSERT_THROW(v.at(outOfRangeIndex), std::out_of_range);
}

TEST(vector, push_back) {
	// Arrange
	std::vector<int> v = {0, 1, 2, 3, 4};
	const int expectedValue = 10;

	// Act
	v.push_back(expectedValue);

	// Assert
	ASSERT_EQ(v.back(), expectedValue);
}

TEST(vector, insert_at_begin) {
	// Arrange
	std::vector<int> v = {0, 1, 2, 3, 4};
	const int expectedValue = 10;

	// Act
	v.insert(v.begin(), expectedValue);

	// Assert
	ASSERT_EQ(v.front(), expectedValue);
}

TEST(vector, insert_into_middle) {
	// Arrange
	std::vector<int> v = {0, 1, 2, 3, 4};
	const int expectedValue = 10;
	const int index = 3;

	// Act
	v.insert(std::next(v.begin(), index), expectedValue);

	// Assert
	ASSERT_EQ(v[index], expectedValue);

}

TEST(vector, pop_back) {
	// Arrange
	const int elementToRemove = 4;
	std::vector<int> v = {0, 1, 2, 3, elementToRemove};

	// Act
	v.pop_back();

	// Assert
	ASSERT_NE(v.back(), elementToRemove);
}

TEST(vector, erase_at_begin) {
	// Arrange
	const int elementToRemove = 0;
	std::vector<int> v = {elementToRemove, 1, 2, 3, 4};

	// Act
	v.erase(v.begin());

	// Assert
	ASSERT_NE(v.front(), elementToRemove);

}

TEST(vector, erase_in_middle) {
	// Arrange
	const int elementToRemove = 2;
	const int index = 2;
	std::vector<int> v = {0, 1, elementToRemove, 3, 4};

	// Act
	v.erase(std::next(v.begin(), index));

	// Assert
	ASSERT_NE(v[index], elementToRemove);
}

TEST(vector, resize_greater) {
	// Arrange
	std::vector<int> v = {0, 1, 2, 3, 4};
	const size_t newSize = 10;

	// Act
	v.resize(newSize);

	// Assert
	ASSERT_EQ(v.size(), newSize);
}

TEST(vector, resize_less) {
	// Arrange
	std::vector<int> v = {0, 1, 2, 3, 4};
	const size_t newSize = 10;

	// Act
	v.resize(newSize);

	// Assert
	ASSERT_EQ(v.size(), newSize);
}

TEST(vector, clear) {
	// Arrange
	std::vector<int> v = {0, 1, 2, 3, 4};	

	// Act
	v.clear();

	// Assert
	ASSERT_TRUE(v.empty());
}