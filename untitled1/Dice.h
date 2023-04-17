//
// Created by 86150 on 2023/3/24.
//

#ifndef UNTITLED1_DICE_H
#define UNTITLED1_DICE_H


class Dice{
    int seed;
public:
    Dice(int seed):seed(seed){
        srand(seed);//将种子传递给rand()
    };
    int rollDice();
    void play();
};
enum GameStatus { WIN, LOSE, PLAYING };


#endif //UNTITLED1_DICE_H
