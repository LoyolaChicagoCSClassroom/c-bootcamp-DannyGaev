if(EXISTS "/Users/oaktree/Documents/GitHub/c-bootcamp-DannyGaev/std-queue/build/int_stack_tests[1]_tests.cmake")
  include("/Users/oaktree/Documents/GitHub/c-bootcamp-DannyGaev/std-queue/build/int_stack_tests[1]_tests.cmake")
else()
  add_test(int_stack_tests_NOT_BUILT int_stack_tests_NOT_BUILT)
endif()
