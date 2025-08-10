#include <stdio.h>
#include <string.h>

typedef int (*test_func)(void);
typedef struct {
    const char *name;
    test_func func;
} test_case;

int run_tests(test_case *tests, int num_tests);

static const char *current_test_name = NULL;
#define ASSERT(cond)                                                           \
    do {                                                                       \
        if (!(cond)) {                                                         \
            fprintf(stderr, "[FAIL] %s => %s at %s:%d \n", current_test_name,  \
                    #cond, __FILE__, __LINE__);                                \
            exit(1);                                                           \
        }                                                                      \
    } while (0)

#define RUN_TESTS(tests) run_tests(tests, sizeof(tests) / sizeof(tests[0]))
inline int run_tests(test_case *tests, int num_tests) {
    int passed = 0;

    printf("Running %d tests...\n", num_tests);
    for (int i = 0; i < num_tests; i++) {
        current_test_name = tests[i].name;
        if (tests[i].func() == 0) {
            printf("[PASS] %s\n", current_test_name);
            passed++;
        } else {
            break;
        }
    }

    printf("%d/%d tests passed.\n", passed, num_tests);
    return (passed == num_tests) ? 0 : 1;
}