#include <gtest.h>
#include "../Objectonics/rational.h"
TEST(Rational, can_create_null_rational)
{
    ASSERT_NO_THROW(Rational r);
}
TEST(Rational, can_create_rational_with_param)
{
    ASSERT_NO_THROW(Rational r(-1));
    ASSERT_NO_THROW(Rational r(-2, 3));
}
TEST(Rational, cant_create_rational_with_zero_)
{
    ASSERT_ANY_THROW(Rational r(3, 0));
}
TEST(Rational, )
{

}
//TEST(Rational, )
//{
//
//}
//TEST(Rational, )
//{
//
//}
//TEST(Rational, )
//{
//
//}