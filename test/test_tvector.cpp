#include "tmatrix.h"

#include <gtest.h>
//Могу создать вектор положительной длины
TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}
//Не могу создать очень большой вектор
TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}
//Исключение, когда создаю вектор с отрицательной длиной
TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}
//Могу создать копию вектора
TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}
//Скопировать вектор от одного и проверить равенство два вектора
TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i + 1;
	}
	TDynamicVector<int> b(a);
	EXPECT_EQ(a, b);
}
//Скопированный вектор имеет свою память - проверить что два указателя указывают на разные места в памяти
TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	TDynamicVector<int> b(a);
	a[0] = 100;
	EXPECT_EQ(0, b[0]);
}
//
TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);
  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v[0] = 4;
  EXPECT_EQ(4, v[0]);
}
//Выброс исключения с отрицательным индексом
TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> a(5);
	ASSERT_ANY_THROW(a.at(-5));
}
//Выброс исключения с огромным индексом
TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> a(5);
	ASSERT_ANY_THROW(a.at(100));
}
//Присвоение вектора самому себе
TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	ASSERT_NO_THROW(a = a);
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(i, a[i]);
	}
}
//
TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	TDynamicVector<int> b(5);
	b = a;
	EXPECT_EQ(0, b[0]);
	EXPECT_EQ(1, b[1]);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	TDynamicVector<int> b(3);
	for (int i = 0; i < 3; i++) {
		b[i] = i;
	}
	b = a;
	EXPECT_EQ(5, b.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	TDynamicVector<int> b(3);
	for (int i = 0; i < 3; i++) {
		b[i] = i;
	}
	ASSERT_NO_THROW(b = a);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	TDynamicVector<int> b(5);
	for (int i = 0; i < 5; i++) {
		b[i] = i;
	}
	ASSERT_TRUE(a == b);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	ASSERT_TRUE(a == a);

}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	TDynamicVector<int> b(3);
	for (int i = 0; i < 3; i++) {
		b[i] = i;
	}
	ASSERT_FALSE(a == b);
}
//Могу прибавить скаляр к вектору
TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	int scal = 3;
	TDynamicVector<int> b = a + scal;
	EXPECT_EQ(3, b[0]);
	EXPECT_EQ(4, b[1]);
}
//Могу вычесть скаляр из вектора
TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	int scal = 3;
	TDynamicVector<int> b = a - scal;
	EXPECT_EQ(-3, b[0]);
	EXPECT_EQ(-2, b[1]);
}
//Могу скаляр умножжть на вектор
TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	int scal = 3;
	TDynamicVector<int> b = a * scal;
	EXPECT_EQ(0, b[0]);
	EXPECT_EQ(3, b[1]);
}
//Могу сложить векторы с одинаковым размером
TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	TDynamicVector<int> b(5);
	for (int i = 0; i < 5; i++) {
		b[i] = i;
	}
	TDynamicVector<int> res = a + b;
	EXPECT_EQ(0, res[0]);
	EXPECT_EQ(2, res[1]);
}
//Не могу сложить векторы с разным размером
TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	TDynamicVector<int> b(10);
	for (int i = 0; i < 10; i++) {
		b[i] = i;
	}
	ASSERT_ANY_THROW(a + b);
}
//Могу вычесть векторы с одинаковыми размерами
TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	TDynamicVector<int> b(5);
	for (int i = 0; i < 5; i++) {
		b[i] = i;
	}
	TDynamicVector<int> res = a - b;
	EXPECT_EQ(0, res[0]);
	EXPECT_EQ(0, res[1]);
}
//Не могу вычесть векторы с разным размером
TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	TDynamicVector<int> b(10);
	for (int i = 0; i < 10; i++) {
		b[i] = i;
	}
	ASSERT_ANY_THROW(a - b);
}
//Могу провести скалярное произведение с одинаковыми размерами
TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	TDynamicVector<int> b(5);
	for (int i = 0; i < 5; i++) {
		b[i] = i;
	}
	int res = a * b;
	EXPECT_EQ(30, res);
}
//Не могу провести скалярное произведение с разными размерами
TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	TDynamicVector<int> b(10);
	for (int i = 0; i < 10; i++) {
		b[i] = i;
	}
	ASSERT_ANY_THROW(a * b);
}