#ifdef SCOPED_CHRONO_H
#error Already included
#else
#define SCOPED_CHRONO_H

class scoped_chrono_priv;

class scoped_chrono
{
    public:
        explicit scoped_chrono(const std::string &str);

        scoped_chrono() = delete;
        scoped_chrono(const scoped_chrono &instance) = delete;
        scoped_chrono(const scoped_chrono &&instance) = delete;
        scoped_chrono &operator=(const scoped_chrono &instance) = delete;
        scoped_chrono &operator=(const scoped_chrono &&instance) = delete;

        ~scoped_chrono();

    private:
        scoped_chrono_priv * const m_priv;
};

#endif
