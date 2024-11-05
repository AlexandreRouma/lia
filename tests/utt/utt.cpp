#include "utt.h"
#include <stdio.h>
#include <algorithm>

int main() {
    // Go through each test
    for (auto& [id, test] : utt::Test::tests) {
        // Display the description of the test
        printf("%s: ", test.desc.c_str());

        // Attempt to run the test
        try {
            // Run the test
            test.test();

            // Show success
            printf("PASS\n");
        }
        catch (const std::exception& e) {
            // Display "FAIL" and optionally an error message if one was given
            if (strlen(e.what())) {
                printf("FAIL -> %s\n", e.what());
            }
            else {
                printf("FAIL\n");
            }

            // Display where the failed test is located and exit
            printf("Failed test is located at %s\n", id.c_str());
            return -1;
        }
    }

    // Display a success message and exit
    printf("All tests have passed successfully!\n");
    return 0;
}