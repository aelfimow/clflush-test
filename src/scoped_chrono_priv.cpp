#include <iostream>
#include <string>
#include <chrono>
#include "scoped_chrono_priv.h"

using namespace std::chrono;

scoped_chrono_priv::scoped_chrono_priv(const std::string &str) :
    m_message { str },
    m_now { high_resolution_clock::now() }
{
}

scoped_chrono_priv::~scoped_chrono_priv()
{
    const auto t2 = high_resolution_clock::now();

    const auto t_diff = duration_cast<milliseconds>(t2 - m_now).count();

    std::cout << m_message << t_diff << " milliseconds" << std::endl;
}
