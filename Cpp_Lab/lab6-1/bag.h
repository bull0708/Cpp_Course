#ifndef BALL_H
#define BALL_H

class Ball
{
public:
    enum Colors {Red, White};

    bool isRed();
    Ball(Colors color);
private:
    Colors m_color;
};

#endif