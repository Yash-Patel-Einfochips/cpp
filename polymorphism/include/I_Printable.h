#ifndef _I_PRINTABLE_
#define _I_PRINTABLE_

#include <iostream>

class I_Printable {
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
    virtual ~I_Printable() = default;
    virtual void print(std::ostream &os) const = 0;
};

#endif // _I_PRINTABLE_