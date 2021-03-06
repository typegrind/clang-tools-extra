// RUN: %check_clang_tidy %s modernize-pass-by-value %t -- -- -std=c++11 -isystem %S/Inputs/Headers

// CHECK-FIXES: #include <utility>

#define HEADER <./a.h>
#include HEADER

struct A {
};

struct B {
  B(const A &a) : a(a) {}
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: pass by value and use std::move [modernize-pass-by-value]
// CHECK-FIXES: B(A a) : a(std::move(a)) {}
  A a;
};
