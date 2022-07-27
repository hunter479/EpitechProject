/*
** EPITECH PROJECT, 2019
** ex01
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
	#define CHARACTER_HPP_

#include <iostream>
#include <string>

class Character {
	public:
		Character(const std::string &name, const int &);
		virtual ~Character();
        const std::string &getName() const {return (Name);};
        const std::string &getClass() const {return (Class);};
        const std::string &getRace() const {return (Race);};
        const int &getLvl() const {return (Lvl);};
        const int &getPv() const {return (Pv);};
        const int &getPower() const {return (Power);};
        const int &getStrenght() const {return (Strenght);};
        const int &getStamina() const {return (Stamina);};
        const int &getIntelligence() const {return (Intelligence);};
        const int &getSpirit() const {return (Spirit);};
        const int &getAgility() const {return (Agility);};
        typedef enum {
            CLOSE,
            RANGE
        } AttackRange;
        AttackRange Range;
        const AttackRange &getRange() const {return (Range);};
        void TakeDamage(const int &);
        virtual int CloseAttack();
        virtual int RangeAttack();
        virtual void Heal();
        virtual void RestorePower();
        virtual int Intercept() {return (0);};
    protected:
        void setName(const std::string &value) {Name = value;};
        void setRange(const AttackRange &value) {Range = value;};
        void setRace(const std::string &value) {Race = value;};
        void setClass(const std::string &value) {Class = value;};
        void setLvl(const int &value) {Lvl = value;};
        void setPv(const int &value) {Pv = value;};
        void setPower(const int &value) {Power = value;};
        void setStrenght(const int &value) {Strenght = value;};
        void setStamina(const int &value) {Stamina = value;};
        void setIntelligence(const int &value) {Intelligence = value;};
        void setSpirit(const int &value) {Spirit = value;};
        void setAgility(const int &value) {Agility = value;};
    protected:
        std::string Name;
        int Lvl;
        std::string Class;
        std::string Race;
        int Pv;
        int Power;
        int Strenght;
        int Stamina;
        int Intelligence;
        int Spirit;
        int Agility;
};

#endif /* !CHARACTER_HPP_ */
