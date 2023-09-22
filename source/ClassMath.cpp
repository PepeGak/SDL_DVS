#include "ClassMath.hpp"

float ClassMath::Calculate_A(Sint32 N, float T)
{
    float A = 2 * M_PI * N * T;
    return A;
}

float ClassMath::Calculate_Q(Sint32 N, float R, float Q_b)
{
    float Q = R * Q_b * N;
    return Q;
}

float ClassMath::Calculate_W(float p_me, float V_d)
{
    float W = p_me * V_d;
    return W;
}

float ClassMath::Calculate_P(float W, Sint32 N, Sint32 n_c)
{
    float P = W * N / n_c;
    return P;
}

float ClassMath::Calculate_T(float V_d, float p_me)
{
    float T = V_d * p_me / 0.0126;
    return T;
}
