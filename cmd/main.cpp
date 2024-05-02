// By Thom Troy
// see https://github.com/ttroy50/cmake-examples/tree/master/05-unit-testing/google-test-download
// https://github.com/ttroy50/cmake-examples/blob/master/LICENSE

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>

int main(int argc, char *argv[])
{
    std::cout << "Hello Third Party Include!" << std::endl;

    // use a shared ptr
    boost::shared_ptr<int> isp(new int(4));

    // trivial use of boost filesystem
    boost::filesystem::path path = "/usr/share/cmake/modules";
    if(path.is_relative())
    {
        std::cout << "Path is relative" << std::endl;
    }
    else
    {
        std::cout << "Path is not relative" << std::endl;
    }

   return 0;
}
