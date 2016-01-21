/*インクルード***********************************************************/
#include "lpc13xx.h"
#include "gpio.h"
#include "vs-wrc103.h"
#include "ixbus.h"

/*マクロ***********************************************************/

#define G_LED LED(1)//緑
#define O_LED LED(2)//橙
#define GO_LED LED(3)//両方
#define OFF_LED LED(0)//消灯
#define mtsp 5000
//#define run Mtr_Run_lv(mtsp,-mtsp,0,0,0,0)

//前進む
//void forword(int d_time){
//    Mtr_Run_lv(mtsp,-mtsp,0,0,0,0);
//    Wait(d_time);
//}


void back(int d_time){
//    Mtr_Run_lv(-mtsp,mtsp,0,0,0,0);
    Mtr_Run_lv(mtsp,-mtsp,0,0,0,0);
    Wait(d_time);
}


void right(int d_time){
//    Mtr_Run_lv(mtsp,mtsp,0,0,0,0);
    Mtr_Run_lv(-mtsp,-mtsp,0,0,0,0);
	Wait(d_time);
}


void left(int d_time){
//    Mtr_Run_lv(-mtsp,-mtsp,0,0,0,0);
    Mtr_Run_lv(mtsp,mtsp,0,0,0,0);
    Wait(d_time);
}


//void stop(int d_time){
//    Mtr_Run_lv(0,0,0,0,0,0);
//    Wait(d_time);
//}

/*メイン関数***********************************************************/

int main (void)
{
    unsigned int LSensor,RSensor;

	//制御周期の設定[単位：Hz　範囲：30.0~]
	const unsigned short MainCycle = 60;
	Init(MainCycle);		//CPUの初期設定

	InitEncoder();	//エンコーダを初期化します。
	ClearEncoder();	//エンコーダの値をクリアします。

	  while (getSW()!=1);
	  while (getSW()==1);

      while(1){
        LSensor=ADRead(0);
        RSensor=ADRead(1);

/*黒紙***********************************************************/
//                if(LSensor >=500 && RSensor >=500){
//                	OFF_LED;
//                	Mtr_Run_lv(mtsp,-mtsp,0,0,0,0);
//                }else{
//                	if(LSensor <500 && RSensor <500){
//                		GO_LED;
//                		back(500);
//                		right(1000);
//                		Mtr_Run_lv(mtsp,-mtsp,0,0,0,0);
//                	}else if(LSensor <500){
//                		O_LED;
//                		back(500);
//                		right(800);
//                		Mtr_Run_lv(mtsp,-mtsp,0,0,0,0);
//                	}else {
//                		G_LED;
//                		back(500);
//                		left(800);
//                		Mtr_Run_lv(mtsp,-mtsp,0,0,0,0);
//                	}
//                }

/*白紙1***********************************************************/
//        if(LSensor <100 && RSensor <100){
//        	OFF_LED;
////        	Mtr_Run_lv(mtsp,-mtsp,0,0,0,0);
//        	Mtr_Run_lv(-mtsp,mtsp,0,0,0,0);
//        }else{
//        	if(LSensor >=100 && RSensor >=100 ){
//        		GO_LED;
//        		back(800);
//        		right(800);
////        		Mtr_Run_lv(mtsp,-mtsp,0,0,0,0);
//        	}else if(LSensor > 100 && RSensor <=100){
//        		O_LED;
//        		back(800);
//        		right(500);
////        		Mtr_Run_lv(mtsp,-mtsp,0,0,0,0);
//        	}else if(LSensor <= 100 && RSensor >100){
//        		G_LED;
//        		back(800);
//        		left(500);
////        		Mtr_Run_lv(mtsp,-mtsp,0,0,0,0);
//        	}else {
//        		Mtr_Run_lv(0,0,0,0,0,0);
//        	}
////        	Mtr_Run_lv(mtsp,-mtsp,0,0,0,0);
////        	Mtr_Run_lv(-mtsp,mtsp,0,0,0,0);
//        }

/*白紙***********************************************************/
        if(LSensor<80 && RSensor<80){
        	OFF_LED;
        	Mtr_Run_lv(-mtsp,mtsp,0,0,0,0);//
//        	Mtr_Run_lv(mtsp,-mtsp,0,0,0,0);//
        }else{
        	if(LSensor>=80){
        		if(RSensor>=80){
        			GO_LED;
        			back(500);
        			right(500);
        		}else{
        			O_LED;
        			back(500);
        			right(500);
        		}
        	}else{
        		G_LED;
        		back(500);
        		left(500);
        	}
        }

     }//while
}//main
