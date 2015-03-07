#ifndef __EXCEPTIONS_H_
#define __EXCEPTIONS_H_

#include <exception>

using namespace std;

namespace arabic {

    class NotImplementedException : public exception
    {
	virtual const char * what () const throw () {
	    return "Not implemented method";
	}
    };

} // namespace arabic

#endif /* __EXCEPTIONS_H_ */
