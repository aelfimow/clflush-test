#include <string>
#include <chrono>
#include "scoped_chrono.h"
#include "scoped_chrono_priv.h"

scoped_chrono::scoped_chrono(const std::string &str) :
    m_priv { new scoped_chrono_priv(str) }
{
}

scoped_chrono::~scoped_chrono()
{
    delete m_priv;
}
