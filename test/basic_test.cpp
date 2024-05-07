#include <gtest/gtest.h>
#include <mstring.h>

TEST(basic_test, construct_empty_mstring)
{
    // Construct a new empty mstring
    mstring m_str = mstr_construct();

    // Check for NULL pointer
    EXPECT_NE(m_str, nullptr);

    // Assert that the string initial size is 0
    ASSERT_EQ(mstr_get_size(m_str), 0);
    // Assert that the string's initial capacity is > 0
    ASSERT_GT(mstr_get_capacity(m_str), 0);

    // Delete string
    mstr_delete(m_str);
}

TEST(basic_test, construct_init_mstring)
{
    // Construct a new mstring with initialization
    mstring m_str = mstr_construct_init("Hello, World!");

    const char* expected_value = "Hello, World!";

    // Check for NULL pointer
    EXPECT_NE(m_str, nullptr);

    // Assert that the size is equal to the length of the string
    // used in the initialization
    EXPECT_EQ(mstr_get_size(m_str), strlen(expected_value));
    // Assert that the capacity is >= least mstr_get_size() + 1
    EXPECT_GE(mstr_get_capacity(m_str), mstr_get_size(m_str) + 1);

    // Check thath the content of the hidden mstring buffer is the
    // same as the constant expected value.
    EXPECT_STREQ(mstr_get(m_str), expected_value);

    // Delete string
    mstr_delete(m_str);
}