/*
** EPITECH PROJECT, 2019
** cpp_d07a_2018
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
	#define KREOGCOM_HPP_

class  KreogCom {
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom();
        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom();
        void ping() const;
        void locateSquad() const;
    private:
        int _x;
        int _y;
        const  int  m_serial;
        KreogCom *_next;
};
#endif /* !KREOGCOM_HPP_ */
