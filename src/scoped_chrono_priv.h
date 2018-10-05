#ifdef SCOPED_CHRONO_PRIV_H
#error Already included
#else
#define SCOPED_CHRONO_PRIV_H

class scoped_chrono_priv
{
    public:
        explicit scoped_chrono_priv(const std::string &str);
        ~scoped_chrono_priv();

    private:
        const std::string m_message;
        const std::chrono::high_resolution_clock::time_point m_now;

    public:
        scoped_chrono_priv() = delete;
        scoped_chrono_priv(const scoped_chrono_priv &instance) = delete;
        scoped_chrono_priv(const scoped_chrono_priv &&instance) = delete;
        scoped_chrono_priv &operator=(const scoped_chrono_priv &instance) = delete;
        scoped_chrono_priv &operator=(const scoped_chrono_priv &&instance) = delete;
};

#endif
