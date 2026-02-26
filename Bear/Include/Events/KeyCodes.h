#pragma once



#include <cstdint>
enum class KeyCode : uint16_t
{

    Unknown = 0,

    // Letters
    A, B, C, D, E, F, G,
    H, I, J, K, L, M, N,
    O, P, Q, R, S, T, U,
    V, W, X, Y, Z,

    // Numbers
    Num0, Num1, Num2, Num3, Num4,
    Num5, Num6, Num7, Num8, Num9,

    // Special
    Space,
    Enter,
    Escape,
    Left,
    Right,
    Up,
    Down,
};
