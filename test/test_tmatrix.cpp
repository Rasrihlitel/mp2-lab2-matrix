#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);
  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = i;
		}
	}
	TDynamicMatrix<int> b(a);
	EXPECT_EQ(a, b);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = i;
		}
	}
	TDynamicMatrix<int> b(a);
	a[0][0] = 100;
	EXPECT_EQ(0, b[0][0]);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(4);
	EXPECT_EQ(4, m[0].size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> v(4);
	v[0][0] = 4;
	EXPECT_EQ(4, v[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> a(5);
	ASSERT_ANY_THROW(a[0].at(-5));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> a(5);
	ASSERT_ANY_THROW(a[0].at(100));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = i;
		}
	}
	ASSERT_NO_THROW(a = a);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			EXPECT_EQ(i, a[i][j]);
		}
	}
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = i;
		}
	}	
	TDynamicMatrix<int> b(5);
	b = a;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			EXPECT_EQ(i, b[i][j]);
		}
	}
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = i;
		}
	}
	TDynamicMatrix<int> b(3);
	b = a;
	EXPECT_EQ(5, b[0].size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = i;
		}
	}
	TDynamicMatrix<int> b(3);
	ASSERT_NO_THROW(b = a);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			EXPECT_EQ(i, b[i][j]);
		}
	}
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> b(5);
	TDynamicMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = i;
			b[i][j] = i;
		}
	}
	ASSERT_TRUE(b == a);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = i;
		}
	}
	ASSERT_TRUE(a == a);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = i;
		}
	}
	TDynamicMatrix<int> b(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			b[i][j] = i;
		}
	}
	ASSERT_FALSE(b == a);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> b(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			b[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> res = a + b;
	TDynamicMatrix<int> realRes(5);
	for (int i = 0; i < 5; i++) {
		realRes[i] = a[i] + b[i];
	}
	ASSERT_TRUE(res == realRes);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> b(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			b[i][j] = i + j;
		}
	}
	ASSERT_ANY_THROW(a + b);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> b(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			b[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> res = a - b;
	TDynamicMatrix<int> realRes(5);
	for (int i = 0; i < 5; i++) {
		realRes[i] = a[i] - b[i];
	}
	ASSERT_TRUE(res == realRes);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			a[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> b(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			b[i][j] = i + j;
		}
	}
	ASSERT_ANY_THROW(a - b);
}

