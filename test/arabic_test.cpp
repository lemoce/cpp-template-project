#define BOOST_TEST_MODULE ArabicConverter
#include <boost/test/unit_test.hpp>
#include <string>

#include "arabic.h"


BOOST_AUTO_TEST_CASE( arabic_converter )
{
    BOOST_CHECK_EQUAL( arabic::convert(1),  std::string {"I"} );
}
