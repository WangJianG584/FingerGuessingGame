#include<iostream>
#include<stdlib.h>
int main()
{

    std::cout << "请输入猜拳代码：1代表石头，2代表剪刀，3代表布"<<std::endl;
    unsigned short PlayerInput,RobotInput; //创建玩家和电脑的猜拳输入变量
    std::string PlayerChoosesDisplay,RobotChoosesDisplay;//创建显示输入变量的中文
    bool OutlierDetection;
    do 
    {   OutlierDetection = false; //默认不循环，但是有例外情况
    
        std::cin >> PlayerInput;
        switch(PlayerInput)//我认为一大段话里面有少许的改动，为此写大部分相同的三句话，我感觉不值
        {
            case 1 :PlayerChoosesDisplay ="石头" ;break;
            case 2 :PlayerChoosesDisplay ="剪刀";break;
            case 3 :PlayerChoosesDisplay ="布";break;
            default:std::cout<<"输入非法,请重新输入";OutlierDetection = true;break;//当遇到异常值时，出现例外，开始让用户重新输入
        }
    } while (OutlierDetection);

    srand((unsigned)time(NULL));//电脑开始猜拳
    RobotInput = rand() % 3 + 1;
    
    unsigned short PlayersSwapFlag; //创建变量用于决定是否交换猜拳决定
    std::cout<<"玩家方选择"<<PlayerChoosesDisplay<<"，\n"<<"能选择和电脑方交换出拳，\n"<<"0代表保持原样，1代表交换出拳"<<std::endl;
    
    
    std::cin >> PlayersSwapFlag;

    if (PlayersSwapFlag == 1)
    {
      
        unsigned short GMSwap;//临时交换变量
        GMSwap = PlayerInput;
        PlayerInput = RobotInput;
        RobotInput = GMSwap;
        std::cout<<"交换成功"<<std::endl;    
    }

    else
    {
        std::cout<<"用户选择不交换自己的决定"<<std::endl;
    }

    switch(PlayerInput)
    {
        case 1 :PlayerChoosesDisplay ="石头" ;break; //刷新显示实时的猜拳状况
        case 2 :PlayerChoosesDisplay ="剪刀";break;
        case 3 :PlayerChoosesDisplay ="布";break;
            
    }

    switch(RobotInput)
    {
        case 1 :RobotChoosesDisplay ="石头" ;break;
        case 2 :RobotChoosesDisplay ="剪刀";break;
        case 3 :RobotChoosesDisplay ="布";break;
            
    }    
    std::cout<<"玩家选择出"<<PlayerChoosesDisplay<<"，电脑选择出"<<RobotChoosesDisplay<<std::endl;
    short VictoryDecision = PlayerInput -RobotInput;//决定胜负的运算
    switch (VictoryDecision)
    {
    case 2: std::cout<<"玩家胜"<<std::endl;return 0;break;
    case -1: std::cout<<"玩家胜"<<std::endl;return 0;break;
    case 1: std::cout<<"电脑胜"<<std::endl;return 0;break;
    case -2: std::cout<<"电脑胜"<<std::endl;return 0;break;
    case 0: std::cout<<"玩家和电脑平局"<<std::endl;return 0;break;
    default:std::cout<<"程序判断出现问题，请联系开发者"<<std::endl;return 555;break;
    
    }

}