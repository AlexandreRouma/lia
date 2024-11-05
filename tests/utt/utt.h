#pragma once

// Stupid MSVC warnings for sprintf...
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 1
#endif

#include <string>
#include <functional>
#include <map>
#include <vector>
#include <stdexcept>

int main();

namespace utt {
    class Test {
    public:
        // Default constructor
        Test() {}

        /**
         * Create a unit test.
         * @param file File of the unit test.
         * @param line Line number of the unit test.
         * @param desc Description of the unit test.
         * @param test Test function. Can either return false or throw an exception. Can also be void in which case only exceptions will count as a fail.
        */
        Test(const std::string& file, int line, const std::string& desc, std::function<void()> test) {
            // Save settings
            this->desc = desc;
            this->test = test;

            // Compute the ID of the test
            char ln[16];
            sprintf(ln, "%010d", line);
            std::string id = file + ":" + ln;

            // Copy self to list
            tests[id] = *this;
        }

        // Make sure the main function has access to internal values
        friend int ::main();

    private:
        std::string desc;
        std::function<void()> test;
        static std::map<std::string, Test> tests;
    };

    // Instance of the test list
    inline std::map<std::string, Test> Test::tests;
}

// UTT Internal use only.
#define __UTT_CONCAT(a, b) a##b
#define _UTT_CONCAT(a, b) __UTT_CONCAT(a, b)

/**
 * Create a unit test.
 * @param desc Description of the unit test.
 * @param test Test function. Can either return false or throw an exception. Can also be void in which case only exceptions will count as a fail.
*/
#define UT(desc, ...) static utt::Test _UTT_CONCAT(utt_user_test_, __LINE__) = utt::Test(__FILE__, __LINE__, desc, []() __VA_ARGS__);