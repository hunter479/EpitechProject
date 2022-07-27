/*
** EPITECH PROJECT, 2019
** ex01
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
    #define DROIDMEMORY_HPP_

#include <string>

class DroidMemory {
    public:
        DroidMemory();
        DroidMemory(const DroidMemory &);
        ~DroidMemory();
        const size_t &getFingerPrint() const;
        const size_t &getExp() const;
        DroidMemory *getBattleData() const;
        void setFingerPrint(const size_t &);
        void setExp(const size_t &);
        void setBattleData(const DroidMemory *);
        void operator<<(const DroidMemory &);
        void operator>>(DroidMemory &);
        void operator+=(const DroidMemory &);
        void operator+=(const size_t &);
        DroidMemory &operator+(const size_t &);
        DroidMemory &operator+(const DroidMemory &);
    private:
        size_t _FingerPrint;
        size_t _Exp;
        DroidMemory *_BattleData;
};
std::ostream &operator<<(std::ostream &, const DroidMemory &);

#endif /* !DROIDMEMORY_HPP_ */
