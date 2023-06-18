#pragma once

template <typename T>
concept Numeric = std::is_arithmetic<T>::value;

