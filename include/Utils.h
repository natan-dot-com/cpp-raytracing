#pragma once

#include <type_traits>

// Numeric generic type
template<typename T>
concept Numeric = std::is_arithmetic<T>::value;