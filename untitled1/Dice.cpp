//
// Created by 86150 on 2023/3/24.
//
#include <iostream>
#include <cstdlib>
#include "Dice.h"
using namespace std;

int Dice::rollDice() {
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;
    int sum = die1 + die2;
    cout << "player rolled " << die1 << " + " << die2 << " = " << sum << endl;
    return sum;
}

void Dice::play(){
    GameStatus status = PLAYING;
    while (status == PLAYING) { //只要状态仍为PLAYING,就继续进 行下一轮
        int sum = rollDice(); //第一轮投骰子、计算和数
        switch (sum) {
            case 7:   //如果和数为7或11则为胜,状态为WIN
            case 11:
                status = WIN;
                break;
            case 2:   //和数为2、3或12则为负,状态为LOSE
            case 3:
            case 12:
                status = LOSE;
                break;
            default: /*其它情况,游戏尚无结果,状态为
					PLAYING,记下点数,为下一轮做准备 */
                status = PLAYING;
                break;
        }
    }
    //当状态不为PLAYING时上面的循环结束,以下程序段输出游戏结果
    if (status == WIN)
        cout << "player wins" << endl;
    else
        cout << "player loses" << endl;
}