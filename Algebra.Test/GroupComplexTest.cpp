#include <boost/test/unit_test.hpp>
#include "include/DefaultNumberFactoryImpl.h"


BOOST_AUTO_TEST_SUITE(ComplexTestSuite)
	NumberFactory const &  numberFactory = DefaultNumberFactoryImpl();

BOOST_AUTO_TEST_CASE(testComplexConstuctAndEquals) {
	Complex::Ptr zero(numberFactory.createComplex());
	Complex::Ptr  one(numberFactory.createComplex(1,0));
	BOOST_REQUIRE(!(zero==one));
	Complex::Ptr  zero2(numberFactory.createComplex(0.0));
	BOOST_REQUIRE((zero==zero2));
	BOOST_REQUIRE_EQUAL(zero, zero2);
}

BOOST_AUTO_TEST_CASE(testComplexCopy) {
	Complex::Ptr a(numberFactory.createComplex(5.6));
	Complex::Ptr b(a);
	BOOST_REQUIRE(a==b);
}

BOOST_AUTO_TEST_CASE(testComplexAddAndSubtract) {
	Complex::Ptr a(numberFactory.createComplex(76,5)),
		b(numberFactory.createComplex(24,6)),
		sum(numberFactory.createComplex(100,11)),
		diff(numberFactory.createComplex(52,-1));
	Complex::Ptr aAddb = (a + b);
	BOOST_REQUIRE(aAddb==sum);
	Complex::Ptr aMinb((a) - (b));
	BOOST_REQUIRE(aMinb==diff);
}

BOOST_AUTO_TEST_CASE(testComplexMultiplyAndDivide) {
	Complex::Ptr zero = numberFactory.createComplex(),
		a(numberFactory.createComplex(5,2)),
		b(numberFactory.createComplex(1,-3)),
		prod(numberFactory.createComplex(11,-13));
	Complex::Ptr aMultb = a * b;
	BOOST_REQUIRE(aMultb==prod);
	Complex::Ptr quotient = prod / b;
	BOOST_REQUIRE(a==quotient);

	//Divide by zero
	BOOST_CHECK_THROW (a/zero, std::invalid_argument);
	//BOOST_MESSAGE("Exception caught while dividing by Complex zero.");
}

BOOST_AUTO_TEST_CASE(testRealAddAndSubtract) {
	Real::RealPtr a(numberFactory.createReal(76)),
		b(numberFactory.createReal(24)),
		sum = numberFactory.createReal(100),
		diff = numberFactory.createReal(52);
	Real::RealPtr aPlusB = (a + b);
	BOOST_REQUIRE(aPlusB==sum);
	Real::RealPtr aMinb = a - b;
	BOOST_REQUIRE(aMinb==diff);
}

BOOST_AUTO_TEST_CASE(testRealMultiplyAndDivide) {
	Real::RealPtr zero = numberFactory.createReal(),
		a = numberFactory.createReal(5),
		b = numberFactory.createReal(3),
		prod(numberFactory.createReal(15));
	Real::RealPtr aMultb = a * b;
	BOOST_REQUIRE(aMultb==prod);
	Real::RealPtr quotient = prod / b;
	BOOST_REQUIRE(a==quotient);

	//Divide by zero
	BOOST_CHECK_THROW (a/zero, std::invalid_argument);
	//BOOST_MESSAGE("Exception caught while dividing by Real zero.");
}


BOOST_AUTO_TEST_CASE(testMixRealAndComplexAddAndSubtract) {
	Complex::Ptr a(numberFactory.createComplex(2.50, 8.0));
	Real::RealPtr    b(numberFactory.createReal(0.5));
	Complex::Ptr sum(numberFactory.createComplex(3.0, 8)),
		diff(numberFactory.createComplex(2, 8));

	Complex::Ptr aAddb =  b + a;
	BOOST_REQUIRE_EQUAL(aAddb, sum);
	Complex::Ptr aMinb(a - b);
	BOOST_REQUIRE_EQUAL(aMinb, diff);
}

BOOST_AUTO_TEST_SUITE_END()
